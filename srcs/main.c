/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 19:37:34 by ldesboui          #+#    #+#             */
/*   Updated: 2026/01/17 13:39:21 by ldesboui         ###   ########.fr       */
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
			printf("Should be positive and in int range, and between 1 and");
			printf(" 399 philosophers\n");
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
