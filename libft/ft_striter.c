/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslift <sslift@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 01:20:13 by sslift            #+#    #+#             */
/*   Updated: 2020/02/21 21:27:19 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	size_t i;

	i = 0;
	if (s && f)
	{
		while (i < ft_strlen(s))
		{
			f(s + i);
			i++;
		}
	}
}
