/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strconcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 15:39:54 by yfuks             #+#    #+#             */
/*   Updated: 2017/10/02 16:39:13 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tools.h"

char		*ft_strconcat(char *str1, char *str2)
{
	int		len;
	int		i;
	int		j;
	char	*concat;

	len = ft_strlen(str1) + ft_strlen(str2) + 1;
	if (!len || !str1 || !str2)
		return (NULL);
	i = 0;
	j = 0;
	concat = (char*)malloc(sizeof(char) * len);
	while (i < ft_strlen(str1))
	{
		concat[i] = str1[i];
		i++;
	}
	while (j < ft_strlen(str2))
	{
		concat[i] = str2[j];
		j++;
		i++;
	}
	concat[i] = 0;
	return (concat);
}
