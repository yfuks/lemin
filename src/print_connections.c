/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_connections.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 13:51:30 by yfuks             #+#    #+#             */
/*   Updated: 2017/10/14 16:13:53 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tools.h"
#include "lemin.h"

static t_names	*new_connection(char *name)
{
	t_names	*new;

	if (!(new = (t_names*)malloc(sizeof(t_names))))
		return (NULL);
	new->name = name;
	new->next = NULL;
	return (new);
}

static int		connection_exist(t_names **names, char *name)
{
	t_names		*cursor;

	cursor = *names;
	while (cursor)
	{
		if (ft_strcmp(cursor->name, name) == 0)
			return (1);
		cursor = cursor->next;
	}
	return (0);
}

static int		add_con(t_names **names, char *name)
{
	t_names		*connection;
	t_names		*cursor;

	if (!(connection = new_connection(name)))
		return (0);
	if (!*names)
	{
		*names = connection;
		return (1);
	}
	cursor = *names;
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = connection;
	return (1);
}

static void		free_names(t_names **names)
{
	t_names		*prev;
	t_names		*cursor;

	cursor = *names;
	prev = *names;
	while (cursor)
	{
		cursor = cursor->next;
		free(prev);
		prev = cursor;
	}
}

void			print_connections(t_room **rooms)
{
	t_room	*cursor;
	int		i;
	t_names	*names;

	names = NULL;
	cursor = *rooms;
	while (cursor)
	{
		i = 0;
		while (cursor->connections && cursor->connections[i] != NULL)
		{
			if (!connection_exist(&names, cursor->connections[i]))
			{
				ft_putstr_fd(cursor->name, 1);
				ft_putchar_fd('-', 1);
				ft_putendl_fd(cursor->connections[i], 1);
			}
			i++;
		}
		if (!connection_exist(&names, cursor->name)
			&& !add_con(&names, cursor->name))
			return ;
		cursor = cursor->next;
	}
	free_names(&names);
}
