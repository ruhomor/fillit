/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslift <sslift@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:40:43 by sslift            #+#    #+#             */
/*   Updated: 2019/09/12 13:44:18 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, char *s2)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (*(s2 + i) != '\0')
	{
		*(s1 + len + i) = *(s2 + i);
		i++;
	}
	*(s1 + len + i) = '\0';
	return (s1);
}
