/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:52:59 by mbendidi          #+#    #+#             */
/*   Updated: 2024/12/29 17:06:26 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	push_chunk_to_b(t_stack *a, t_stack *b, t_chunk ck)
{
	int	chunk_len;
	int	count_pushed;
	int	pos;

	chunk_len = ck.end - ck.start + 1;
	count_pushed = 0;
	while (count_pushed < chunk_len)
	{
		pos = find_position_in_stack(a, ck.start, ck.end);
		if (pos == -1)
			break ;
		ft_move_top(a, pos);
		ft_pb(a, b);
		count_pushed++;
	}
}

int	ft_is_sorted(t_stack *stack)
{
	t_node	*cur;

	cur = stack->top;
	while (cur && cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}

void	ft_sort(t_stack *a, t_stack *b)
{
	if (a->size <= 1 || ft_is_sorted(a))
		return ;
	if (a->size == 2)
	{
		if (a->top->value > a->top->next->value)
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
		index_values(a);
		sort_chunks(a, b);
	}
}
