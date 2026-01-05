/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 19:37:34 by ldesboui          #+#    #+#             */
/*   Updated: 2026/01/05 21:05:24 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	main(int ac, char **av)
{
	t_table	table;
	int		ok;

	if (ac > 4 && ac <= 6)
	{
		if (checkav(av) == 0)
		{
			printf("Args are not all numerics\n");
			return (0);
		}
		ok = parser(&table, av);
		if (ok != 1)
		{
			freeeverything(&table, av);
			printf("Error during launch\n");
			return (0);
		}
		launch_routine(&table);
		pthread_create(&(table.monitor), NULL, monitor_routine, &table);
		jointhreads(&table);
	}
	else
		printf("too much or not enough args\n");
}
