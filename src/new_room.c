/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 15:05:43 by yfuks             #+#    #+#             */
/*   Updated: 2017/10/03 15:38:40 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"

t_room		*new_room(void)
{
	t_room	*new;

	new = (t_room *)malloc(sizeof(t_room));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->connections = NULL;
	new->nb_ants = 0;
	new->infos = 0;
	new->cor_x = 0;
	new->cor_y = 0;
	new->name = NULL;
	return (new);
}
