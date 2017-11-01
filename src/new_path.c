/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 14:14:41 by yfuks             #+#    #+#             */
/*   Updated: 2017/10/06 14:17:32 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"

t_path		*new_path(t_room *room)
{
	t_path	*new;

	if (!(new = (t_path*)malloc(sizeof(t_path))))
		return (NULL);
	new->room = room;
	new->next = NULL;
	return (new);
}
