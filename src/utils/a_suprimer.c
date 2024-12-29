/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_suprimer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:38:06 by mbendidi          #+#    #+#             */
/*   Updated: 2024/12/28 22:38:19 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node	*tmp;

	if (!stack || !stack->top)
	{
		ft_printf("\033[31mLa pile est vide ou invalide.\033[0m\n");
		return ;
	}
	tmp = stack->top;
	while (tmp)
	{
		ft_printf("%d\t", tmp->value);
		tmp = tmp->next;
	}
	ft_printf("\n");
}
