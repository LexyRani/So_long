/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:36:19 by aceralin          #+#    #+#             */
/*   Updated: 2023/02/20 01:10:12 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	move_if_c_up(t_game *game)
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
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->img_player, game->x * 50, game->y * 50);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->img_floor, game->x * 50, game->y * 50);
}

void	move_if_0_up(t_game *game)
{
	if (game->count_e == 0)
	{
		game->map_game[game->y][game->x] = 'P';
		game->map_game[game->y + 1][game->x] = 'E';
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img_exit, game->x * 50, (game->y + 1) * 50);
		game->count_e++;
	}
	else
	{
		game->map_game[game->y][game->x] = 'P';
		game->map_game[game->y + 1][game->x] = '0';
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img_player, game->x * 50, game->y * 50);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img_floor, game->x * 50, game->y * 50);
	}
}

void	move_if_e_up(t_game *game)
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
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->img_player, game->x * 50, game->y * 50);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->img_floor, game->x * 50, game->y * 50);
}

void	ft_move_up(t_game *game)
{
	game->y = game->y - 1;
	if (game->map_game[game->y][game->x] != '1')
	{
		if (game->map_game[game->y][game->x] == 'E')
			move_if_e_up(game);
		else if (game->map_game[game->y][game->x] == 'C')
			move_if_c_up(game);
		else if (game->map_game[game->y][game->x] == '0')
			move_if_0_up(game);
		game->move++;
		ft_putnbr_fd(game->move, 1);
		ft_putstr_fd("\n", 1);
	}	
}
