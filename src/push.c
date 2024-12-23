/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 22:39:49 by mbendidi          #+#    #+#             */
/*   Updated: 2024/12/23 22:00:14 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (!b || b->size < 1)
		return ;
	tmp = b->top;
	b->top = b->top->next;
	b->size--;
	tmp->next = a->top;
	a->top = tmp;
	a->size++;
	ft_printf("pa\n");
}

void	ft_pb(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (!a || a->size < 1)
		return ;
	tmp = a->top;
	a->top = a->top->next;
	a->size--;
	tmp->next = b->top;
	b->top = tmp;
	b->size++;
	ft_printf("pb\n");
}
