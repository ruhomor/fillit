/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_support_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslift <sslift@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:22:13 by sslift            #+#    #+#             */
/*   Updated: 2020/02/22 17:46:41 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_if_error(void)
{
	ft_putstr_fd("error\n", 1);
	exit(0);
}

char		*ft_code(char *str)
{
	int		i;
	char	*code;

	i = 0;
	code = ft_strnew(ft_strlen(str));
	while (*(str + i) != '\0')
	{
		if (*(str + i) == '.')
			*(code + i) = '0';
		else if (*(str + i) == '#')
			*(code + i) = '1';
		else
			*(code + i) = *(str + i);
		i++;
	}
	return (code);
}

t_tetramino	*ft_tetrabase(t_tetramino *tetra)
{
	while (tetra->order != 1)
		tetra = tetra->prev;
	return (tetra);
}

char		*ft_padding(const char *line, int size)
{
	char	*str;
	size_t	len;
	size_t	i;

	str = ft_strnew(size + 1);
	len = ft_strlen(line);
	i = 0;
	while (i < len)
	{
		*(str + i) = *(line + i);
		i++;
	}
	while (i < (size_t)size + 1)
	{
		*(str + i) = '0';
		i++;
	}
	return (str);
}

char		*ft_makeline(t_tetramino *tetra, int size)
{
	char *line;
	char *tmp;

	line = ft_strnew(4 * (size + 1));
	tmp = ft_padding(tetra->base[0], size);
	line = ft_strcat(line, tmp);
	free(tmp);
	tmp = ft_padding(tetra->base[1], size);
	line = ft_strcat(line, tmp);
	free(tmp);
	tmp = ft_padding(tetra->base[2], size);
	line = ft_strcat(line, tmp);
	free(tmp);
	tmp = ft_padding(tetra->base[3], size);
	line = ft_strcat(line, tmp);
	free(tmp);
	tmp = line;
	line = ft_strtrimchrcond(line, '0', 0, 1);
	free(tmp);
	return (line);
}
