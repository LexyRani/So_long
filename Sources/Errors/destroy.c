/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:58:50 by aceralin          #+#    #+#             */
/*   Updated: 2023/02/20 14:59:07 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

int	ft_clean_mlx(t_game *game)
{
	if (game->mlx_ptr)
		mlx_loop_end(game->mlx_ptr);
	if (game->mlx_ptr && game->img_coin)
		mlx_destroy_image(game->mlx_ptr, game->img_coin);
	if (game->mlx_ptr && game->img_exit)
		mlx_destroy_image(game->mlx_ptr, game->img_exit);
	if (game->mlx_ptr && game->img_floor)
		mlx_destroy_image(game->mlx_ptr, game->img_floor);
	if (game->mlx_ptr && game->img_player)
		mlx_destroy_image(game->mlx_ptr, game->img_player);
	if (game->mlx_ptr && game->img_wall)
		mlx_destroy_image(game->mlx_ptr, game->img_wall);
	if (game->mlx_ptr && game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
		mlx_destroy_display(game->mlx_ptr);
	return (0);
}
