/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_support_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslift <sslift@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:33:52 by sslift            #+#    #+#             */
/*   Updated: 2020/02/22 16:42:47 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check(char *map, char *line, int pos)
{
	size_t i;

	i = 0;
	while (i < ft_strlen(line))
	{
		if (*(line + i) == '1')
		{
			if (*(map + pos + i) != '0')
				return (0);
		}
		i++;
	}
	return (1);
}

void	ft_filloutputmap(t_tetramino *tetra, char **map, int size)
{
	char	*line;
	size_t	i;
	char	c;

	while (tetra)
	{
		line = ft_makeline(tetra, size);
		i = -1;
		c = tetra->order + 'A' - 1;
		while (++i < ft_strlen(line))
		{
			if (*(line + i) == '1')
				*(*map + tetra->pos + i) = c;
		}
		tetra = tetra->next;
		free(line);
	}
	i = -1;
	while (++i < ft_strlen(*map))
	{
		if (*(*map + i) == '0')
			*(*map + i) = '.';
		else if (*(*map + i) == '1')
			*(*map + i) = '\n';
	}
}

void	ft_fillmap(char *line, char **map, int pos)
{
	size_t i;

	i = 0;
	while (i < ft_strlen(line))
	{
		if (*(line + i) == '1')
			*(*map + pos + i) = '1';
		i++;
	}
}

void	ft_unfillmap(char *line, char **map, int pos)
{
	size_t i;

	i = 0;
	while (i < ft_strlen(line))
	{
		if (*(line + i) == '1')
			*(*map + pos + i) = '0';
		i++;
	}
}
