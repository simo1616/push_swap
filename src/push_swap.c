/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:22:29 by mbendidi          #+#    #+#             */
/*   Updated: 2024/12/29 15:40:04 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	push_bottom(t_stack *a, int nb)
{
	t_node	*new_node;
	t_node	*tmp;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
	{
		write(2, "\033[31m ERROR MLK\033[0m\n", 21);
		exit(1);
	}
	new_node->value = nb;
	new_node->next = NULL;
	if (!a->top)
	{
		a->top = new_node;
		a->size++;
		return ;
	}
	tmp = a->top;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
	a->size++;
}

void	init_stack(t_stack *stack, char id)
{
	stack->top = NULL;
	stack->size = 0;
	stack->id = id;
}

int	check_and_push(char **av, t_stack *a)
{
	int	i;
	int	nb;

	i = 1;
	nb = 0;
	while (av[i])
	{
		if (!valid_number(av[i]))
		{
			write(2, "\033[31m ERROR VN\033[0m\n", 20);
			free_stack(a);
			return (0);
		}
		nb = ft_atoll(av[i]);
		if (!check_atoll(av[i], &nb) || has_duplicate(a, nb))
		{
			write(2, "\033[31m ERROR ATL or DPLK \033[0m\n", 30);
			free_stack(a);
			return (0);
		}
		push_bottom(a, nb);
		i++;
	}
	return (1);
}

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
