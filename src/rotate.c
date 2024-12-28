/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 23:18:18 by mbendidi          #+#    #+#             */
/*   Updated: 2024/12/28 19:11:08 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *a)
{
	t_node	*tmp;
	t_node	*cur;

	if (!a || a->size < 2)
		return ;
	tmp = a->top;
	a->top = a->top->next;
	cur = a->top;
	while (cur->next)
		cur = cur->next;
	cur->next = tmp;
	tmp->next = NULL;
	ft_printf("ra\n");
}

void	ft_rb(t_stack *b)
{
	t_node	*tmp;
	t_node	*cur;

	if (!b || b->size < 2)
		return ;
	tmp = b->top;
	b->top = b->top->next;
	cur = b->top;
	while (cur->next)
		cur = cur->next;
	cur->next = tmp;
	tmp->next = NULL;
	ft_printf("rb\n");
}

static void	rotate_stack(t_stack *s)
{
	t_node	*tmp;
	t_node	*cur;

	if (!s || s->size < 2)
		return ;
	tmp = s->top;
	s->top = s->top->next;
	cur = s->top;
	while (cur->next)
		cur = cur->next;
	cur->next = tmp;
	tmp->next = NULL;
}

void	ft_rr(t_stack *a, t_stack *b)
{
	rotate_stack(a);
	rotate_stack(b);
	ft_printf("rr\n");
}
