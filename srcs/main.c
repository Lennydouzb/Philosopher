/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 19:37:34 by ldesboui          #+#    #+#             */
/*   Updated: 2026/01/05 10:02:41 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	main(int ac, char **av)
{
	t_table	table;

	if (ac > 4 && ac <= 6)
	{
		if (checkav(av) == 0)
		{
			printf("Args are not all numerics\n");
			return (0);
		}
		table = parser(av[1]);
		if (table.forks == NULL)
		{
			printf("Error during launch\n");
			return (0);
		}
	}
	else
		printf("too much or not enough args\n");
}
