/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:32:16 by mbendidi          #+#    #+#             */
/*   Updated: 2024/12/29 18:34:15 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac <= 1)
		return (0);
	init_stack(&a, 'A');
	init_stack(&b, 'B');
	if (!check_and_push(av, &a))
		return (1);
	if (a.size <= 1 || ft_is_sorted(&a))
	{
		free_stack(&a);
		free_stack(&b);
		return (0);
	}
	ft_sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
