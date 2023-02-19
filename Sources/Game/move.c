/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:11:40 by aceralin          #+#    #+#             */
/*   Updated: 2023/02/19 20:36:58 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	get_count(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map_game[i])
	{
		j = 0;
		while (game->map_game[i][j])
		{
			if (game->map_game[i][j] == 'E')
				game->count_e++;
			if (game->map_game[i][j] == 'C')
				game->count_c++;
			j++;
		}
		i++;
	}
}

void	player_position(t_game *game)
{
	int	i;
	int	j;

	game->x = 0;
	game->y = 0;
	j = 0;
	while (game->map_game[j])
	{
		i = 0;
		while (game->map_game[j][i] != '\0')
		{
			if (game->map_game[j][i] == 'P')
			{
				game->x = i;
				game->y = j;
			}	
			i++;
		}
		j++;
	}
}

int	ft_key_move( int key, t_game *game)
{
	player_position(game);
	if (key == XK_Escape)
		ft_close(game);
	else if (key == XK_w)
		ft_move_up(game);
	else if (key == XK_a)
		ft_move_left(game);
	else if (key == XK_d)
		ft_move_right(game);
	else if (key == XK_s)
		ft_move_down(game);
	return (0);
}