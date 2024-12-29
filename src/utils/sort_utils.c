/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:43:57 by mbendidi          #+#    #+#             */
/*   Updated: 2024/12/29 18:59:20 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_values(t_stack *a)
{
	t_node	*current;
	t_node	*compare;
	int		index;

	current = a->top;
	while (current)
	{
		index = 0;
		compare = a->top;
		while (compare)
		{
			if (compare->value < current->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

void	ft_move_top(t_stack *stack, int index)
{
	if (index <= stack->size / 2)
	{
		while (index > 0)
		{
			if (stack->id == 'A')
				ft_ra(stack);
			else if (stack->id == 'B')
				ft_rb(stack);
			index--;
		}
	}
	else
	{
		while (index < stack->size)
		{
			if (stack->id == 'A')
				ft_rra(stack);
			else if (stack->id == 'B')
				ft_rrb(stack);
			index++;
		}
	}
}
