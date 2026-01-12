/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 21:28:06 by ldesboui          #+#    #+#             */
/*   Updated: 2026/01/12 11:57:42 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

static void	make_table(t_table *table, t_fork *forks, t_philo *philos, char **a)
{
	table->forks = forks;
	table->philos = philos;
	pthread_mutex_lock(&(table->lockrun));
	table->running = 1;
	pthread_mutex_unlock(&(table->lockrun));
	if (!a[5])
		table->musteat = 2147483647;
	else
		table->musteat = ft_atoi(a[5]);
}

int	parser(t_table *table, char **arg)
{
	int		nb;
	t_fork	*forks;
	t_philo	*philos;

	nb = ft_atoi(arg[1]);
	table->valid_mu = pthread_mutex_init(&(table->lock), NULL);
	if (table->valid_mu != 0)
		return (0);
	table->valid_lockrun = pthread_mutex_init(&(table->lockrun), NULL);
	if (table->valid_lockrun != 0)
	{
		pthread_mutex_destroy(&(table->lock));
		return (0);
	}
	table->valid_hour = pthread_mutex_init(&(table->mu_hour), NULL);
	if (table->valid_hour != 0)
	{
		pthread_mutex_destroy(&(table->lock));
		pthread_mutex_destroy(&(table->lockrun));
		return (0);
	}
	forks = ft_calloc(sizeof(t_fork), nb + 1);
	if (!forks)
	{
		pthread_mutex_destroy(&(table->lockrun));
		pthread_mutex_destroy(&(table->lock));
		pthread_mutex_destroy(&(table->mu_hour));
		return (0);
	}
	philos = ft_calloc(sizeof(t_philo), nb + 1);
	if (!philos)
	{
		free (forks);
		pthread_mutex_destroy(&(table->lock));
		pthread_mutex_destroy(&(table->lockrun));
		pthread_mutex_destroy(&(table->mu_hour));
		return (0);
	}
	init(philos, forks, arg, table);
	make_table(table, forks, philos, arg);
	if (check_mutexes(table, arg) == 0)
		return (0);
	return (1);
}
