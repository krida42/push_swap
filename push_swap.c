/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:27:58 by kisikaya          #+#    #+#             */
/*   Updated: 2022/03/22 19:57:14 by kisikaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_doublons(char **valstr)
{
	int	i;
	int	j;
	int	val;

	i = -1;
	while (valstr[++i])
	{
		val = ft_atoi(valstr[i]);
		j = 0;
		while (valstr[i + ++j])
		{
			if (val == ft_atoi(valstr[i + j]))
				return (1);
		}
	}
	return (0);
}

static int	is_only_nbrs(char **valstr)
{
	int	i;

	while (*valstr)
	{
		i = 0;
		while ((*valstr)[i])
		{
			if (((*valstr)[i] == '-' || (*valstr)[i] == '+') && (*valstr)[1]
					&& i == 0 && ++i)
				continue ;
			if (!ft_isdigit((*valstr)[i++]))
				return (0);
		}
		valstr++;
	}
	return (1);
}

static void	do_sanitize(char **valstr)
{
	if (!is_only_nbrs(valstr) || is_doublons(valstr) || is_there_ouflow(valstr))
		ft_exit("Error\n");
	if (!*valstr)
		exit(0);
}

int	main(int argc, char **argv)
{
	char	**valstr;
	t_stack	*s_a;
	t_stack	*s_b;

	if (argc == 1)
		return (0);
	else if (argc == 2)
		valstr = ft_split(argv[1], ' ');
	else
		valstr = argv + 1;
	do_sanitize(valstr);
	s_a = NULL;
	s_b = NULL;
	s_a = mkstack(valstr);
	if (is_sorted_nof(s_a))
		move_to_first(&s_a, find_min(s_a), 'a');
	else
		sort_it(&s_a, &s_b);
	clear_stack(s_a);
	clear_stack(s_b);
	if (argc == 2)
		free_split(valstr);
	return (0);
}
