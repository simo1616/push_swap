/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:29:53 by mbendidi          #+#    #+#             */
/*   Updated: 2024/12/26 18:07:38 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void bring_back_to_a(t_stack *a, t_stack *b)
{
    while (b->size > 0)
    {
        int max_pos = ft_position_of_max(b); // Trouver l'index du maximum
        ft_move_top(b, max_pos);            // Déplacer le maximum en haut
        ft_pa(a, b);                        // Rapatrier dans a
    }
}

void bring_back_all_in_order(t_stack *a, t_stack *b)
{
    while (b->size > 0)
    {
        int max_pos = ft_position_of_max(b); // Trouver l'index du maximum dans B
        ft_move_top(b, max_pos);            // Amener le maximum au sommet de B
        ft_pa(a, b);                        // Pousser le maximum dans A
    }
}

void push_chunk_to_b(t_stack *a, t_stack *b, int start, int end)
{
    int count_pushed = 0; 
    int chunk_size = end - start + 1;

    // Continuer jusqu’à ce que tout le chunk soit poussé dans B
    while (count_pushed < chunk_size)
    {
        int index = a->top->index; // Lire l’index de l’élément au sommet de A

        if (index >= start && index <= end)
        {
            ft_pb(a, b); // Si l’élément est dans le chunk, on pousse dans B
            count_pushed++;
        }
        else
        {
            ft_ra(a); // Sinon, on fait défiler pour passer à l’élément suivant
        }
    }
}

int get_chunk_size(int size)
{
    if (size <= 100)
        return size / 5; // Diviser en 5 chunks pour 100 éléments
    else
        return size / 11; // Diviser en 11 chunks pour 500 éléments
}

void sort_chunks(t_stack *a, t_stack *b)
{
    int chunk_size = get_chunk_size(a->size); // Calcul de la taille d’un chunk
    int start = 0;
    int end = chunk_size - 1;

    // Pousser tous les chunks dans B
    while (start < a->size)
    {
        push_chunk_to_b(a, b, start, end);
        start = end + 1;
        end += chunk_size;
        if (end >= a->size) // Ajuster pour le dernier chunk
            end = a->size - 1;
    }

    // Rapatrier tout depuis B vers A
    bring_back_all_in_order(a, b);
}


void ft_sort_five(t_stack *a, t_stack *b)
{
    int min_pos;

	if (ft_is_sorted(a))
        return;
    // ============ 1er plus petit =============
    min_pos = ft_position_of_min(a); 
    ft_move_top(a, min_pos); // via ra/rra, comme pour 4 éléments
    ft_pb(a, b);             // On envoie ce plus petit dans B
    // ============ 2e plus petit =============
    min_pos = ft_position_of_min(a); 
    ft_move_top(a, min_pos);
    ft_pb(a, b);
    // ============ Trier les 3 restants dans A
    ft_sort_three(a);
    // ============ Remonter dans le bon ordre
    // B contient 2 éléments (le plus petit est en bas ou en haut, à voir)
    // Option 1 : pa, puis pa, et si besoin on corrige l'ordre (un sa/sb éventuel)
    ft_pa(a, b);
    ft_pa(a, b);
    // - regarder si l'élément qui remonte doit être placé en haut ou
    //   s’il faut faire un ra pour bien l'insérer. 
    // Mais pour 5 éléments, ce n’est pas très coûteux de faire quelques instructions de plus.
}


void ft_sort_four(t_stack *a, t_stack *b)
{
    int min_pos;
	
	if (ft_is_sorted(a))
        return;
	min_pos = ft_position_of_min(a);
    if (min_pos == 1)
        ft_ra(a);
    else if (min_pos == 2)
    {
        ft_ra(a);
        ft_ra(a);
    }
    else if (min_pos == 3)
        ft_rra(a);
    ft_pb(a, b);
    ft_sort_three(a);
    ft_pa(a, b);
}

void	ft_sort_three(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	top = a->top->value;
	mid = a->top->next->value;
	bot = a->top->next->next->value;
	if (top > mid && mid < bot && bot > top)
		ft_sa(a);
	else if (top > mid && mid > bot && bot < top)
	{
		ft_sa(a);
		ft_rra(a);
	}
	else if (top > mid && mid < bot && bot < top)
		ft_ra(a);
	else if (top < mid && mid > bot && bot > top)
	{
		ft_sa(a);
		ft_ra(a);
	}
	else if (top < mid && mid > bot && bot < top)
		ft_rra(a);
}

void	ft_sort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if(a->top->value > a->top->next->value)
			ft_sa(a);
	}
	else if (a->size == 3)
		ft_sort_three(a);
	else if (a->size == 4)
		ft_sort_four(a, b);
	else if (a->size == 5)
		ft_sort_five(a, b);
	else
	{
        index_values(a); // Générer les indices
        sort_chunks(a, b); // Utiliser le tri par chunks
    }
}

