/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 10:49:42 by ldesboui          #+#    #+#             */
/*   Updated: 2026/01/13 13:11:59 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

int	checkav(char **av)
{
	if (ft_strsisnum(av[1]) == 0)
		return (0);
	else
	{
		if (ft_atoi(av[1]) == 0)
			return (0);
	}
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
