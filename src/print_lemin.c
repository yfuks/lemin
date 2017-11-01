/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lemin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 19:10:02 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/01 17:02:20 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "tools.h"

void		print_lemin(t_path_list **list, t_options *opts)
{
	if (opts->debug)
	{
		ft_putendl_fd("\npath(s):", 1);
		print_paths(list);
	}
}
