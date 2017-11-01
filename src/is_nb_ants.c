/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_nb_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 14:16:05 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/01 17:01:32 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int		is_nb_ants(char *line)
{
	int		i;

	if (!line || !line[0])
		return (0);
	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			return (0);
		i++;
	}
	ft_putendl_fd(line, 1);
	return (1);
}
