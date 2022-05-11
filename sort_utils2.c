/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:10:54 by kisikaya          #+#    #+#             */
/*   Updated: 2022/03/21 17:26:23 by kisikaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
int	max_push_sort(t_stack **s_a, t_stack **s_b)
{
	while (*s_b)
	{
		move_to_first(s_b, find_max(*s_b), 'b');
		push_a(s_a, s_b);
	}
	return (0);
}
*/
/*
int	push_all(t_stack **s_a, t_stack **s_b)
{
	const t_stack	*max = find_max(*s_a);

	if (!*s_a)
		ft_exit("DANGER - - push_all - - s_a is null");
	while (stack_len(*s_a) > 1)
	{
		if (*s_a != max)
			push_b(s_a, s_b);
		else
			rotate_a(s_a, 1);
	}
	return (0);
}
*/

t_stack	*get_part(t_stack *s_a, int divider)
{
	int		i;
	int		part_len;
	t_stack	*a;

	part_len = (stack_len(s_a) -1) / divider;
	while (s_a)
	{
		a = get_first(s_a);
		i = 0;
		while (a)
		{
			if (s_a->val < a->val)
				i++;
			a = a->next;
		}
		if (i == part_len)
			return (s_a);
		s_a = s_a->next;
	}
	return (ft_exit("DANGER get_part return NULL"), NULL);
}

int	pivot_pushing(t_stack **s_a, t_stack **s_b, int pivot)
{
	t_stack	*a;
	t_stack	*an;
	int		len;
	t_stack	*max;

	a = *s_a;
	len = stack_len(*s_a);
	max = find_max(*s_a);
	while (len--)
	{
		an = a->next;
		if (a->val <= pivot && a != max)
		{
			push_b(s_a, s_b);
		}
		else if (a->val > pivot && len)
		{
			rotate_a(s_a, 1);
		}
		a = an;
	}
	return (0);
}

void	find_bless_him(t_stack *s_a, t_stack *s_b, t_stack *b, t_blessed *bl)
{
	if (bl->count_r == -1 || count_optimized(count_move(s_b, b),
			count_move(s_a, find_greater(s_a, b))) < bl->count_r)
	{
		bl->count_b = count_move(s_b, b);
		bl->count_a = count_move(s_a, find_greater(s_a, b));
		bl->count_r = count_optimized(bl->count_b, bl->count_a);
		bl->el = b;
	}
}

void	make_best_move(t_stack **s_a, t_stack **s_b, t_blessed *bl)
{
	if (!are_same_sign(bl->count_a, bl->count_b))
	{
		move_to_first(s_b, bl->el, 'b');
		move_to_first(s_a, find_greater(*s_a, bl->el), 'a');
		push_a(s_a, s_b);
	}
	else
	{
		move_optimized(s_a, s_b, bl->count_a, bl->count_b);
		push_a(s_a, s_b);
	}
}

int	smart_push_sort(t_stack **s_a, t_stack **s_b)
{
	t_stack		*b;
	t_blessed	bl;

	while (*s_b)
	{
		b = *s_b;
		bl.count_r = -1;
		while (b)
		{
			find_bless_him(*s_a, *s_b, b, &bl);
			b = b->next;
		}
		make_best_move(s_a, s_b, &bl);
	}
	move_to_first(s_a, find_min(*s_a), 'a');
	return (0);
}
