/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:44:45 by aceralin          #+#    #+#             */
/*   Updated: 2023/02/03 06:16:16 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	ft_init_count(t_map	count)
{
    count.c = 0;
	count.e = 0;
	count.p = 0;
}

void	is_not_valid_count(t_solong **map, t_map *count)
{
    t_solong *tmp;
    int  i;
   
	tmp = *map;
    while(tmp)
    {
    	i = 0;
		while(tmp->extract[i])
    	{
			if(tmp->extract[i] == 'P')
			{
				count->p++;
				if(count->p > 1)
					ft_exit(*map, "Error: too many Player in the map");
			}
			if(tmp->extract[i] == 'C')
				count->c++;
			if(tmp->extract[i] == 'E')
			{
				count->e++;
				if(count->e > 1)	
					ft_exit(*map, "Error: too many Exit in the map");
			}
			i++;
		}
		tmp = tmp->next;
    }
	if(count->c <= 0)
		ft_exit(*map, " Too few coin in the map");
	if(count->p == 0)
		ft_exit(*map, "Error: No Player in the map");
	if(count->e == 0)
		ft_exit(*map, "Error: No exit in the map");
}

int	change_c_to_p_i(t_solong *map, t_map *count, int i,char c)
{
	int check;
	
	check = 0;
	if(map->extract[i + 1] == c )
	{
		map->extract[i + 1] = 'P';
		if(c == 'C')
			count->c--;
		else if (c == 'E')
			count->e--;
		check++;
	}
	if (map->extract[i - 1] == c)
	{
		map->extract[i - 1] = 'P';
		if(c == 'C')
			count->c--;
		else if (c == 'E')
			count->e--;
		check++;
	}
	return(check);
}

int	change_c_to_p_np(t_solong *map, t_map *count, int i, char c)
{
	int check;
	
	check = 0;
	if (map->next->extract[i] == c )
	{
		map->next->extract[i] = 'P';
		if(c == 'C')
			count->c--;
		else if (c == 'E')
			count->e--;
		check++;
	}
	if (map->prev->extract[i] == c )
	{
		map->prev->extract[i] = 'P';
		if(c == 'C')
			count->c--;
		else if (c == 'E')
			count->e--;
		check++;
	}
	return(check);
}
int	change_nextp(t_solong *map, t_map *count, int i)
{
	int check;

	check = 0;

	check += change_c_to_p_i(map,count,i,'C');
	check += change_c_to_p_np(map,count, i,'C');
	check += change_c_to_p_i(map,count,i,'E');
	check += change_c_to_p_np(map,count, i,'E');
	check += change_c_to_p_i(map,count,i,'0');
	check += change_c_to_p_np(map,count, i,'0');
	if(check == 0)
		return(0);
	return(1);
}

int		is_not_valid_path(t_solong **map, t_map *count)
{
	t_solong	*tmp;
	int	i;
	int	change;
	
	tmp = *map;
	while (tmp)
	{
		i = 0;
		while (tmp->extract[i])
		{
			if(tmp->extract[i] == 'P')
				change += change_nextp(tmp, count, i);
			i++;
		}
		if(count->c == 0 && count->e == 0)
			return(0);
		if(tmp->next == NULL)
		{
			if(change == 0)
				return(1);
			else
				change = 0;
			tmp = *map;
		}
		tmp = tmp->next;
	}
	return(0);
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
