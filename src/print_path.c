/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 16:22:26 by yfuks             #+#    #+#             */
/*   Updated: 2017/10/07 16:24:53 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "lemin.h"

void		print_path(t_path **path)
{
	t_path			*cursor;

	cursor = *path;
	while (cursor)
	{
		ft_putstr_fd(cursor->room->name, 1);
		if (cursor->next)
			ft_putstr_fd("->", 1);
		else
			ft_putchar_fd('\n', 1);
		cursor = cursor->next;
	}
}
