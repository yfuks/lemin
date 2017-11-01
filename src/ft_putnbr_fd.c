/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 15:58:22 by yfuks             #+#    #+#             */
/*   Updated: 2017/10/03 16:02:31 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void		ft_putnbr_fd(long long int nbr, int fd)
{
	unsigned long long int	uin;

	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		uin = (unsigned long long int)-nbr;
	}
	else
		uin = (unsigned long long int)nbr;
	if (uin >= 10)
		ft_putnbr_fd(uin / 10, fd);
	ft_putchar_fd(uin % 10 + '0', fd);
}
