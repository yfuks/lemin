/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_room.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 14:35:23 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/01 16:56:16 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int		is_room(char *line)
{
	int		i;

	if (!line || line[0] == 'L' || line[0] == '#')
		return (0);
	i = 0;
	while (line[i] && line[i] != ' ' && line[i] != '-')
		i++;
	if (!line[i])
		return (0);
	i++;
	while (line[i] && (ft_isdigit(line[i]) || line[i] == '-'))
		i++;
	if (!line[i] || line[i] != ' ' || !line[i + 1])
		return (0);
	i++;
	while (line[i] && (ft_isdigit(line[i]) || line[i] == '-'))
		i++;
	if (line[i])
		return (0);
	return (1);
}
