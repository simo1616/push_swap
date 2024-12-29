/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:45:37 by mbendidi          #+#    #+#             */
/*   Updated: 2024/12/29 18:45:45 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	top = a->top->value;
	mid = a->top->next->value;
	bot = a->top->next->next->value;
	if (top > mid && mid < bot && bot > top)
		ft_sa(a);
	else if (top > mid && mid > bot && bot < top)
	{
		ft_sa(a);
		ft_rra(a);
	}
	else if (top > mid && mid < bot && bot < top)
		ft_ra(a);
	else if (top < mid && mid > bot && bot > top)
	{
		ft_sa(a);
		ft_ra(a);
	}
	else if (top < mid && mid > bot && bot < top)
		ft_rra(a);
}

void	ft_sort_four(t_stack *a, t_stack *b)
{
	int	min_pos;

	if (ft_is_sorted(a))
		return ;
	min_pos = position_of_min_by_value(a);
	if (min_pos == 1)
		ft_ra(a);
	else if (min_pos == 2)
	{
		ft_ra(a);
		ft_ra(a);
	}
	else if (min_pos == 3)
		ft_rra(a);
	ft_pb(a, b);
	ft_sort_three(a);
	ft_pa(a, b);
}

void	ft_sort_five(t_stack *a, t_stack *b)
{
	int	min_pos;

	if (ft_is_sorted(a))
		return ;
	min_pos = position_of_min_by_value(a);
	ft_move_top(a, min_pos);
	ft_pb(a, b);
	min_pos = position_of_min_by_value(a);
	ft_move_top(a, min_pos);
	ft_pb(a, b);
	ft_sort_three(a);
	ft_pa(a, b);
	ft_pa(a, b);
}
