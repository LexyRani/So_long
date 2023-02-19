/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 23:07:05 by aceralin          #+#    #+#             */
/*   Updated: 2023/02/19 23:49:17 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	to_up(char **map, t_count *count, t_coord *coor, char c)
{
	map[coor->y - 1][coor->x] = 'P';
	if (c == 'C')
		count->c--;
	else if (c == 'E')
		count->e--;
}

void	to_down(char **map, t_count *count, t_coord *coor, char c)
{
	map[coor->y + 1][coor->x] = 'P';
	if (c == 'C')
		count->c--;
	else if (c == 'E')
		count->e--;
}

void	to_right(char **map, t_count *count, t_coord *coor, char c)
{
	map[coor->y][coor->x + 1] = 'P';
	if (c == 'C')
		count->c--;
	else if (c == 'E')
		count->e--;
}

void	to_left(char **map, t_count *count, t_coord *coor, char c)
{
	map[coor->y][coor->x - 1] = 'P';
	if (c == 'C')
		count->c--;
	else if (c == 'E')
		count->e--;
}

int	charset_to_p(char **map, t_count *count, t_coord *coor, char c)
{
	int	check;

	check = 0;
	if (map[coor->y - 1][coor->x] == c)
	{
		to_up(map, count, coor, c);
		check++;
	}
	if (map[coor->y + 1][coor->x] == c)
	{
		to_down(map, count, coor, c);
		check++;
	}
	if (map[coor->y][coor->x - 1] == c)
	{
		to_left(map, count, coor, c);
		check++;
	}
	if (map[coor->y][coor->x + 1] == c)
	{
		to_right(map, count, coor, c);
		check++;
	}
	return (check);
}
