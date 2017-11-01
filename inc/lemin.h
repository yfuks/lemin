/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 14:48:42 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/01 16:59:06 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# define STD_IN	0

# define IS_START	(1 << 0)
# define IS_END		(1 << 1)
# define IS_EMPTY	(1 << 2)

typedef	struct			s_room
{
	char				*name;
	int					cor_x;
	int					cor_y;
	char				infos;
	int					nb_ants;
	char				**connections;
	struct s_room		*next;
}						t_room;

typedef struct			s_path
{
	int					length;
	t_room				*room;
	struct s_path		*next;
}						t_path;

typedef struct			s_path_list
{
	t_path				*path;
	struct s_path_list	*next;
}						t_path_list;

typedef struct			s_options
{
	char				debug;
}						t_options;

typedef struct			s_ant
{
	t_path				*c;
}						t_ant;

typedef struct			s_two_path
{
	t_path				*path1;
	t_path				*path2;
}						t_two_path;

typedef struct			s_fuck_norme
{
	t_path				*tmp;
	t_room				*room;
	char				room_added;
}						t_fuck_norme;

typedef struct			s_fuck_norme_two
{
	int					nb_ants;
	char				*line;
	t_room				*rooms;
	char				in_connection;
}						t_fuck_norme_two;

int						parse_arguments(int ac, char **av, t_options *options);
int						show_error(t_options option, char *err);
t_room					*parse_stdin(t_fuck_norme_two *n);
int						check_parse(t_room **rooms);

int						is_nb_ants(char *line);
int						is_command(char *line);
int						is_room(char *line);
int						is_connection(char *line, t_room **rooms);
int						is_commentary(char *line);

char					*get_room_name(char *line);

int						add_command(char *line, t_room **rooms);
int						add_connection(char *line, t_room **rooms);
int						add_room(char *line, t_room **rooms, char infos);

t_room					*get_room_by_name(char *name, t_room **rooms);
t_room					*new_room(void);
t_room					*get_start_room(t_room **rooms);

void					print_lemin(t_path_list **list, t_options *opts);
void					print_connections(t_room **rooms);
void					print_paths(t_path_list **list);
void					print_path(t_path **path);

t_path_list				*get_path_list(t_room **rooms);
int						is_room_in_path(t_path **path, char *room_name);
t_path					*new_path(t_room *room);
t_path_list				*new_path_list(t_path *path);
t_path					*copy_path(t_path **path);
int						add_room_in_path(t_path **path, t_room *room);
void					free_path(t_path **path);
int						add_paths(t_path_list **list, t_room **rooms);
int						add_path_in_list(t_path_list **list, t_path *path);
int						create_path(t_path_list **list, t_path **path,
									t_room **rooms);
void					remove_overlap_paths(t_path_list **list);
void					remove_bad_paths(t_path_list **list);
void					moove_ants(int nb_ants, t_path_list **list,
								t_room **rooms);
int						get_path_length(t_path **path);
void					multi_road(int nb_ants, t_path_list **list);
void					launch_ants(int nb_ants, t_ant *ants);
void					free_rooms(t_room **rooms);
void					free_paths(t_path_list **paths);

#endif
