/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stdin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 17:38:35 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/01 17:21:35 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tools.h"
#include "lemin.h"

t_room	*parse_stdin(t_fuck_norme_two *n)
{
	while (ft_get_line(&n->line))
	{
		if (is_nb_ants(n->line) && n->nb_ants == 0)
			n->nb_ants = ft_atoi(n->line);
		else if (is_room(n->line) && !n->in_connection)
		{
			if (n->nb_ants <= 0 || !add_room(n->line, &n->rooms, IS_EMPTY))
				return (0);
		}
		else if (is_command(n->line) && !n->in_connection)
		{
			if (n->nb_ants <= 0 || !add_command(n->line, &n->rooms))
				return (0);
		}
		else if (is_connection(n->line, &n->rooms))
		{
			if (n->nb_ants <= 0)
				return (0);
			if ((n->in_connection = 1) && !add_connection(n->line, &n->rooms))
				return (n->rooms);
		}
		else if (!is_commentary(n->line))
			return (n->rooms);
	}
	return (n->rooms);
}
