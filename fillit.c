/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslift <sslift@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 20:35:57 by sslift            #+#    #+#             */
/*   Updated: 2020/02/22 18:12:00 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int ft_mainsearch(t_tetramino *tetra, char **map, int size)
{
	char *line;

	if (!tetra)
		return (1);
	line = ft_makeline(tetra, size);
	while (1)
	{
		tetra->pos++;
		if (tetra->pos + ft_strlen(line) > ft_strlen(*map))
		{
			free(line);
			return (0);
		}
		if (ft_check(*map, line, tetra->pos))
		{
			ft_fillmap(line, map, tetra->pos);
			if (!ft_mainsearch(tetra->next, map, size))
			{
				ft_unfillmap(line, map, tetra->pos);
				tetra->next->pos = -1;
				continue;
			} else
				return (1);
		}
	}
}

char *ft_makemap(int size)
{
	char *map;
	int i;
	int j;

	i = 0;
	map = ft_strnew((size + 1) * size + 1);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			*(map + i * (size + 1) + j) = '0';
			j++;
		}
		*(map + i * (size + 1) + j) = '1';
		i++;
	}
	return (map);
}


void fillit(int fd)
{
	char *line;
	char *code;
	char *t;
	t_tetramino *tetra;
	t_tetramino *tmp;
	int n;
	int j;
	int gnl;
	int size;

	code = ft_strnew(20);
	t = code;
	n = 0;
	j = 0;
	while (1)
	{
		if ((gnl = get_next_line(fd, &line)) >= 0)
		{
			if (j < 4)
			{
				code = ft_strcat(code, line);
				if (ft_strlen(line) != 4)
					ft_if_error();
				code = ft_strcat(code, ft_strdup("0"));
				j++;
				if (gnl == 0)
					ft_if_error();
			} else if (j == 4)
			{
				n++;
				code = ft_code(code);
				code = ft_strtrimchr(code, '0');
				if (!tetra)
				{
					tetra = ft_tetramino(ft_frombistringtointeger(code));
					tetra->order = 1;
				} else
				{
					tetra->next = ft_tetramino(ft_frombistringtointeger(code));
					tmp = tetra;
					tetra = tetra->next;
					tetra->prev = tmp;
					tetra->order = tetra->prev->order + 1;
				}
				free(code);
				if (tetra->min_size == -5)
					ft_if_error();
				code = ft_strnew(20);
				if (gnl > 0)
				{
					j = 0;
					if (ft_strcmp(line, "") != 0 || gnl <= 0)
						ft_if_error();
				} else
					break ;
			}

		} else if (gnl < 0)
			ft_if_error();
	}

	tetra = ft_tetrabase(tetra);
	size = 1;
	size = ft_max(size, tetra->min_size);
	while (tetra->next)
	{
		tetra = tetra->next;
		size = ft_max(size, tetra->min_size);
	}
	size = ft_max(size, ft_sqrt(n * 4));

	char *map;
	tetra = ft_tetrabase(tetra);
	while (1)
	{
		map = ft_makemap(size);
		if (ft_mainsearch(tetra, &map, size))
			break;
		tetra->pos = -1;
		size++;
		free(map);
	}

	free(map);
	map = ft_makemap(size);
	ft_filloutputmap(tetra, &map, size);
	ft_putstr(map);
	free(map);
}
