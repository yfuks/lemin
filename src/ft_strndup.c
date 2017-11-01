/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alansiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 15:23:49 by alansiva          #+#    #+#             */
/*   Updated: 2017/11/01 17:15:14 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*tmp;

	if (!(tmp = ft_strnew_size(n)))
		return (NULL);
	ft_strncpy(tmp, s, n);
	return (tmp);
}
