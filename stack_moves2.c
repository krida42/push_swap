/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:10:20 by kisikaya          #+#    #+#             */
/*   Updated: 2022/03/22 21:33:52 by kisikaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_x(t_stack **s_a)
{
	t_stack	*last;

	if (!*s_a)
		ft_exit("DANGER - - trying to rotate when it's NULL - -");
	else if (!(*s_a)->next)
		ft_exit("DANGER - - rotate_a when there is only one number - -");
	last = get_last(*s_a);
	last->next = *s_a;
	*s_a = (*s_a)->next;
	((*s_a)->prev)->prev = last;
	((*s_a)->prev)->next = NULL;
	(*s_a)->prev = NULL;
}

void	rotate_a(t_stack **s_a, int is_print)
{
	if (is_print)
		ft_putstr_fd("ra\n", 1);
	rotate_x(s_a);
}

void	rotate_b(t_stack **s_b, int is_print)
{
	if (is_print)
		ft_putstr_fd("rb\n", 1);
	rotate_x(s_b);
}

void	rotate_r(t_stack **s_a, t_stack **s_b)
{
	rotate_a(s_a, 0);
	rotate_b(s_b, 0);
	ft_putstr_fd("rr\n", 1);
}
