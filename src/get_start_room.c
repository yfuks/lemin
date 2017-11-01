/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_start_room.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 14:08:58 by yfuks             #+#    #+#             */
/*   Updated: 2017/10/06 14:10:50 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"

t_room		*get_start_room(t_room **rooms)
{
	t_room	*cursor;

	cursor = *rooms;
	while (cursor)
	{
		if (cursor->infos & IS_START)
			return (cursor);
		cursor = cursor->next;
	}
	return (NULL);
}
