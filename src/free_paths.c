/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 17:20:51 by yfuks             #+#    #+#             */
/*   Updated: 2017/10/13 17:22:46 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"

void		free_paths(t_path_list **paths)
{
	t_path_list	*cursor;
	t_path_list	*tmp;

	cursor = *paths;
	while (cursor)
	{
		free_path(&cursor->path);
		tmp = cursor;
		cursor = cursor->next;
		free(tmp);
	}
}
