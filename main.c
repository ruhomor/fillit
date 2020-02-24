/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslift <sslift@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 21:04:21 by sslift            #+#    #+#             */
/*   Updated: 2020/02/21 21:27:19 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int argc, char **argv)
{
	if (argc < 0 && !argv)
	    return (0);
	int fd = 0;
	fd = open(argv[1], O_RDONLY);
	//fd = open("test02", O_RDONLY);
	//printf("Suka");
	fillit(fd);
	return (0);
}