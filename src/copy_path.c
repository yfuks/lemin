/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 14:19:48 by yfuks             #+#    #+#             */
/*   Updated: 2017/10/07 16:35:23 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"

t_path		*copy_path(t_path **path)
{
	t_path		*copy;
	t_path		*cursor;
	t_path		*cursor2;

	copy = NULL;
	cursor = *path;
	while (cursor)
	{
		if (!copy)
		{
			copy = new_path(cursor->room);
			cursor2 = copy;
		}
		else
		{
			cursor2->next = new_path(cursor->room);
			cursor2 = cursor2->next;
		}
		cursor = cursor->next;
	}
	return (copy);
}
