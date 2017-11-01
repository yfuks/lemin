/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 17:42:24 by yfuks             #+#    #+#             */
/*   Updated: 2017/10/09 19:08:18 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "lemin.h"

int		show_error(t_options option, char *err)
{
	ft_putendl_fd("ERROR", 2);
	if (option.debug)
	{
		ft_putchar_fd('(', 1);
		ft_putstr_fd(err, 2);
		ft_putendl_fd(")", 1);
	}
	return (-1);
}
