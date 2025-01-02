/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:50:00 by mbendidi          #+#    #+#             */
/*   Updated: 2025/01/02 18:53:42 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bring_back_to_a(t_stack *a, t_stack *b)
{
	int	min_pos;

	while (b->size > 0)
	{
		min_pos = ft_position_of_min(b);
		ft_move_top(b, min_pos);
		ft_pa(a, b);
	}
}

int	find_pos_in_stk_from_bot(t_stack *stack, int start, int end)
{
	t_node	*cur;
	int		pos;
	int		stack_size;

	cur = stack->top;
	pos = 0;
	stack_size = stack->size;
	while (cur)
	{
		if (cur->index >= start && cur->index <= end)
			return (stack_size - pos);
		cur = cur->next;
		pos++;
	}
	return (-1);
}