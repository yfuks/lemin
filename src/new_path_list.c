/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_path_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 11:56:28 by yfuks             #+#    #+#             */
/*   Updated: 2017/10/07 11:57:40 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"

t_path_list		*new_path_list(t_path *path)
{
	t_path_list	*new;

	if (!(new = (t_path_list*)malloc(sizeof(t_path_list))))
		return (NULL);
	new->path = path;
	new->next = NULL;
	return (new);
}
