/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:28:36 by yfuks             #+#    #+#             */
/*   Updated: 2017/10/09 19:06:40 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "tools.h"

int		parse_arguments(int ac, char **av, t_options *options)
{
	int		i;
	int		j;

	options->debug = 0;
	if (ac <= 1)
		return (1);
	i = 1;
	while (av[i])
	{
		if (av[i][0] != '-')
			return (0);
		j = 1;
		while (av[i][j])
		{
			if (av[i][j] == 'd')
				options->debug = 1;
			j++;
		}
		i++;
	}
	return (1);
}
