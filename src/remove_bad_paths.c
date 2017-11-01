/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_bad_paths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 16:25:57 by yfuks             #+#    #+#             */
/*   Updated: 2017/10/14 16:22:40 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"
#include "tools.h"

static int	path_working(t_path **list)
{
	t_path	*cursor;

	cursor = *list;
	while (cursor->next)
		cursor = cursor->next;
	if (!(cursor->room->infos & IS_END))
		return (0);
	return (1);
}

static void	remove_path(t_path_list **list, t_path_list **cursor,
						t_path_list **prev)
{
	if (!*prev)
	{
		*list = (*cursor)->next;
		free_path(&(*cursor)->path);
		free(*cursor);
		*cursor = *list;
	}
	else
	{
		(*prev)->next = (*cursor)->next;
		free_path(&(*cursor)->path);
		free(*cursor);
		*cursor = *prev;
	}
}

void		remove_bad_paths(t_path_list **list)
{
	t_path_list		*cursor;
	t_path_list		*prev;

	if (!*list)
		return ;
	cursor = *list;
	prev = NULL;
	while (cursor)
	{
		if (!path_working(&cursor->path))
			remove_path(list, &cursor, &prev);
		else
		{
			prev = cursor;
			cursor = cursor->next;
		}
	}
}
