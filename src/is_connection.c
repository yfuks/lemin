/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_connection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 14:49:11 by yfuks             #+#    #+#             */
/*   Updated: 2017/10/03 18:54:02 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"
#include "tools.h"

int		is_connection(char *line, t_room **rooms)
{
	int		i;
	char	*tmp;

	if (!line || !rooms)
		return (0);
	i = 0;
	tmp = ft_strnew(line);
	while (tmp[i] && tmp[i] != '-')
		i++;
	if (!tmp[i])
	{
		free(tmp);
		return (0);
	}
	tmp[i] = 0;
	if (!get_room_by_name(tmp, rooms) || !get_room_by_name(&tmp[i + 1], rooms))
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	return (1);
}
