/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslift <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 18:58:24 by sslift            #+#    #+#             */
/*   Updated: 2020/02/22 16:35:30 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct	s_tetramino
{
	char		*base[4];
	int			min_size;
	struct		s_tetramino *next;
	struct		s_tetramino *prev;
	int			order;
	int			pos;
}				t_tetramino;

t_tetramino		*ft_tetramino(int code);
void			fillit(int fd);
void			ft_if_error(void);
char			*ft_code(char *str);
t_tetramino		*ft_tetrabase(t_tetramino *tetra);
char			*ft_padding(const char *line, int size);
char			*ft_makeline(t_tetramino *tetra, int size);
int				ft_check(char *map, char *line, int pos);
void			ft_filloutputmap(t_tetramino *tetra, char **map, int size);
void			ft_fillmap(char *line, char **map, int pos);
void			ft_unfillmap(char *line, char **map, int pos);
int				ft_size(t_tetramino *tetra);

#endif
