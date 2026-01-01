/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 19:37:34 by ldesboui          #+#    #+#             */
/*   Updated: 2026/01/01 20:53:24 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	main(int ac, char **av)
{
	t_phio	*philos;
	t_forks *forks;
	if (ac > 4)
	{
		int nb = ft_atoi(av[1]);
		int i = 0;
		forks = ft_calloc(sizeof(t_fork), nb);
		while (i < nb)
		{
			forks[i].nb =  i;
			pthread_mutex_init(&(forks[i].lock), NULL);
			++i;
		}
		i = 1;
		philos = ft_calloc(sizeof(t_philo), nb);
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
	else
	printf("Bad args :(");
}
