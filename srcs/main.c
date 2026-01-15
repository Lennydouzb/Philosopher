/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 19:37:34 by ldesboui          #+#    #+#             */
/*   Updated: 2026/01/15 19:13:06 by ldesboui         ###   ########.fr       */
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
			printf("Args should ne numeric, and at least one philo bozo\n");
			return (0);
		}
		ok = parser(&table, av);
		if (ok != 1)
		{
			destroy(&table);
			printf("Error during launch\n");
			return (0);
		}
		launch_routine(&table);
		jointhreads(&table);
		destroy(&table);
	}
	else
		printf("too much or not enough args\n");
}
