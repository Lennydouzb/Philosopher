/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 21:28:06 by ldesboui          #+#    #+#             */
/*   Updated: 2026/01/02 17:04:07 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

t_table	parser(char *arg)
{
	int		nb;
	int		i;
	t_fork	*forks;
	t_philo	*philos;
	t_table	table;

	i = 0;
	nb = ft_atoi(arg);
	forks = ft_calloc(sizeof(t_fork), nb);
	if (!forks)
		return ((t_table){.forks = NULL});
	philos = ft_calloc(sizeof(t_philo), nb);
	if (!philos)
	{
		free (forks);
		return ((t_table){.forks = NULL});
	}
	init(philos, forks, &nb);
	if (forks[i].valid_mutex != 0)
	{
		freeforksandphilos(forks, philos);
		return ((t_table){.forks = NULL});
	}
	table = (t_table){.forks = forks, .philos = philos};
	return (table);
}
