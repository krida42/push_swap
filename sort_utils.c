/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:04:21 by kisikaya          #+#    #+#             */
/*   Updated: 2022/03/21 17:07:51 by kisikaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	quick_sort(t_stack **s_a, t_stack **s_b)
{
	int	pivot;

	while (stack_len(*s_a) > 1)
	{
		pivot = get_part(*s_a, 2)->val;
		pivot_pushing(s_a, s_b, pivot);
	}
	smart_push_sort(s_a, s_b);
	return (0);
}

void	smallest_sort(t_stack **s_a)
{
	if (is_sorted_nof(*s_a))
	{
		move_to_first(s_a, find_min(*s_a), 'a');
		return ;
	}
	else
		swap_a(s_a);
	smallest_sort(s_a);
}

void	medium_sort(t_stack **s_a, t_stack **s_b)
{
	while (stack_len(get_first(*s_a)) > 3)
	{
		if (*s_a != find_max(*s_a))
			push_b(s_a, s_b);
		else
			rotate_a(s_a, 1);
	}
	smallest_sort(s_a);
	smart_push_sort(s_a, s_b);
}

void	sort_it(t_stack **s_a, t_stack **s_b)
{
	if (stack_len(*s_a) <= 3)
		smallest_sort(s_a);
	else if (stack_len(*s_a) < 100)
		medium_sort(s_a, s_b);
	else
		quick_sort(s_a, s_b);
}
