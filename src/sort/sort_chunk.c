/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:50:00 by mbendidi          #+#    #+#             */
/*   Updated: 2024/12/29 19:29:52 by mbendidi         ###   ########.fr       */
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

int	get_chunk_size(int size)
{
	if (size <= 100)
		return (size / 5);
	else
		return (size / 11);
}
