/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:22:48 by mbendidi          #+#    #+#             */
/*   Updated: 2024/12/23 17:42:32 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}	t_stack;

void		init_stack(t_stack *stack);
int			ft_is_digit(char c);
int			ft_is_sign(char c);
int			valid_number(char *str);
void		init_stack(t_stack *stack);
long long	ft_atoll(const char *str);
int			has_duplicate(t_stack *a, int nb);
void		push_top(t_stack *a, int nb);
void		print_stack(t_stack *a);
int			check_atoll(const char *str, int *out);
void		free_stack(t_stack *a);
void		push_a(t_stack *a, t_stack *b);
void		push_b(t_stack *a, t_stack *b);
void		ft_sa(t_stack *stack);
void		ft_sb(t_stack *stack);
void		ft_ss(t_stack *a, t_stack *b);
void		ft_ra(t_stack *a);
void		ft_rb(t_stack *b);
void		ft_rr(t_stack *a, t_stack *b);
void		ft_rra(t_stack *a);
void		ft_rrb(t_stack *b);
void		ft_rrr(t_stack *a, t_stack *b);
void		ft_sort_three(t_stack *a);
void		ft_sort(t_stack *a, t_stack *b);

#endif