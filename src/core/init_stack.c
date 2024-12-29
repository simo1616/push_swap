/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:41:52 by mbendidi          #+#    #+#             */
/*   Updated: 2024/12/29 18:42:47 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack, char id)
{
	stack->top = NULL;
	stack->size = 0;
	stack->id = id;
}

void	free_stack(t_stack *a)
{
	t_node	*current;
	t_node	*next;

	if (!a)
		return ;
	current = a->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	a->top = NULL;
	a->size = 0;
}
