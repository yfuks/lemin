/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_connection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 16:35:22 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/01 17:00:17 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"
#include "tools.h"

static char	*get_first_room_name(char *line)
{
	int		i;
	char	*name;

	i = 0;
	while (line[i] && line[i] != '-')
		i++;
	if (!(name = (char *)malloc(sizeof(char) * i)))
		return (NULL);
	name[i] = 0;
	while (i--)
		name[i] = line[i];
	return (name);
}

static char	*get_second_room_name(char *line)
{
	int		i;
	int		j;
	char	*name;

	i = 0;
	while (line[i] && line[i] != '-')
		i++;
	i++;
	j = i;
	while (line[i])
		i++;
	if (!(name = (char *)malloc(sizeof(char) * (i - j) + i)))
		return (NULL);
	name[i - j] = 0;
	while (i-- >= j)
		name[i - j] = line[i];
	return (name);
}

static int	connection_not_valid(char *connection, t_room *room)
{
	int		i;

	if (ft_strcmp(room->name, connection) == 0)
		return (1);
	if (room->connections)
	{
		i = 0;
		while (room->connections[i])
		{
			if (ft_strcmp(room->connections[i], connection) == 0)
				return (1);
			i++;
		}
	}
	return (0);
}

static int	add_con_room(char *connection, t_room *room)
{
	if (connection_not_valid(connection, room))
		return (0);
	if (!room->connections)
	{
		if (!(room->connections = (char **)malloc(sizeof(char *) * 3)))
			return (0);
		room->connections[0] = ft_strnew(connection);
		room->connections[1] = NULL;
		return (1);
	}
	if (!(room->connections = ft_stradd(room->connections, connection)))
		return (0);
	return (1);
}

int			add_connection(char *line, t_room **rooms)
{
	char	*r_name_1;
	char	*r_name_2;
	t_room	*room_1;
	t_room	*room_2;

	if (!(r_name_1 = get_first_room_name(line)))
		return (0);
	if (!(r_name_2 = get_second_room_name(line)))
	{
		free(r_name_1);
		return (0);
	}
	room_1 = get_room_by_name(r_name_1, rooms);
	room_2 = get_room_by_name(r_name_2, rooms);
	if (!add_con_room(r_name_2, room_1) || !add_con_room(r_name_1, room_2))
	{
		free(r_name_1);
		free(r_name_2);
		return (0);
	}
	free(r_name_1);
	free(r_name_2);
	ft_putendl_fd(line, 1);
	return (1);
}
