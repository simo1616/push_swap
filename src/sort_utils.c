/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:43:57 by mbendidi          #+#    #+#             */
/*   Updated: 2024/12/26 18:07:31 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_position_of_max(t_stack *stack)
{
    t_node *cur;
    int max;
    int max_index;
    int index;

    cur = stack->top;
    max = cur->value;
    max_index = 0;
    index = 0;

    while (cur)
    {
        if (cur->value > max)
        {
            max = cur->value;
            max_index = index;
        }
        cur = cur->next;
        index++;
    }
    return max_index;
}

void index_values(t_stack *a)
{
    t_node *current;
    t_node *compare;
    int index;

    current = a->top;
    while (current)
    {
        index = 0;  // Initialiser l'indice
        compare = a->top;
        while (compare)
        {
            if (compare->value < current->value)
                index++;  // Incrémenter si une valeur plus petite est trouvée
            compare = compare->next;
        }
        current->index = index;  // Stocker l'indice dans le champ `index`
        current = current->next;
    }
}


void	ft_move_top(t_stack *stack, int index)
{
	if (index <= stack->size / 2)
	{
		while (index > 0)
		{
			ft_ra(stack);
			index--;
		}
	}
	else
	{
		while (index < stack->size)
		{
			ft_rra(stack);
			index++;
		}
	}
}

int	ft_position_of_min(t_stack *stack)
{
	t_node	*cur;
	int		min;
	int		min_index;
	int		index;

	cur = stack->top;
	min = cur->value;
	index = 0;
	min_index = 0;
	while (cur)
	{
		if (cur->value < min)
		{
			min = cur->value;
			min_index = index;
		}
		cur = cur->next;
		index++;
	}
	return (min_index);
}

int	ft_is_sorted(t_stack *stack)
{
	t_node	*cur;

	cur = stack->top;
	while (cur && cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}
