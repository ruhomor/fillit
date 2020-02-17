/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslift <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 18:58:24 by sslift            #+#    #+#             */
/*   Updated: 2020/01/13 18:58:46 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

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

#endif
