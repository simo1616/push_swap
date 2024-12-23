/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:29:53 by mbendidi          #+#    #+#             */
/*   Updated: 2024/12/23 22:30:31 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		return ;
	}
	if (a->size == 3)
	{
		ft_sort_three(a);
		return ;
	}
	if (a->size == 4)
	{
		ft_sort_four(a, b);
		return ;
	}
	if (a->size == 5)
	{
		ft_sort_five(a, b);
		return ;
	}
	
	
}
