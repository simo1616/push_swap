/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:22:29 by mbendidi          #+#    #+#             */
/*   Updated: 2024/12/29 18:43:08 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_bottom(t_stack *a, int nb)
{
	t_node	*new_node;
	t_node	*tmp;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
	{
		write(2, "ERROR\n", 7);
		exit(1);
	}
	new_node->value = nb;
	new_node->next = NULL;
	if (!a->top)
	{
		a->top = new_node;
		a->size++;
		return ;
	}
	tmp = a->top;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
	a->size++;
}

int	check_and_push(char **av, t_stack *a)
{
	int	i;
	int	nb;

	i = 1;
	nb = 0;
	while (av[i])
	{
		if (!valid_number(av[i]))
		{
			write(2, "ERROR\n", 7);
			free_stack(a);
			return (0);
		}
		nb = ft_atoll(av[i]);
		if (!check_atoll(av[i], &nb) || has_duplicate(a, nb))
		{
			write(2, "ERROR\n", 7);
			free_stack(a);
			return (0);
		}
		push_bottom(a, nb);
		i++;
	}
	return (1);
}
