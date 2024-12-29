/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:54:59 by mbendidi          #+#    #+#             */
/*   Updated: 2024/12/29 19:05:21 by mbendidi         ###   ########.fr       */
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

int	check_atoll(const char *str, int *out)
{
	long long	val;

	val = ft_atoll(str);
	if (val > INT_MAX || val < INT_MIN)
		return (0);
	*out = (int)val;
	return (1);
}
