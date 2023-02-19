/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:44:45 by aceralin          #+#    #+#             */
/*   Updated: 2023/02/20 00:07:00 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

/*void	print_double_array(char **array)
{
	int	i;

	i = 0;
	if (!*array)
		return;
	while (array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}
}*/

int	is_not_valid_count(t_map **map, t_count *count)
{
	t_map	*tmp;
	int		i;

	tmp = *map;
	while (tmp)
	{
		i = 0;
		while (tmp->line[i])
		{
			if (!is_what_kind(tmp->line[i], count))
				return (1);
			i++;
		}
		tmp = tmp->next;
	}
	printf("%d\n", count->c);
	if (count->c <= 0 || count->p == 0 || count->e == 0)
		return (1);
	return (0);
}

int	change_nextp(char **map, t_count *count, t_coord *coor)
{
	int	check;

	check = 0;
	check += charset_to_p(map, count, coor, 'C');
	check += charset_to_p(map, count, coor, 'E');
	check += charset_to_p(map, count, coor, '0');
	if (check == 0)
		return (0);
	return (1);
}

static int	valid_map(t_count *count)
{
	if (count->c == 0 && count->e == 0)
		return (0);
	return (1);
}

int	while_map( char **map, t_count *count)
{
	int			change;
	t_coord		coor;

	change = 0;
	coor.y = 0;
	while (map[coor.y])
	{
		coor.x = 0;
		while (map[coor.y][coor.x] != '\0')
		{
			if (map[coor.y][coor.x] == 'P')
			change += change_nextp(map, count, &coor);
			coor.x++;
		}
		coor.y++;
	}
	return (change);
}

int	is_not_valid_path(t_game *game, t_map **map, t_count *count)
{
	char			**map_created;
	int				change;

	change = 0;
	game->map_game = make_array_chain(map);
	if (!game->map_game)
		return (1);
	map_created = copy_array(game->map_game, map);
	if (!map_created)
		return (1);
	while (valid_map(count))
	{
		change = while_map(map_created, count);
		if (change == 0)
		{
			ft_free_double_tab(map_created);
			return (1);
		}
		else
			change = 0;
	}
	ft_free_double_tab(map_created);
	return (0);
}
