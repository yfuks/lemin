/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 15:32:10 by yfuks             #+#    #+#             */
/*   Updated: 2017/10/10 17:21:58 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		get_path_length(t_path **path)
{
	t_path		*cursor;
	int			i;

	cursor = *path;
	i = 0;
	while (cursor)
	{
		i++;
		cursor = cursor->next;
	}
	return (i);
}
