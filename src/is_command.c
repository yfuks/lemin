/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 14:22:39 by yfuks             #+#    #+#             */
/*   Updated: 2017/10/03 14:33:39 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int		is_command(char *line)
{
	if (line && line[0] == '#' && line[1] == '#')
		return (1);
	return (0);
}
