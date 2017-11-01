/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alansiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 19:00:02 by alansiva          #+#    #+#             */
/*   Updated: 2017/10/31 17:00:32 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*ptr;

	if (s1 && s2)
	{
		str = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (str)
		{
			ptr = str;
			while (*s1)
				*ptr++ = *s1++;
			while (*s2)
				*ptr++ = *s2++;
			*ptr = '\0';
			return (str);
		}
		else
			return (NULL);
	}
	else
		return (NULL);
}
