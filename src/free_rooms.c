/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 17:16:18 by yfuks             #+#    #+#             */
/*   Updated: 2017/10/13 17:21:05 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"

void		free_rooms(t_room **rooms)
{
	t_room	*cursor;
	t_room	*tmp;
	int		i;

	cursor = *rooms;
	while (cursor)
	{
		i = 0;
		while (cursor->connections && cursor->connections[i])
		{
			free(cursor->connections[i]);
			i++;
		}
		if (cursor->connections)
			free(cursor->connections);
		free(cursor->name);
		tmp = cursor;
		cursor = cursor->next;
		free(tmp);
	}
}
