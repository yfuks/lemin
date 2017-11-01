/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 14:12:34 by yfuks             #+#    #+#             */
/*   Updated: 2017/10/09 13:52:07 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "tools.h"

void		print_paths(t_path_list **list)
{
	t_path_list		*cursor;

	cursor = *list;
	while (cursor)
	{
		print_path(&(cursor->path));
		cursor = cursor->next;
	}
}
