/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 15:09:54 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/01 17:00:51 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"
#include "tools.h"

static int		get_room_coor_x(char *line)
{
	int		i;

	i = 0;
	while (line[i] != ' ')
		i++;
	return (ft_atoi(&line[i + 1]));
}

static int		get_room_coor_y(char *line)
{
	int		i;

	i = 0;
	while (line[i] != ' ')
		i++;
	i++;
	while (line[i] != ' ')
		i++;
	return (ft_atoi(&line[i + 1]));
}

static t_room	*create_new_room(char *line, char infos)
{
	t_room	*room;

	if (!(room = new_room()))
		return (NULL);
	if (!(room->name = get_room_name(line)))
	{
		free(room);
		return (NULL);
	}
	room->cor_x = get_room_coor_x(line);
	room->cor_y = get_room_coor_y(line);
	room->infos = infos;
	return (room);
}

static int		room_already_exist(char *line, t_room **rooms)
{
	char	*room_name;

	if (!(room_name = get_room_name(line)))
		return (1);
	if (get_room_by_name(room_name, rooms))
	{
		free(room_name);
		return (1);
	}
	free(room_name);
	return (0);
}

int				add_room(char *line, t_room **rooms, char infos)
{
	t_room	*new_room;
	t_room	*cursor;

	if (room_already_exist(line, rooms))
		return (0);
	if (!(new_room = create_new_room(line, infos)))
		return (0);
	if (!*rooms)
	{
		*rooms = new_room;
		ft_putendl_fd(line, 1);
		return (1);
	}
	cursor = *rooms;
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = new_room;
	ft_putendl_fd(line, 1);
	return (1);
}
