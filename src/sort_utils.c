/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:43:57 by mbendidi          #+#    #+#             */
/*   Updated: 2024/12/28 09:47:32 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_position_of_min(t_stack *stack)
{
    t_node *cur = stack->top;
    int pos = 0;
    int pos_min = 0;
    int current_min = cur->index;

    while (cur)
    {
        if (cur->index < current_min)
        {
            current_min = cur->index;
            pos_min = pos;
        }
        cur = cur->next;
        pos++;
    }
    return (pos_min);
}

int ft_position_of_max(t_stack *stack)
{
    t_node *cur = stack->top;
    int pos = 0;
    int pos_max = 0;
    int current_max = cur->index;

    while (cur)
    {
        if (cur->index > current_max)
        {
            current_max = cur->index;
            pos_max = pos;
        }
        cur = cur->next;
        pos++;
    }
    return (pos_max);
}

int position_of_min_by_value(t_stack *a)
{
    t_node *cur = a->top;
    int pos = 0;
    int pos_min = 0;
    int min_val = cur->value;

    while (cur)
    {
        if (cur->value < min_val)
        {
            min_val = cur->value;
            pos_min = pos;
        }
        cur = cur->next;
        pos++;
    }
    return pos_min;
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
