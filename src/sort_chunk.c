/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:26:56 by mbendidi          #+#    #+#             */
/*   Updated: 2024/12/28 22:44:27 by mbendidi         ###   ########.fr       */
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

int	get_chunk_size(int size)
{
	if (size <= 100)
		return (size / 5);
	else
		return (size / 11);
}

void	process_chunk(t_stack *a, t_stack *b, int i, int chunk_size, int size_init)
{
	int	start;
	int	end;

	start = i * chunk_size;
	end = (i + 1) * chunk_size - 1;
	if (end >= size_init)
		end = size_init - 1;
	push_chunk_to_b(a, b, start, end, size_init);
}

void	sort_chunks(t_stack *a, t_stack *b)
{
	int	size_init;
	int	nb_chunks;
	int	chunk_size;
	int	i;

	if (ft_is_sorted(a))
		return ;
	size_init = a->size;
	if (size_init <= 100)
    	nb_chunks = 5;
	else
    	nb_chunks = 11;

	chunk_size = (size_init / nb_chunks);
	if (size_init % nb_chunks != 0)
		chunk_size++;
	index_values(a);
	i = 0;
	while (i < nb_chunks)
	{
		process_chunk(a, b, i, chunk_size, size_init);
		i++;
	}
	bring_back_all_in_order(a, b);
}
