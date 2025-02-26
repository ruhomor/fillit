/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:17:04 by kachiote          #+#    #+#             */
/*   Updated: 2020/02/24 19:29:56 by kachiote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 64
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef	struct		s_ldb
{
	int				fd;
	char			*cut;
	struct s_ldb	*next;
}					t_ldb;

t_ldb				*create_db(const int fd);
char				*search_n(char **n, char *cut);
int					read_line(const int fd, char **line, char *cut);
t_ldb				*search_db(t_ldb *db, const int fd);
int					get_next_line(const int fd, char **line);

#endif
