/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 14:28:00 by yfuks             #+#    #+#             */
/*   Updated: 2017/10/18 19:12:23 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "tools.h"

static	int		add_copy(t_path_list **list, t_path **tmp,
					t_room *room, t_room **rooms)
{
	t_path		*cpy;

	cpy = copy_path(tmp);
	add_room_in_path(&cpy, room);
	if (!(create_path(list, &cpy, rooms)))
		return (0);
	return (1);
}

static	t_path	*get_last_path(t_path **path)
{
	t_path	*cursor;

	cursor = *path;
	while (cursor->next)
		cursor = cursor->next;
	return (cursor);
}

static int		check_room(t_fuck_norme *n, t_room **rooms, t_path **path,
						t_path_list **list)
{
	if (!is_room_in_path(&n->tmp, n->room->name))
	{
		if (!n->room_added)
		{
			add_room_in_path(path, n->room);
			n->room_added = 1;
			if (!(create_path(list, path, rooms)))
				return (0);
		}
		else if (!add_copy(list, &n->tmp, n->room, rooms))
			return (0);
	}
	return (1);
}

int				create_path(t_path_list **list, t_path **path, t_room **rooms)
{
	t_path			*cursor;
	int				i;
	t_fuck_norme	n;

	cursor = get_last_path(path);
	if (cursor->room->infos & IS_END)
		return (add_path_in_list(list, *path));
	i = 0;
	n.room_added = 0;
	n.tmp = copy_path(path);
	while (cursor->room->connections && cursor->room->connections[i])
	{
		n.room = get_room_by_name(cursor->room->connections[i], rooms);
		if (!check_room(&n, rooms, path, list))
			return (0);
		i++;
	}
	free_path(&n.tmp);
	if (!n.room_added)
		return (add_path_in_list(list, *path));
	return (1);
}
