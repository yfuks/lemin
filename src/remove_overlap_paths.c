/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_overlap_paths.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:06:30 by yfuks             #+#    #+#             */
/*   Updated: 2017/10/14 16:35:07 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"
#include "tools.h"

static int		paths_have_room_in_common(t_path **path1, t_path **path2)
{
	t_path		*cursor;
	t_room		*room;

	cursor = *path1;
	while (cursor)
	{
		room = cursor->room;
		if (!(room->infos & IS_END) && !(room->infos & IS_START))
		{
			if (is_room_in_path(path2, room->name))
				return (1);
		}
		cursor = cursor->next;
	}
	return (0);
}

static void		remove_left_path(t_path_list **list, t_path_list **cursor,
								t_path_list **prev)
{
	if (!*prev)
	{
		*list = (*cursor)->next;
		free(*cursor);
		*cursor = *list;
	}
	else
	{
		(*prev)->next = (*cursor)->next;
		free(*cursor);
		*cursor = *prev;
	}
}

static void		remove_longer_path(t_two_path *paths,
								t_path_list **list, t_path_list **cursor,
								t_path_list **prev)
{
	t_path_list	*tmp;

	if (get_path_length(&paths->path1) <= get_path_length(&paths->path2))
	{
		free_path(&paths->path2);
		tmp = (*cursor)->next->next;
		free((*cursor)->next);
		(*cursor)->next = tmp;
	}
	else
	{
		free_path(&paths->path1);
		remove_left_path(list, cursor, prev);
	}
}

void			remove_overlap_paths(t_path_list **list)
{
	t_two_path	paths;
	t_path_list	*cursor;
	t_path_list	*prev;

	cursor = *list;
	prev = NULL;
	while (cursor->next)
	{
		paths.path1 = cursor->path;
		paths.path2 = cursor->next->path;
		if (paths_have_room_in_common(&paths.path1, &paths.path2))
			remove_longer_path(&paths, list, &cursor, &prev);
		else
		{
			prev = cursor;
			cursor = cursor->next;
		}
	}
}
