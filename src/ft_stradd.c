/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 17:06:52 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/01 16:55:24 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tools.h"

char		**ft_stradd(char **tab, char *str)
{
	int		i;
	int		old_lenght;
	char	**new_tab;

	old_lenght = 0;
	while (tab[old_lenght])
		old_lenght++;
	if (!(new_tab = (char **)malloc(sizeof(char *) * (old_lenght + 4))))
		return (0);
	i = 0;
	while (i < old_lenght)
	{
		new_tab[i] = tab[i];
		i++;
	}
	new_tab[i] = ft_strnew(str);
	new_tab[i + 1] = NULL;
	free(tab);
	return (new_tab);
}
