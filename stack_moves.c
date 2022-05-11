/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:03:23 by kisikaya          #+#    #+#             */
/*   Updated: 2022/03/22 21:35:20 by kisikaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_x(t_stack **s_a, t_stack **s_b)
{
	if (!*s_a)
		ft_exit("DANGER - - push_b - - s_a or s_b is NULL");
	add_first(s_b, (*s_a)->val);
	rm_first(s_a);
}

void	push_a(t_stack **s_a, t_stack **s_b)
{
	ft_putstr_fd("pa\n", 1);
	push_x(s_b, s_a);
}

void	push_b(t_stack **s_a, t_stack **s_b)
{
	ft_putstr_fd("pb\n", 1);
	push_x(s_a, s_b);
}

void	swap_a(t_stack **s_a)
{
	t_stack	*second;

	second = (*s_a)->next;
	second->prev = NULL;
	(*s_a)->prev = second;
	(*s_a)->next = second->next;
	if (second->next)
		(second->next)->prev = (*s_a);
	second->next = *s_a;
	*s_a = second;
	ft_putstr_fd("sa\n", 1);
}
