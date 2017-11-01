/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 12:01:35 by yfuks             #+#    #+#             */
/*   Updated: 2017/10/07 17:02:12 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"

void		free_path(t_path **path)
{
	t_path	*cursor;
	t_path	*prev;

	if (!*path)
		return ;
	cursor = *path;
	prev = *path;
	while (cursor)
	{
		prev = cursor;
		cursor = cursor->next;
		free(prev);
	}
	*path = NULL;
}
