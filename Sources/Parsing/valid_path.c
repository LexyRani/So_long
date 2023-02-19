/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:44:45 by aceralin          #+#    #+#             */
/*   Updated: 2023/02/19 18:30:53 by aceralin         ###   ########.fr       */
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

int	is_what_kind(char tmp, t_count *count)
{
	if (tmp == 'P')
	{
		count->p++;
		if (count->p > 1)
			return (0);
	}
	if (tmp == 'C')
		count->c++;
	if (tmp == 'E')
	{
		count->e++;
		if (count->e > 1)
			return (0);
	}
	return (1);
}

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

static int	charset_to_p(char **map, t_count *count, t_coordinate *coor, char c)
{
	int	check;

	check = 0;
	if (map[coor->y - 1][coor->x] == c)
	{
		map[coor->y - 1][coor->x] = 'P';
		if (c == 'C')
			count->c--;
		else if (c == 'E')
			count->e--;
		check++;
	}
	if (map[coor->y + 1][coor->x] == c)
	{
		map[coor->y + 1][coor->x] = 'P';
		if (c == 'C')
			count->c--;
		else if (c == 'E')
			count->e--;
		check++;
	}
	if (map[coor->y][coor->x - 1] == c)
	{
		map[coor->y][coor->x - 1] = 'P';
		if (c == 'C')
			count->c--;
		else if (c == 'E')
			count->e--;
		check++;
	}
	if (map[coor->y][coor->x + 1] == c)
	{
		map[coor->y][coor->x + 1] = 'P';
		if (c == 'C')
			count->c--;
		else if (c == 'E')
			count->e--;
		check++;
	}
	return (check);
}

int	change_nextp(char **map, t_count *count, t_coordinate *coor)
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

static void	ft_free_double_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free (tab[i]);
		i++;
	}
	free (tab);
}

static char	**make_array_chain(t_map **map)
{
	char	**new_array;
	int		len;
	t_map	*tmp;
	int		i;

	tmp = *map;
	len = 0;
	i = 0;
	//if (!*map)//verifier
		//return (NULL);
	len = ft_lstsize(tmp);
	new_array = (char **)malloc(sizeof(char *) * (len + 1));
	if (!new_array)
		return (NULL);
	while (i < len)
	{
		new_array[i] = ft_strdup_without_nl(tmp->line);
		i++;
		tmp = tmp->next;
	}
	new_array[i] = NULL;
	return (new_array);
}

char	**copy_array(char **array, t_map **map)
{
	char	**new_array;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!array)
		return (NULL);
	len = ft_lstsize(*map);
	new_array = (char **)malloc(sizeof(char *) * (len + 1));
	if (!new_array)
		return (NULL);
	while (i < len)
	{
		new_array[i] = ft_strdup_without_nl(array[i]);
		if (!new_array[i])
		{
			ft_free_double_tab(new_array);
			return (NULL);
		}
		i++;
	}
	new_array[i] = NULL;
	return (new_array);
}

static int	valid_map(t_count *count)
{
	if (count->c == 0 && count->e == 0)
		return (0);
	return (1);
}

int	is_not_valid_path(t_game *game, t_map **map, t_count *count)
{
	char			**map_created;
	t_coordinate	coor;
	int				change;

	coor.y = 0;
	coor.x = 0;
	change = 0;
	game->map_game = make_array_chain(map);
	if (!game->map_game)
		return (1);
	map_created = copy_array(game->map_game, map);
	if (!map_created)
		return (1);
	while (valid_map(count))
	{
		coor.y = 0;
		while (map_created[coor.y])
		{
			coor.x = 0;
			while (map_created[coor.y][coor.x] != '\0')
			{
				if (map_created[coor.y][coor.x] == 'P')
				{
					change += change_nextp(map_created, count, &coor);
				}	
				coor.x++;
			}
			coor.y++;
		}
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
