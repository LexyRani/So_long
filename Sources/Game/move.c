/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:11:40 by aceralin          #+#    #+#             */
/*   Updated: 2023/02/19 19:53:23 by aceralin         ###   ########.fr       */
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



void	ft_move_up(t_game *game)
{
	game->y = game->y - 1;
	if (game->map_game[game->y][game->x] != '1')
	{
		if (game->map_game[game->y][game->x] == 'E')
		{
			game->count_e--;
			if (game->count_c == 0)
			{
				game->move++;
				ft_putnbr_fd(game->move, 1);
				ft_putstr_fd("\n", 1);
				ft_close(game);
			}
			game->map_game[game->y][game->x] = 'P';
			game->map_game[game->y + 1][game->x] = '0';
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_player, game->x * 50,game->y * 50);
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_floor, game->x * 50, game->y * 50);
		}
		else if (game->map_game[game->y][game->x] == 'C')
		{
			game->count_c--;
			game->map_game[game->y][game->x] = 'P';
			if (game->count_e == 0)
			{
				game->map_game[game->y + 1][game->x] = 'E';
				game->count_e++;
			}
			else
				game->map_game[game->y + 1][game->x] = '0';
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_player, game->x * 50,game->y * 50);
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_floor, game->x * 50, game->y * 50);
		}
		else if (game->map_game[game->y][game->x] == '0')
		{
			if (game->count_e == 0)
			{
				game->map_game[game->y][game->x] = 'P';
				game->map_game[game->y + 1][game->x] = 'E';
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_exit, game->x  * 50, (game->y + 1) * 50);
				game->count_e++;
			}
			else
			{
				game->map_game[game->y][game->x] = 'P';
				game->map_game[game->y + 1][game->x] = '0';
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_player, game->x * 50,game->y * 50);
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_floor, game->x * 50, game->y * 50);
			}
		}
		game->move++;
		ft_putnbr_fd(game->move, 1);
		ft_putstr_fd("\n", 1);
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