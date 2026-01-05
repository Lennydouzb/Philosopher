/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 10:49:42 by ldesboui          #+#    #+#             */
/*   Updated: 2026/01/05 21:19:23 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

int	checkav(char **av)
{
	if (ft_strsisnum(av[1]) == 0)
		return (0);
	if (ft_strsisnum(av[2]) == 0)
		return (0);
	if (ft_strsisnum(av[3]) == 0)
		return (0);
	if (ft_strsisnum(av[4]) == 0)
		return (0);
	if (!av[5])
		return (1);
	if (ft_strsisnum(av[5]) == 0)
		return (0);
	return (1);
}

int	check_mutexes(t_table *table, char **arg)
{
	int	i;

	i = 0;
	while (i < ft_atoi(arg[1]))
	{
		if (table->philos[i].valid_eat != 0)
			return (0);
		if (table->forks[i].valid_mutex != 0)
			return (0);
		++i;
	}
	if (table->valid_lockrun != 0 || table->valid_mu != 0)
		return (0);
	return (1);
}
