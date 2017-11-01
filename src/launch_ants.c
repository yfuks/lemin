/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 15:01:30 by yfuks             #+#    #+#             */
/*   Updated: 2017/10/14 15:38:55 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "tools.h"

static void	print_moove(int ant_number, char *room_name)
{
	ft_putchar_fd('L', 1);
	ft_putnbr_fd(ant_number, 1);
	ft_putchar_fd('-', 1);
	ft_putstr_fd(room_name, 1);
	ft_putchar_fd(' ', 1);
}

void		launch_ants(int nb_ants, t_ant *ants)
{
	int		i;
	char	end;

	end = 0;
	while (!end)
	{
		end = 1;
		ft_putchar_fd('\n', 1);
		i = 0;
		while (i < nb_ants)
		{
			if (ants[i].c->next && ((ants[i].c->next->room->infos & IS_EMPTY)
									|| (!ants[i].c->next->next)))
			{
				if (!(ants[i].c->next->room->infos & IS_END))
					ants[i].c->next->room->infos = 0;
				if (!(ants[i].c->room->infos & IS_START))
					ants[i].c->room->infos = IS_EMPTY;
				end = 0;
				print_moove(i + 1, ants[i].c->next->room->name);
				ants[i].c = ants[i].c->next;
			}
			i++;
		}
	}
}
