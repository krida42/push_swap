/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:28:42 by kisikaya          #+#    #+#             */
/*   Updated: 2022/03/22 21:26:44 by kisikaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				val;
	int				tag;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_blessed
{
	int					count_a;
	int					count_b;
	int					count_r;
	struct s_stack		*el;
}	t_blessed;

t_stack		*mkstack(char **valstr);
t_stack		*new_el(int nb);
t_stack		*get_last(t_stack *stack);
t_stack		*get_el(t_stack *stack, int index);
t_stack		*get_first(t_stack *stack);
int			get_index(t_stack *stack, t_stack *el);
void		add_back(t_stack **stack, int nb);
void		add_first(t_stack **stack, int nb);
void		add_to(t_stack **stack, int index, int nb);
void		rm_first(t_stack **stack);

void		push_b(t_stack **s_a, t_stack **s_b);
void		push_a(t_stack **s_a, t_stack **s_b);
void		rotate_a(t_stack **s_a, int is_print);
void		rotate_b(t_stack **s_b, int is_print);
void		rotate_r(t_stack **s_a, t_stack **s_b);
void		reverse_a(t_stack **s_a, int is_print);
void		reverse_b(t_stack **s_b, int is_print);
void		reverse_r(t_stack **s_a, t_stack **s_b);
void		swap_a(t_stack **s_a);

void		sort_it(t_stack **s_a, t_stack **s_b);
int			is_sorted(t_stack *stack);
int			is_sorted_nof(t_stack *stack);
int			smart_push_sort(t_stack **s_a, t_stack **s_b);
int			max_push_sort(t_stack **s_a, t_stack **s_b);
int			pivot_pushing(t_stack **s_a, t_stack **s_b, int pivot);
void		move_to_first(t_stack **stack, t_stack *el, char c);
void		move_optimized(t_stack **s_a, t_stack **s_b, int a, int b);
int			count_optimized(int a, int b);
int			count_move(t_stack *stack, t_stack *el);

t_stack		*find_max(t_stack *stack);
t_stack		*find_min(t_stack *stack);
t_stack		*find_greater(t_stack *s_a, t_stack *b_el);
t_stack		*get_part(t_stack *s_a, int divider);

int			stack_len(t_stack *stack);
int			get_abs(int nb);
int			are_same_sign(int a, int b);
void		ft_exit(char *s);
int			is_there_ouflow(char **valstr);
void		clear_stack(t_stack *stack);
void		free_split(char	**str);
#endif
