/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:22:29 by mbendidi          #+#    #+#             */
/*   Updated: 2024/12/23 18:21:57 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *a)
{
	t_node *current;
	t_node	*next;

	if (!a)
		return;
	
	current = a->top;
	while(current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	a->top = NULL;
	a->size = 0;
}

//pour tester le bon deroulement de push a
void	print_stack(t_stack *a)
{
	t_node *tmp;
	tmp = a->top;
	if(!tmp)
	{
		write(2, "\033[31m ERROR PRINT_STACK \033[0m\n", 30);
		exit(1);
	}
	while(tmp)
	{
		ft_printf("%d\t", tmp->value);
		tmp = tmp->next;
	}
	write(1, "\n", 1);
}

void	push_top(t_stack *a, int nb)
{
	t_node *new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if(!new_node)
	{
		write(2, "\033[31m ERROR D'ALLOCATION \033[0m\n", 30);
		exit(1);
	}
	new_node->value = nb;
	new_node->next = a->top;   // Le nouveau node pointe vers l'ancien sommet
	a->top = new_node;         // Le nouveau node devient le sommet
    a->size++;                 // Incrémenter la taille de la pile
	//free(new_node);
}

int	has_duplicate(t_stack *a, int nb)
{
	t_node *tmp = a->top;
	
	while(tmp)
	{
		if (nb == tmp->value)
			return(1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_is_digit(char c)
{
	return(c >= '0' && c <= '9');
}

int	ft_is_sign(char c)
{
	return(c == '+' || c == '-');
}

int	valid_number(char *str)
{
	int	i;

	i = 0;
	// verifier si pas vide
	if(!str || !str[i])
		return (0);
	// verifier si + ou -
	if(ft_is_sign(str[i]))
		i++;
	if(!str[i])
		return (0);
	while(str[i])
	{
		if(!ft_is_digit(str[i]))
			return(0);
		i++;
	}
	
	return(1);
}

void	init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->size = 0;
}

int	check_and_push(char **av, t_stack *a)
{
	int		i;
	int		nb;

	i = 1;
	nb = 0;
	while(av[i])
	{
		if(!valid_number(av[i]))
		{
			ft_printf("erreur arg -Non valide- pour le %deme argument \n", i);
			free_stack(a);
			return(0);
		}
		nb = ft_atoll(av[i]);
		if (!check_atoll(av[i], &nb))
		{
			ft_printf("erreur arg -Out of range- pour le %deme argument\n", i);
			free_stack(a);
			return(0);
		}
		if (has_duplicate(a, nb))
		{
			ft_printf("erreur arg -Duplicated- pour le %deme argument \n", i);
			free_stack(a);
			return(0);
		}
		push_top(a, nb);
		i++;
	}
	return(1);
}

int main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	
	
	if(ac < 2)
	{
		write(2, "\033[31m ERROR \033[0m\n", 18);
		return(1);
	}
	init_stack(&a);
	init_stack(&b);
	if (!check_and_push(av, &a))
		return(1);
	print_stack(&a);
	//ft_printf("compte : %d\n", i - 1);
	ft_sort(&a, &b);
	print_stack(&a);
	return(0);
}