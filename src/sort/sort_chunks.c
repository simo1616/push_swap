/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:47:31 by mbendidi          #+#    #+#             */
/*   Updated: 2024/12/29 18:54:13 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	process_chunk(t_stack *a, t_stack *b, t_args arg)
{
	t_chunk	ck;

	ck.start = arg.i * arg.chunk_size;
	ck.end = (arg.i + 1) * arg.chunk_size - 1;
	if (ck.end >= arg.size_init)
		ck.end = arg.size_init - 1;
	ck.size_init = arg.size_init;
	push_chunk_to_b(a, b, ck);
}

void	sort_chunks(t_stack *a, t_stack *b)
{
	int		size_init;
	int		nb_chunks;
	int		chunk_size;
	int		i;
	t_args	arg;

	if (ft_is_sorted(a))
		return ;
	size_init = a->size;
	if (size_init <= 100)
		nb_chunks = 5;
	else
		nb_chunks = 11;
	chunk_size = size_init / nb_chunks;
	if (size_init % nb_chunks != 0)
		chunk_size++;
	i = 0;
	while (i < nb_chunks)
	{
		arg.i = i++;
		arg.chunk_size = chunk_size;
		arg.size_init = size_init;
		process_chunk(a, b, arg);
	}
	bring_back_all_in_order(a, b);
}

void	bring_back_all_in_order(t_stack *a, t_stack *b)
{
	int	max_pos;

	while (b->size > 0)
	{
		max_pos = ft_position_of_max(b);
		ft_move_top(b, max_pos);
		ft_pa(a, b);
	}
}
