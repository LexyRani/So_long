/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:27:43 by aceralin          #+#    #+#             */
/*   Updated: 2023/02/01 02:07:15 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

int	is_not_rectangle(t_solong **map)
{
	t_solong *tmp;
	
	tmp = *map;
	while (tmp->next)
	{
		if(ft_strlen(tmp->extract) != ft_strlen(tmp->next->extract))
			return (1);
		tmp = tmp->next;	
	}
	return(0);
}

int	is_all_one( t_solong *map)
{
	int i;
	i = 0;
	printf("%s\n", map->extract);
	while(map->extract[i])
	{
		if(map->extract[i] != '1')
			return(0);
		i++;
	}
	return(1);
}

int	check_middle(t_solong *map)
{
	int	i;

	i = ft_strlen(map->extract) - 1;
	if(map->extract[0] == '1' && map->extract[i] == '1')
		return(1);
	return(0);
}

int	is_not_wall_framed(t_solong **map)
{
	int	y;
	t_solong *tmp;
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

// int	is_not_valid_path(t_solong **map)
// {
	
// }

void	ft_map_is_valid(t_solong **map)
{
	if(is_not_rectangle(map))
		ft_exit(*map, "Error: map is not rectangle");
	if(is_not_wall_framed(map))
	 	ft_exit(*map, "Error: map is missng wall");
	// if(is_not_valid_path(*map)) //backtracking
	// 	ft_exit(map, "Error: map is not a valid path");
	
}