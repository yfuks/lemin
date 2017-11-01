/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_path_in_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 12:23:02 by yfuks             #+#    #+#             */
/*   Updated: 2017/10/07 15:15:11 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			add_path_in_list(t_path_list **list, t_path *path)
{
	t_path_list		*cursor;

	if (!*list)
	{
		if (!(*list = new_path_list(path)))
			return (0);
		return (1);
	}
	cursor = *list;
	while (cursor->next)
		cursor = cursor->next;
	if (!(cursor->next = new_path_list(path)))
		return (0);
	return (1);
}
