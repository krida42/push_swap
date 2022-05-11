/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:00:18 by kisikaya          #+#    #+#             */
/*   Updated: 2022/03/20 21:04:26 by kisikaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef void	(**t_xmove)(t_stack **, int);
typedef void	(**t_rmove)(t_stack **, t_stack **);

void	move_to_first(t_stack **stack, t_stack *el, char c)
{
	int			i;
	const int	index = get_index(*stack, el);
	void		(*rotate_me)(t_stack **, int is_print);
	void		(*reverse_me)(t_stack **, int is_print);

	if (c == 'a')
	{
		rotate_me = rotate_a;
		reverse_me = reverse_a;
	}
	else
	{
		rotate_me = rotate_b;
		reverse_me = reverse_b;
	}
	i = -1;
	if (index <= stack_len(*stack) / 2)
		while (++i < index)
			rotate_me(stack, 1);
	else
		while (++i < stack_len(*stack) - index)
			reverse_me(stack, 1);
}

void	init_moves(t_xmove move_a, t_xmove move_b, t_rmove move_r, int dir)
{
	if (dir)
	{
		*move_a = rotate_a;
		*move_b = rotate_b;
		*move_r = rotate_r;
	}
	else
	{
		*move_a = reverse_a;
		*move_b = reverse_b;
		*move_r = reverse_r;
	}
}

void	move_optimized(t_stack **s_a, t_stack **s_b, int a, int b)
{
	int		dir;
	int		min;
	void	(*move_a)(t_stack **, int is_print);
	void	(*move_b)(t_stack **, int is_print);
	void	(*move_r)(t_stack **, t_stack **);

	if (!are_same_sign(a, b))
		ft_exit("DANGER - - move_optimized - - a and b arent same sign");
	dir = a >= 0;
	a = get_abs(a);
	b = get_abs(b);
	min = a;
	if (b < a)
		min = b;
	init_moves(&move_a, &move_b, &move_r, dir);
	while (min--)
		move_r(s_a, s_b);
	if (a > b)
		while (a-- > b)
			move_a(s_a, 1);
	else if (b > a)
		while (b-- > a)
			move_b(s_b, 1);
}
