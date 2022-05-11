/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:12:48 by kisikaya          #+#    #+#             */
/*   Updated: 2022/03/22 18:49:51 by kisikaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(char *s)
{
	ft_putstr_fd(s, 2);
	exit(1);
}

static long	ft_latoi(const char *str)
{
	int			signe;
	long		nbr;

	nbr = 0;
	signe = 1;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (str[1] == '+' || str[1] == '-')
			return (0);
		if (*str++ == '-')
			signe = -1;
	}
	while (*str >= '0' && *str <= '9')
		nbr = (nbr * 10) + (*str++ - '0');
	return (nbr * signe);
}

int	is_there_ouflow(char **valstr)
{
	while (*valstr)
	{
		if (ft_latoi(*valstr) < INT_MIN || ft_latoi(*valstr) > INT_MAX
			|| ft_strlen(*valstr) > 11)
			return (1);
		valstr++;
	}
	return (0);
}

void	clear_stack(t_stack *stack)
{
	if (!stack)
		return ;
	while (stack->next)
	{
		stack = stack->next;
		free(stack->prev);
	}
	free(stack);
}

void	free_split(char	**str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}
