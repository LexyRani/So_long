/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:27:43 by aceralin          #+#    #+#             */
/*   Updated: 2023/02/19 17:26:50 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

int	valid_char(char c)
{
	if (c == '0' || c == 'E' || c == '1' || c == 'C' || c == 'P')
		return (0);
	return (1);
}

int	is_bad_char(t_map **map)
{
	t_map	*tmp;
	int		i;

	tmp = *map;
	while (tmp)
	{
		i = 0;
		while (tmp->line[i])
		{	
			if (valid_char(tmp->line[i]))
				return (1);
			i++;
		}
		tmp = tmp->next;
	}
	return (0);
}

void	ft_map_is_valid(t_game *game, t_map **map)
{
	t_count	count;

	count.c = 0;
	count.e = 0;
	count.p = 0;
	if (*map == NULL)
		ft_exit(NULL, NULL, ERROR_EMPTY);
	if (is_not_rectangle(map))
		ft_exit(*map, game, ERROR_REC);
	if (is_not_wall_framed(map))
		ft_exit(*map, game, ERROR_WALL);
	if (is_bad_char(map))
		ft_exit(*map, game, ERROR_CHAR);
	if (is_not_valid_count(map, &count))
		ft_exit(*map, game, ERROR_PATH);
	if (is_not_valid_path(game, map, &count))
		ft_exit(*map, game, ERROR_PATH);
}
