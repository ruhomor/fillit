/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetraminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslift <sslift@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 20:36:20 by sslift            #+#    #+#             */
/*   Updated: 2020/02/17 20:36:20 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetramino *ft_tetramino(int code)
{
	t_tetramino *tetramino;

	tetramino = (t_tetramino *) malloc(sizeof(t_tetramino));
	if (code == 99)
		*tetramino = (t_tetramino) {.base = {"11", "11", "0", "0"}, .min_size = 2, .next = NULL, .pos = -1};
	else if (code == 2145)
		*tetramino = (t_tetramino) {.base = {"1", "11", "01", "0"}, .min_size = 3, .next = NULL, .pos = -1};
	else if (code == 561)
		*tetramino = (t_tetramino) {.base = {"01", "11", "1", "0"}, .min_size = 3, .next = NULL, .pos = -1};
	else if (code == 51)
		*tetramino = (t_tetramino) {.base = {"011", "11", "0", "0"}, .min_size = 3, .next = NULL, .pos = -1};
	else if (code == 195)
		*tetramino = (t_tetramino) {.base = {"11", "011", "0", "0"}, .min_size = 3, .next = NULL, .pos = -1};
	else if (code == 2115)
		*tetramino = (t_tetramino) {.base = {"1", "1", "11", "0"}, .min_size = 3, .next = NULL, .pos = -1};
	else if (code == 1059)
		*tetramino = (t_tetramino) {.base = {"01", "01", "11", "0"}, .min_size = 3, .next = NULL, .pos = -1};
	else if (code == 57)
		*tetramino = (t_tetramino) {.base = {"111", "1", "0", "0"}, .min_size = 3, .next = NULL, .pos = -1};
	else if (code == 225)
		*tetramino = (t_tetramino) {.base = {"111", "001", "0", "0"}, .min_size = 3, .next = NULL, .pos = -1};
	else if (code == 39)
		*tetramino = (t_tetramino) {.base = {"001", "111", "0", "0"}, .min_size = 3, .next = NULL, .pos = -1};
	else if (code == 135)
		*tetramino = (t_tetramino) {.base = {"1", "111", "0", "0"}, .min_size = 3, .next = NULL, .pos = -1};
	else if (code == 3105)
		*tetramino = (t_tetramino) {.base = {"11", "01", "01", "0"}, .min_size = 3, .next = NULL, .pos = -1};
	else if (code == 1569)
		*tetramino = (t_tetramino) {.base = {"11", "1", "1", "0"}, .min_size = 3, .next = NULL, .pos = -1};
	else if (code == 33825)
		*tetramino = (t_tetramino) {.base = {"1", "1", "1", "1"}, .min_size = 4, .next = NULL, .pos = -1};
	else if (code == 15)
		*tetramino = (t_tetramino) {.base = {"1111", "0", "0", "0"}, .min_size = 4, .next = NULL, .pos = -1};
	else if (code == 113)
		*tetramino = (t_tetramino) {.base = {"111", "01", "0", "0"}, .min_size = 3, .next = NULL, .pos = -1};
	else if (code == 71)
		*tetramino = (t_tetramino) {.base = {"01", "111", "0", "0"}, .min_size = 3, .next = NULL, .pos = -1};
	else if (code == 1073)
		*tetramino = (t_tetramino) {.base = {"1", "11", "1", "0"}, .min_size = 3, .next = NULL, .pos = -1};
	else if (code == 1121)
		*tetramino = (t_tetramino) {.base = {"01", "11", "01", "0"}, .min_size = 3, .next = NULL, .pos = -1};
	return (tetramino);
}