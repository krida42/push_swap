/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:09:32 by kisikaya          #+#    #+#             */
/*   Updated: 2022/03/20 20:51:57 by kisikaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_first(t_stack *stack)
{
	while (stack->prev)
		stack = stack->prev;
	return (stack);
}

void	add_to(t_stack **stack, int index, int nb)
{
	t_stack	*el_i;
	t_stack	*el_nw;

	if (index < 0)
		ft_exit("DANGER - - add_to - - INDEX NEGATIVE");
	else if (index > stack_len(*stack))
		ft_exit("DANGER - - add_to - - INDEX GREATER THAN STACK LEN");
	if (!index || !*stack)
		add_first(stack, nb);
	else if (index == stack_len(*stack))
		add_back(stack, nb);
	else
	{
		el_i = get_el(*stack, index);
		el_nw = new_el(nb);
		el_nw->prev = el_i->prev;
		el_nw->next = el_i;
		(el_i->prev)->next = el_nw;
		el_i->prev = el_nw;
		(el_i->prev)->next = el_i;
	}
}

t_stack	*find_max(t_stack *stack)
{
	t_stack	*max;

	if (!stack)
		ft_exit("DANGER - - find_max - - stack is NULL");
	max = stack;
	while (stack)
	{
		if (stack->val > max->val)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

t_stack	*find_min(t_stack *stack)
{
	t_stack	*min;

	if (!stack)
		ft_exit("DANGER - - find_min - - stack is NULL");
	min = stack;
	while (stack)
	{
		if (stack->val < min->val)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_stack	*find_greater(t_stack *s_a, t_stack *b_el)
{
	t_stack	*greater;

	if (!b_el)
		ft_exit("DANGER - - find_greater - - b_el is NULL");
	if (!s_a)
		ft_exit("DANGER - - find_greater - - s_a is NULL");
	greater = find_max(s_a);
	while (s_a)
	{
		if (s_a->val > b_el->val && s_a->val < greater->val)
			greater = s_a;
		s_a = s_a->next;
	}
	return (greater);
}
