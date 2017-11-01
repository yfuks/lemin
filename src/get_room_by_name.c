/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_room_by_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 14:51:05 by yfuks             #+#    #+#             */
/*   Updated: 2017/10/03 17:36:13 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tools.h"
#include "lemin.h"

t_room		*get_room_by_name(char *name, t_room **rooms)
{
	t_room	*cursor;

	cursor = *rooms;
	while (cursor)
	{
		if (ft_strcmp(cursor->name, name) == 0)
			return (cursor);
		cursor = cursor->next;
	}
	return (NULL);
}
