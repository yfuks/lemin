/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 14:14:13 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/01 17:01:50 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "tools.h"
#include <unistd.h>

int		main(int ac, char **av)
{
	t_path_list			*path_list;
	t_options			options;
	t_fuck_norme_two	n;

	parse_arguments(ac, av, &options);
	n.nb_ants = 0;
	n.rooms = NULL;
	n.in_connection = 0;
	if (!(n.rooms = parse_stdin(&n)))
		return (show_error(options, "Map not well formated"));
	if (!(n.nb_ants))
		return (show_error(options, "Number of ant not valid"));
	if (!(check_parse(&n.rooms)))
		return (show_error(options, "Map logic broken"));
	if (!(path_list = get_path_list(&n.rooms)))
		return (show_error(options, "Can't found any path"));
	remove_bad_paths(&path_list);
	if (!path_list)
		return (show_error(options, "Can't found any good path"));
	remove_overlap_paths(&path_list);
	print_lemin(&path_list, &options);
	moove_ants(n.nb_ants, &path_list, &n.rooms);
	free_rooms(&n.rooms);
	free_paths(&path_list);
	return (0);
}
