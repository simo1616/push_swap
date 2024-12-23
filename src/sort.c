/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:29:53 by mbendidi          #+#    #+#             */
/*   Updated: 2024/12/23 18:20:54 by mbendidi         ###   ########.fr       */
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

void	ft_sort(t_stack *a, t_stack *b)
{
	(void)b;
	if (a->size == 2)
	{
		ft_sa(a);
		return ;
	}
	if (a->size == 3)
	{
		ft_sort_three(a);
		return ;
	}
}
