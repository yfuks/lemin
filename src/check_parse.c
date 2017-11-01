/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:53:52 by yfuks             #+#    #+#             */
/*   Updated: 2017/10/07 18:46:15 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	have_connection(t_room **rooms)
{
	t_room	*cursor;

	cursor = *rooms;
	while (cursor)
	{
		if (cursor->connections)
			return (1);
		cursor = cursor->next;
	}
	return (0);
}

static int	good_end(t_room **rooms)
{
	t_room	*cursor;
	int		have_end;

	have_end = 0;
	cursor = *rooms;
	while (cursor)
	{
		if (cursor->infos & IS_END)
		{
			if (have_end)
				return (0);
			else
				have_end = 1;
		}
		cursor = cursor->next;
	}
	return (have_end);
}

static int	good_start(t_room **rooms)
{
	t_room	*cursor;
	int		have_start;

	have_start = 0;
	cursor = *rooms;
	while (cursor)
	{
		if (cursor->infos & IS_START)
		{
			if (have_start)
				return (0);
			else
				have_start = 1;
		}
		cursor = cursor->next;
	}
	return (have_start);
}

int			check_parse(t_room **rooms)
{
	if (!have_connection(rooms))
		return (0);
	if (!good_end(rooms))
		return (0);
	if (!good_start(rooms))
		return (0);
	return (1);
}
