/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_road.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 13:53:15 by yfuks             #+#    #+#             */
/*   Updated: 2017/10/16 16:11:54 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"
#include "tools.h"

static t_ant	*init_ants(int nb_ants, t_path_list **list)
{
	t_ant		*ants;
	int			i;
	t_path_list	*cursor;

	if (!(ants = (t_ant *)malloc(sizeof(t_ant) * nb_ants)))
		return (NULL);
	i = 0;
	cursor = *list;
	while (i < nb_ants)
	{
		ants[i].c = cursor->path;
		if (cursor->path->length - 2 > 0)
			cursor = cursor->next;
		i++;
		if (!cursor)
			cursor = *list;
	}
	return (ants);
}

void			multi_road(int nb_ants, t_path_list **list)
{
	t_ant	*ants;

	ants = init_ants(nb_ants, list);
	launch_ants(nb_ants, ants);
	free(ants);
}
