/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslift <sslift@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 04:38:20 by sslift            #+#    #+#             */
/*   Updated: 2019/09/14 23:38:49 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t count)
{
	size_t			i;
	unsigned char	*tmp;
	unsigned char	*tmp_src;

	tmp = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	i = 0;
	if ((tmp == NULL) && (tmp_src == NULL))
		return (NULL);
	while (i < count)
	{
		*(tmp + i) = *(tmp_src + i);
		i++;
	}
	return (tmp);
}
