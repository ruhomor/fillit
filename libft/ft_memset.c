/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslift <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:02:16 by sslift            #+#    #+#             */
/*   Updated: 2019/09/14 23:15:59 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int c, size_t count)
{
	size_t			i;
	unsigned char	*tmp;

	tmp = (unsigned char *)buf;
	i = 0;
	while (i < count)
	{
		*(tmp + i) = c;
		i++;
	}
	return (tmp);
}
