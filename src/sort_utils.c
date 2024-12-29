/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:43:57 by mbendidi          #+#    #+#             */
/*   Updated: 2024/12/29 16:45:29 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_position_of_min(t_stack *stack)
{
	t_node	*cur;
	int		pos;
	int		pos_min;
	int		current_min;

	cur = stack->top;
	pos = 0;
	pos_min = 0;
	current_min = cur->index;
	while (cur)
	{
		if (cur->index < current_min)
		{
			current_min = cur->index;
			pos_min = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (pos_min);
}

int	ft_position_of_max(t_stack *stack)
{
	t_node	*cur;
	int		pos;
	int		pos_max;
	int		current_max;

	cur = stack->top;
	pos = 0;
	pos_max = 0;
	current_max = cur->index;
	while (cur)
	{
		if (cur->index > current_max)
		{
			current_max = cur->index;
			pos_max = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (pos_max);
}

int	position_of_min_by_value(t_stack *a)
{
	t_node	*cur;
	int		pos;
	int		pos_min;
	int		min_val;

	cur = a->top;
	pos = 0;
	pos_min = 0;
	min_val = cur->value;
	while (cur)
	{
		if (cur->value < min_val)
		{
			min_val = cur->value;
			pos_min = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (pos_min);
}

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
