/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:40:10 by mbendidi          #+#    #+#             */
/*   Updated: 2024/12/30 22:42:56 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ***************************** INCLUDES *********************************** */
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"

/* ***************************** STRUCTURES ********************************* */
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
	char			id;
}	t_stack;

typedef struct s_chunk
{
	int				start;
	int				end;
	int				size_init;
}	t_chunk;

typedef struct s_args
{
	int				i;
	int				chunk_size;
	int				size_init;
}	t_args;

/* ***************************** PROTOTYPES ********************************* */

/* Initialization and validation */
void		init_stack(t_stack *stack, char id);
int			ft_is_digit(char c);
int			ft_is_sign(char c);
int			valid_number(char *str);
int			check_atoll(const char *str, int *out);
long long	ft_atoll(const char *str);
int			has_duplicate(t_stack *a, int nb);
void		free_stack(t_stack *a);

/* Stack operations */
void		push_bottom(t_stack *a, int nb);
void		print_stack(t_stack *a);
void		ft_pa(t_stack *a, t_stack *b);
void		ft_pb(t_stack *a, t_stack *b);
void		ft_sa(t_stack *stack);
void		ft_sb(t_stack *stack);
void		ft_ss(t_stack *a, t_stack *b);
void		ft_ra(t_stack *a);
void		ft_rb(t_stack *b);
void		ft_rr(t_stack *a, t_stack *b);
void		ft_rra(t_stack *a);
void		ft_rrb(t_stack *b);
void		ft_rrr(t_stack *a, t_stack *b);

/* Sorting utilities */
void		ft_sort(t_stack *a, t_stack *b);
void		ft_sort_three(t_stack *a);
void		ft_sort_four(t_stack *a, t_stack *b);
void		ft_sort_five(t_stack *a, t_stack *b);
int			ft_position_of_min(t_stack *stack);
int			position_of_min_by_value(t_stack *a);
int			ft_is_sorted(t_stack *stack);

/* Chunk management */
void		index_values(t_stack *a);
void		bring_back_to_a(t_stack *a, t_stack *b);
void		push_chunk_to_b(t_stack *a, t_stack *b, t_chunk ck);
int			get_chunk_size(int size);
void		process_chunk(t_stack *a, t_stack *b, t_args arg);
void		sort_chunks(t_stack *a, t_stack *b);
void		bring_back_all_in_order(t_stack *a, t_stack *b);

/* Utility functions */
int			ft_position_of_max(t_stack *stack);
int			ft_position_of_next_max(t_stack *stack);
int			find_position_in_stack(t_stack *stack, int start, int end);
int			find_position_frm_bot(t_stack *stack, int start, int end);
int			check_and_push(char **av, t_stack *a);
void		ft_move_top(t_stack *stack, int index);

#endif
