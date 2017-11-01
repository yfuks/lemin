/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_room_in_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 12:44:16 by yfuks             #+#    #+#             */
/*   Updated: 2017/10/10 17:37:37 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "lemin.h"

int		is_room_in_path(t_path **path, char *room_name)
{
	t_path	*cursor;

	cursor = *path;
	while (cursor)
	{
		if (ft_strcmp(cursor->room->name, room_name) == 0)
			return (1);
		cursor = cursor->next;
	}
	return (0);
}
