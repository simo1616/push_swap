/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:29:24 by mbendidi          #+#    #+#             */
/*   Updated: 2024/12/28 19:03:15 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return (0);
	if (ft_is_sign(str[i]))
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_is_digit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicate(t_stack *a, int nb)
{
	t_node	*tmp;

	tmp = a->top;
	while (tmp)
	{
		if (nb == tmp->value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
