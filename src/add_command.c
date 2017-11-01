/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 15:40:37 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/01 17:21:47 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "tools.h"

static char	get_command_infos(char *line)
{
	char	infos;

	infos = 0;
	if (ft_strcmp(line, "##start") == 0)
		infos = IS_START;
	if (ft_strcmp(line, "##end") == 0)
		infos = IS_END | IS_EMPTY;
	return (infos);
}

int			add_command(char *line, t_room **rooms)
{
	char	infos;
	char	*next_line;

	ft_putendl_fd(line, 1);
	if (!(infos = get_command_infos(line)))
		return (1);
	if (!ft_get_line(&next_line))
		return (0);
	if (!is_room(next_line))
		return (0);
	return (add_room(next_line, rooms, infos));
}
