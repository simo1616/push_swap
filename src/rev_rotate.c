/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 23:46:26 by mbendidi          #+#    #+#             */
/*   Updated: 2024/12/25 15:47:53 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack *a)
{
	t_node	*cur;
	t_node	*prev;

	if (a->size < 2)
		return ;
	cur = a->top;
	prev = NULL;
	while (cur->next)
	{
		prev = cur;
		cur = cur->next;
	}
	prev->next = NULL;
	cur->next = a->top;
	a->top = cur;
	ft_printf("rra\n");
}

void	ft_rrb(t_stack *b)
{
	t_node	*cur;
	t_node	*prev;

	if (b->size < 2)
		return ;
	cur = b->top;
	prev = NULL;
	while (cur->next)
	{
		prev = cur;
		cur = cur->next;
	}
	prev->next = NULL;
	cur->next = b->top;
	b->top = cur;
	ft_printf("rrb\n");
}
static void	ft_rotate_rev(t_stack *s)
{
	t_node	*cur;
	t_node	*prev;

	if (s->size < 2)
		return ;
	cur = s->top;
	prev = NULL;
	while (cur->next)
	{
		prev = cur;
		cur = cur->next;
	}
	prev->next = NULL;
	cur->next = s->top;
	s->top = cur;
}
void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_rotate_rev(a);
	ft_rotate_rev(b);
	ft_printf("rrr\n");
}
