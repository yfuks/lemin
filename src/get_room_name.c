/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_room_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 15:32:57 by yfuks             #+#    #+#             */
/*   Updated: 2017/10/14 15:33:39 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*get_room_name(char *line)
{
	int		i;
	char	*name;

	i = 0;
	while (line[i] != ' ')
		i++;
	if (!(name = (char *)malloc(sizeof(char) * i)))
		return (NULL);
	name[i] = 0;
	while (i--)
		name[i] = line[i];
	return (name);
}
