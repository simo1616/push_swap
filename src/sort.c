/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:52:59 by mbendidi          #+#    #+#             */
/*   Updated: 2024/12/28 22:54:02 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunk_to_b(t_stack *a, t_stack *b, t_chunk ck)
{
	int	chunk_len;
	int	count_pushed;
	int	idx;

	chunk_len = ck.end - ck.start + 1;
	if (chunk_len > ck.size_init - ck.start)
		chunk_len = ck.size_init - ck.start;
	count_pushed = 0;
	while (count_pushed < chunk_len)
	{
		idx = a->top->index;
		if (idx >= ck.start && idx <= ck.end)
		{
			ft_pb(a, b);
			count_pushed++;
		}
		else
			ft_ra(a);
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
