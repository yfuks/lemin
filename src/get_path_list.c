/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 14:02:14 by yfuks             #+#    #+#             */
/*   Updated: 2017/10/18 19:09:16 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"
#include "tools.h"

static t_path_list	*find_paths(t_path_list **list, t_room **rooms)
{
	t_room	*start;
	t_path	*path;

	path = NULL;
	if (!(start = get_start_room(rooms)))
		return (NULL);
	if (!add_room_in_path(&path, start))
		return (NULL);
	if (!(create_path(list, &path, rooms)))
		return (NULL);
	return (*list);
}

t_path_list			*get_path_list(t_room **rooms)
{
	t_path_list	*list;

	list = NULL;
	list = find_paths(&list, rooms);
	return (list);
}
