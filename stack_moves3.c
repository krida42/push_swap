/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:10:38 by kisikaya          #+#    #+#             */
/*   Updated: 2022/03/22 21:34:37 by kisikaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_x(t_stack **s_a)
{
	t_stack	*last;

	if (!*s_a)
		ft_exit("DANGER - - trying to reverse when it's NULL - -");
	else if (!(*s_a)->next)
		ft_exit("DANGER - - reverse when there is only one number - -");
	last = get_last(*s_a);
	(last->prev)->next = NULL;
	last->next = (*s_a);
	last->prev = NULL;
	(*s_a)->prev = last;
	*s_a = last;
}

void	reverse_a(t_stack **s_a, int is_print)
{
	if (is_print)
		ft_putstr_fd("rra\n", 1);
	reverse_x(s_a);
}

void	reverse_b(t_stack **s_b, int is_print)
{
	if (is_print)
		ft_putstr_fd("rrb\n", 1);
	reverse_x(s_b);
}

void	reverse_r(t_stack **s_a, t_stack **s_b)
{
	reverse_a(s_a, 0);
	reverse_b(s_b, 0);
	ft_putstr_fd("rrr\n", 1);
}
