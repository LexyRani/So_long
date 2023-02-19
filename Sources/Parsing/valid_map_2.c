/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:39:39 by aceralin          #+#    #+#             */
/*   Updated: 2023/02/19 16:49:03 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

int	is_not_rectangle(t_map **map)
{
	t_map	*tmp;

	tmp = *map;
	while (tmp && tmp->next)
	{
		if (ft_strlen(tmp->line) != ft_strlen(tmp->next->line))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	is_all_one( t_map *map)
{
	int	i;

	i = 0;
	while (map->line[i])
	{
		if (map->line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_middle(t_map *map)
{
	int	i;

	i = ft_strlen(map->line) - 1;
	if (map->line[0] == '1' && map->line[i] == '1')
		return (1);
	return (0);
}

int	is_not_wall_framed(t_map **map)
{
	int		y;
	t_map	*tmp;
	int		i;

	i = 0;
	y = ft_lstsize(*map);
	tmp = *map;
	while (tmp)
	{
		if (i == 0 || i == (y - 1))
		{
			if (is_all_one(tmp) == 0)
				return (1);
		}
		else
			if (!check_middle(tmp))
				return (1);
		i++;
		tmp = tmp->next;
	}
	return (0);
}
