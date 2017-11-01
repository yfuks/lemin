/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_room_in_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 11:54:14 by yfuks             #+#    #+#             */
/*   Updated: 2017/10/07 14:12:52 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			add_room_in_path(t_path **path, t_room *room)
{
	t_path	*new;
	t_path	*cursor;

	if (!(new = new_path(room)))
		return (0);
	if (!*path)
	{
		*path = new;
		return (1);
	}
	cursor = *path;
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = new;
	return (1);
}
