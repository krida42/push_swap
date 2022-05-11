/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:02:54 by kisikaya          #+#    #+#             */
/*   Updated: 2022/03/20 21:35:02 by kisikaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

int	are_same_sign(int a, int b)
{
	if ((a > 0 && b > 0) || (a < 0 && b < 0))
		return (1);
	return (0);
}

int	is_sorted_nof(t_stack *stack)
{
	int		len;
	t_stack	*next;
	t_stack	*tmp_stack;

	len = stack_len(stack);
	tmp_stack = stack;
	stack = find_min(stack);
	while (--len)
	{
		if (!stack)
			stack = get_first(tmp_stack);
		next = stack->next;
		if (!next)
			next = get_first(stack);
		if (stack->val > next->val)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	count_move(t_stack *stack, t_stack *el)
{
	const int	index = get_index(stack, el);

	if (!stack)
		ft_exit("DANGER  - - count_move - -stack is null");
	if (!el)
		ft_exit("DANGER  - - count_move - -el is null");
	if (index <= stack_len(stack) / 2)
		return (index);
	else
		return (- (stack_len(stack) - index));
}

int	count_optimized(int a, int b)
{
	if (!are_same_sign(a, b))
		return (get_abs(a) + get_abs(b));
	if (get_abs(a) > get_abs(b))
		return (get_abs(a));
	return (get_abs(b));
}
