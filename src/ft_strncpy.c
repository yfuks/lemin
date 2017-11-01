/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alansiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 16:31:16 by alansiva          #+#    #+#             */
/*   Updated: 2017/10/31 16:59:31 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*temp;

	temp = dst;
	while (*src != '\0' && len > 0)
	{
		*dst = *src;
		dst++;
		src++;
		len--;
	}
	while (len > 0)
	{
		*dst = '\0';
		dst++;
		len--;
	}
	return (temp);
}
