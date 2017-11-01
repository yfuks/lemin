/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 15:35:13 by yfuks             #+#    #+#             */
/*   Updated: 2017/10/03 18:34:41 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "tools.h"
#include "lemin.h"

static	int		read_new(t_gl *save)
{
	ssize_t	len;
	char	*buff;
	char	*tmp;

	if (!(buff = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (0);
	while ((len = read(STD_IN, buff, BUFF_SIZE)) > 0)
	{
		buff[len] = 0;
		if (!save->buff_start)
			save->buff_start = ft_strnew(buff);
		else
		{
			tmp = save->buff_start;
			save->buff_start = ft_strconcat(tmp, buff);
			free(tmp);
		}
	}
	free(buff);
	save->buff_current = save->buff_start;
	return (1);
}

static	int		parse_line(t_gl *save, char **line)
{
	int		i;

	i = 0;
	while (save->buff_current[i] && save->buff_current[i] != '\n')
		i++;
	save->buff_current[i] = 0;
	*line = save->buff_current;
	save->buff_current = &save->buff_current[i + 1];
	return (1);
}

static	int		get_new_line(t_gl *save, char **line)
{
	if (!save->buff_start || !save->buff_current)
		return (0);
	if (!save->buff_current[0])
	{
		free(save->buff_start);
		save->buff_start = NULL;
		*line = NULL;
		return (0);
	}
	return (parse_line(save, line));
}

int				ft_get_line(char **line)
{
	static	t_gl	save;

	if (!save.buff_start || !save.buff_current)
	{
		if (!read_new(&save))
			return (0);
	}
	return (get_new_line(&save, line));
}
