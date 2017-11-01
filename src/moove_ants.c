/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 15:26:53 by yfuks             #+#    #+#             */
/*   Updated: 2017/10/14 15:39:14 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"
#include "tools.h"

static void		sort_paths(t_path_list **list)
{
	t_path_list		*cursor;
	t_path			*tmp;

	cursor = *list;
	while (cursor)
	{
		if (cursor->next && cursor->path->length > cursor->next->path->length)
		{
			tmp = cursor->path;
			cursor->path = cursor->next->path;
			cursor->next->path = tmp;
			cursor = *list;
		}
		else
			cursor = cursor->next;
	}
}

static t_ant	*init_ants(int nb_ants, t_path **path)
{
	t_ant	*ants;
	int		i;

	if (!(ants = (t_ant *)malloc(sizeof(t_ant) * nb_ants)))
		return (NULL);
	i = 0;
	while (i < nb_ants)
	{
		ants[i].c = *path;
		i++;
	}
	return (ants);
}

static void		single_road(int nb_ants, t_path **path)
{
	t_ant	*ants;

	ants = init_ants(nb_ants, path);
	launch_ants(nb_ants, ants);
	free(ants);
}

void			moove_ants(int nb_ants, t_path_list **list, t_room **rooms)
{
	t_path_list		*cursor;
	t_room			*start;
	t_path			*path;

	cursor = *list;
	path = cursor->path;
	while (cursor)
	{
		cursor->path->length = get_path_length(&cursor->path);
		cursor = cursor->next;
	}
	sort_paths(list);
	start = get_start_room(rooms);
	start->nb_ants = nb_ants;
	if (!(*list)->next)
		single_road(nb_ants, &path);
	else
		multi_road(nb_ants, list);
}
