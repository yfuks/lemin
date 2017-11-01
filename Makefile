#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/02 13:22:33 by yfuks             #+#    #+#              #
#    Updated: 2017/11/01 17:17:45 by yfuks            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# EXECUTABLE
NAME	:= lem-in

# COMPILATION
CC		:= clang
FLAGS	:= -Wall -Wextra -Werror -g3

# DIRECTORY
SRCDIR	:= src/
INCDIR	:= inc/
OBJDIR	:= obj/

# FILES
SRCS	:= $(SRCDIR)main.c \
			$(SRCDIR)ft_putchar_fd.c \
			$(SRCDIR)ft_putendl_fd.c \
			$(SRCDIR)ft_putstr_fd.c \
			$(SRCDIR)ft_strlen.c  \
			$(SRCDIR)ft_strnew.c  \
			$(SRCDIR)ft_strnew_new.c  \
			$(SRCDIR)ft_get_line.c \
			$(SRCDIR)ft_strconcat.c \
			$(SRCDIR)ft_strchr.c \
			$(SRCDIR)show_error.c \
			$(SRCDIR)parse_stdin.c \
			$(SRCDIR)ft_atoi.c	\
			$(SRCDIR)ft_isspace.c \
			$(SRCDIR)ft_isdigit.c \
			$(SRCDIR)is_nb_ants.c \
			$(SRCDIR)ft_strcmp.c \
			$(SRCDIR)is_command.c \
			$(SRCDIR)is_room.c \
			$(SRCDIR)is_commentary.c \
			$(SRCDIR)is_connection.c \
			$(SRCDIR)get_room_by_name.c \
			$(SRCDIR)new_room.c \
			$(SRCDIR)add_room.c \
			$(SRCDIR)add_command.c \
			$(SRCDIR)ft_putnbr_fd.c \
			$(SRCDIR)add_connection.c \
			$(SRCDIR)ft_stradd.c \
			$(SRCDIR)print_lemin.c \
			$(SRCDIR)check_parse.c \
			$(SRCDIR)print_connections.c \
			$(SRCDIR)get_path_list.c \
			$(SRCDIR)get_start_room.c \
			$(SRCDIR)new_path.c \
			$(SRCDIR)copy_path.c \
			$(SRCDIR)add_room_in_path.c \
			$(SRCDIR)new_path_list.c \
			$(SRCDIR)free_path.c \
			$(SRCDIR)add_path_in_list.c \
			$(SRCDIR)is_room_in_path.c \
			$(SRCDIR)print_paths.c \
			$(SRCDIR)create_path.c \
			$(SRCDIR)print_path.c \
			$(SRCDIR)remove_overlap_paths.c \
			$(SRCDIR)remove_bad_paths.c \
			$(SRCDIR)parse_options.c \
			$(SRCDIR)moove_ants.c \
			$(SRCDIR)get_path_length.c \
			$(SRCDIR)multi_road.c \
			$(SRCDIR)launch_ants.c \
			$(SRCDIR)free_rooms.c \
			$(SRCDIR)free_paths.c \
			$(SRCDIR)get_room_name.c \
			$(SRCDIR)get_next_line.c \
			$(SRCDIR)ft_strjoin.c \
			$(SRCDIR)ft_strdup.c \
			$(SRCDIR)ft_strsub.c \
			$(SRCDIR)ft_strndup.c \
			$(SRCDIR)ft_strcpy.c \
			$(SRCDIR)ft_strncpy.c \
			$(SRCDIR)ft_bzero.c

OBJS	:= $(SRCS:$(SRCDIR)%.c=$(OBJDIR)%.o)

# BIN
RM		:= /bin/rm -rf

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS)
		@$(CC) $(FLAGS) $(OBJS) -o $@ -I./$(INCDIR)
		@echo "[\033[1;32m√\033[m]" $@

$(OBJDIR)%.o: $(SRCDIR)%.c
			@$(CC) $(FLAGS) -c $< -o $@ -I./$(INCDIR)
			@echo "[\033[1;32m√\033[m]" $@

$(OBJDIR):
		@mkdir -p $(OBJDIR)

clean:
	$(RM) $(OBJDIR)

fclean:
	$(RM) $(NAME)
	$(RM) $(OBJDIR)

re: fclean 
	@$(MAKE) all