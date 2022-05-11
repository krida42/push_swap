/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:15:34 by kisikaya          #+#    #+#             */
/*   Updated: 2022/03/20 18:15:47 by kisikaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_el(int nb)
{
	t_stack	*el;

	el = (t_stack *) malloc(sizeof(t_stack));
	el->val = nb;
	el->prev = NULL;
	el->next = NULL;
	return (el);
}

t_stack	*get_last(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	add_back(t_stack **stack, int nb)
{
	t_stack	*last;

	if (!*stack)
	{
		*stack = new_el(nb);
		return ;
	}
	last = get_last(*stack);
	last->next = new_el(nb);
	(last->next)->prev = last;
}

void	add_first(t_stack **stack, int nb)
{
	if (!*stack)
	{
		*stack = new_el(nb);
		return ;
	}
	(*stack)->prev = new_el(nb);
	((*stack)->prev)->next = *stack;
	*stack = (*stack)->prev;
}

t_stack	*mkstack(char **valstr)
{
	t_stack	*stack;

	stack = NULL;
	while (*valstr)
	{
		add_back(&stack, ft_atoi(*valstr));
		valstr++;
	}
	return (stack);
}
