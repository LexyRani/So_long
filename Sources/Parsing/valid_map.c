/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:27:43 by aceralin          #+#    #+#             */
/*   Updated: 2023/02/18 19:38:02 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

int	is_not_rectangle(t_map **map)
{
	t_map *tmp;

	tmp = *map;
	while (tmp && tmp->next)
	{
		if(ft_strlen(tmp->line) != ft_strlen(tmp->next->line))
			return (1);
		tmp = tmp->next;
	}
	return(0);
}

int	is_all_one( t_map *map)
{
	int i;
	i = 0;
	while(map->line[i])
	{
		if(map->line[i] != '1')
			return(0);
		i++;
	}
	return(1);
}

int	check_middle(t_map *map)
{
	int	i;

	i = ft_strlen(map->line) - 1;
	if(map->line[0] == '1' && map->line[i] == '1')
		return(1);
	return(0);
}

int	is_not_wall_framed(t_map **map)
{
	int	y;
	t_map *tmp;
	int i;
	
	i = 0;
	y = ft_lstsize(*map);
	tmp = *map;
	while (tmp)
	{
		if(i == 0 || i == (y - 1))
		{
			if(is_all_one(tmp) == 0)
				return(1);
		}
		else
			if(!check_middle(tmp))
				return(1);
		i++;
		tmp = tmp->next;
	}
	return(0);
}

// static int	valid_char(char c)
// {
// 	if (c == '0' || c == 'E' || c == '1' || c == 'C' || c == 'P')
// 		return (0);
// 	return (1);
// }

int	is_bad_char(t_map **map)
{
	t_map	*tmp;
	int		i;

	tmp = *map;	
	while(tmp)
	{
		i = 0;
		while(tmp->line[i])
		{	
			if(tmp->line[i] != '0' && tmp->line[i] != 'E' &&
				 tmp->line[i] != '1' && tmp->line[i] != 'C' &&
				 tmp->line[i] != 'P')
			{
				printf("%d\n", tmp->line[i]);
				return(1);	
			}
			// if(valid_char(tmp->line[i]))
			// {
			// 	printf("here %d\n", tmp->line[i]);
			// 	return(1);	
			// }
			i++;
		}
		tmp = tmp->next;
	}
	return(0);
	
}

void	ft_map_is_valid(t_game *game, t_map **map)
{
	t_count  count;

	count.c = 0;
	count.e = 0;
	count.p = 0;
	if(*map == NULL)
		ft_exit(NULL, NULL, "Error: map is empty");
	if(is_not_rectangle(map))
		ft_exit(*map, game, "Error: map is not rectangle");
	if(is_not_wall_framed(map))
	 	ft_exit(*map, game,"Error: map is missing wall");
	if(is_bad_char(map))
		ft_exit(*map, game, "Error: char must be 0, 1, E, P, C");
	if(is_not_valid_count(map, &count))
		ft_exit(*map, game, "Error: map is not a valid path");
	if(is_not_valid_path(game, map, &count))
		ft_exit(*map, game, "Error: map is not a valid path");
}

/*printf("-----------\n");
		print_map(*map);
		printf("-----------\n");*/