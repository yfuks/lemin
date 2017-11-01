/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 14:49:48 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/01 17:17:23 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# define BUFF_SIZE 256

# include <stdlib.h>

int				ft_strlen(const char *str);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *str, int fd);
void			ft_putendl_fd(char *str, int fd);
void			ft_putnbr_fd(long long int nbr, int fd);
int				ft_get_line(char **line);
int				get_next_line(int const fd, char **line);
char			*ft_strnew(char *str);
char			*ft_strnew_size(size_t size);
char			*ft_strconcat(char *str1, char *str2);
char			*ft_strchr(char *str, char c);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
void			ft_bzero(void *s, size_t n);
int				ft_atoi(char *str);
int				ft_isspace(char c);
int				ft_isdigit(char c);
int				ft_strcmp(const char *s1, const char *s2);
char			**ft_stradd(char **tab, char *str);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strdup(const char *s);
char			*ft_strndup(const char *s, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);

typedef	struct	s_gl
{
	char		*buff_start;
	char		*buff_current;
}				t_gl;

typedef struct	s_names
{
	char			*name;
	struct s_names	*next;
}				t_names;

#endif
