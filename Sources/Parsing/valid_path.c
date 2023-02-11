/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:44:45 by aceralin          #+#    #+#             */
/*   Updated: 2023/02/11 21:10:33 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	ft_init_count(t_count	count)
{
	count.c = 0;
	count.e = 0;
	count.p = 0;
}

t_count	*is_what_kind(char tmp, t_map **map, t_count *count)
{
	if (tmp == 'P')
	{
		count->p++;
		if (count->p > 1)
			ft_exit(*map, "Error: map is not a valid path");
	}
	if (tmp == 'C')
		count->c++;
	if (tmp == 'E')
	{
		count->e++;
		if (count->e > 1)
			ft_exit(*map, "Error: map is not a valid path");
	}
	return (count);
}

void	is_not_valid_count(t_map **map, t_count *count)
{
	t_map	*tmp;
	int			i;

	tmp = *map;
	while (tmp)
	{
		i = 0;
		while (tmp->extract[i])
		{
			count = is_what_kind(tmp->extract[i], map, count);
			i++;
		}
		tmp = tmp->next;
	}
	if (count->c <= 0)
		ft_exit(*map, "Error: map is not a valid path");
	if (count->p == 0)
		ft_exit(*map, "Error: map is not a valid path");
	if (count->e == 0)
		ft_exit(*map, "Error: map is not a valid path");
}

int	change_c_to_p_i(t_map *map, t_count *count, int i, char c)
{
	int	check;

	check = 0;
	if (map->extract[i + 1] == c)
	{
		map->extract[i + 1] = 'P';
		if (c == 'C')
			count->c--;
		else if (c == 'E')
			count->e--;
		check++;
	}
	if (map->extract[i - 1] == c)
	{
		map->extract[i - 1] = 'P';
		if (c == 'C')
			count->c--;
		else if (c == 'E')
			count->e--;
		check++;
	}
	return (check);
}

int	change_c_to_p_np(t_map *map, t_count *count, int i, char c)
{
	int	check;

	check = 0;
	if (map->next->extract[i] == c)
	{
		map->next->extract[i] = 'P';
		if (c == 'C')
			count->c--;
		else if (c == 'E')
			count->e--;
		check++;
	}
	if (map->prev->extract[i] == c)
	{
		map->prev->extract[i] = 'P';
		if (c == 'C')
			count->c--;
		else if (c == 'E')
			count->e--;
		check++;
	}
	return (check);
}

int	change_nextp(t_map *map, t_count *count, int i)
{
	int	check;

	check = 0;
	check += change_c_to_p_i(map, count, i, 'C');
	check += change_c_to_p_np(map, count, i, 'C');
	check += change_c_to_p_i(map, count, i, 'E');
	check += change_c_to_p_np(map, count, i, 'E');
	check += change_c_to_p_i(map, count, i, '0');
	check += change_c_to_p_np(map, count, i, '0');
	if (check == 0)
		return (0);
	return (1);
}


char	*new_str(char *src)
{
	char	*new;
	int		i;

	i = ft_strlen(src);
	new = malloc(sizeof(char) * (i + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

t_map	*map_copy(t_game *game, t_map *src)
{
	t_map	*head;
	t_map	*map_cp;
	t_map	*prev;

	prev = src->prev;
	map_cp = malloc(sizeof(t_map));
	if (!map_cp)
		return (NULL);
	head = map_cp;
	game->head_map_cp = head;
	while (src)
	{
		map_cp->extract = new_str(src->extract);
		if (!src->next)
		{
			map_cp->next = NULL;
			map_cp->prev = prev;
			src = game->head_map;
			map_cp = head;
			return (map_cp);
		}
		map_cp->next = malloc(sizeof(t_map));
		if (!map_cp->next)
			return (0);
		map_cp->prev = prev;
		map_cp = map_cp->next;
		prev = src;
		src = src->next;
	}
	return (NULL);
}

int	is_not_valid_path(t_game *game, t_map **map, t_count *count)
{
	t_map	*tmp;
	int			i;
	int			change;

	// tmp = *map;
	tmp = map_copy(game, *map);
	while (tmp)
	{
		i = 0;
		while (tmp->extract[i])
		{
			if (tmp->extract[i] == 'P')
				change += change_nextp(tmp, count, i);
			i++;
		}
		if (count->c == 0 && count->e == 0)
			return (tmp = game->head_map_cp, free_map(tmp), 0);
		if (tmp->next == NULL)
		{
			if (change == 0)
				return (tmp = game->head_map_cp, free_map(tmp), 1);
			else
				change = 0;
			tmp = *map;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
		}
		tmp = tmp->next;
	}
	return (tmp = game->head_map_cp, free_map(tmp), 0);
}

/*
static void print_for_debug(t_solong **map, t_map *count)
{
	t_solong *tmp;
	
	tmp = *map;
	printf("--------------------\n");
	while (tmp)
	{
		printf("%s\n", tmp->extract);

		tmp = tmp->next;
		
	}
	printf("ce = %d cc = %d\n", count->e, count->c);
	printf("--------------------\n");
}*/
