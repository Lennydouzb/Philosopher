/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 21:28:06 by ldesboui          #+#    #+#             */
/*   Updated: 2026/01/01 21:33:05 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

int	parser(char *arg)
{
	int		nb;
	int		i;
	t_fork	*forks;
	t_philo	*philos;

	i = 0;
	nb = ft_atoi(arg);
	forks = ft_calloc(sizeof(t_fork), nb);
	if (!forks)
		return (0);
	while (i < nb)
	{
		forks[i].nb = i;
		pthread_mutex_init(&(forks[i].lock), NULL);
		++i;
	}
	i = 1;
	philos = ft_calloc(sizeof(t_philo), nb);
	if (!philos)
	{
		free (forks);
		return (0);
	}
	philos[0].nb = 0;
	philos[0].lfork = &(forks[0]);
	while (i < nb)
	{
		philos[i].nb = i;
		philos[i].lfork = &(forks[i]);
		philos[i].rfork = &(forks[i - 1]);
		++i;
	}
	philos[0].rfork = &(forks[i - 1]);
}
