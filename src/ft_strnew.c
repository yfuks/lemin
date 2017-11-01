/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 15:25:47 by yfuks             #+#    #+#             */
/*   Updated: 2017/10/02 17:26:01 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tools.h"

char	*ft_strnew(char *str)
{
	char	*new;
	int		str_len;
	int		i;

	str_len = ft_strlen(str) + 1;
	new = (char*)malloc(sizeof(char) * str_len);
	if (!new)
		return (NULL);
	i = 0;
	while (i < str_len)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = 0;
	return (new);
}
