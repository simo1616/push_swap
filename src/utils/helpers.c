/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:57:14 by mbendidi          #+#    #+#             */
/*   Updated: 2025/01/02 18:51:54 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	find_position_in_stack(t_stack *stack, int start, int end)
{
	t_node	*cur;
	int		pos;

	cur = stack->top;
	pos = 0;
	while (cur)
	{
		if (cur->index >= start && cur->index <= end)
			return (pos);
		cur = cur->next;
		pos++;
	}
	return (-1);
}
