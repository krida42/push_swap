/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:14:55 by kisikaya          #+#    #+#             */
/*   Updated: 2022/03/20 18:15:22 by kisikaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	rm_first(t_stack **stack)
{
	if (!*stack)
		return ;
	else if (!(*stack)->next)
	{
		free(*stack);
		*stack = NULL;
	}
	else
	{
		*stack = (*stack)->next;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
}

int	is_sorted(t_stack *stack)
{
	while (stack)
	{
		if (stack->prev && stack->prev->val > stack->val)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_stack	*get_el(t_stack *stack, int index)
{
	int	i;

	if (index < 0)
		ft_exit("DANGER  - - - INDEX NEGATIVE");
	else if (index >= stack_len(stack))
		ft_exit("DANGER  - - - -  INDEX GREATER THAN STACK_LEN");
	i = -1;
	while (++i < index)
		stack = stack->next;
	return (stack);
}

int	get_index(t_stack *stack, t_stack *el)
{
	int	i;

	if (!stack || !el)
		ft_exit("DANGER - - - get_index - stack or el is NULL");
	i = 0;
	while (stack && stack->val != el->val)
	{
		stack = stack->next;
		i++;
	}
	if (!stack)
		i = -1;
	return (i);
}
