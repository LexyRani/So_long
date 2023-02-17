/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:19:19 by aceralin          #+#    #+#             */
/*   Updated: 2023/02/17 12:37:23 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	image_init(t_game *data)
{
	data->img_coin = ft_convert_to_img("./Sources/Images/coin.xpm", data);
	data->img_wall = ft_convert_to_img("./Sources/Images/walls.xpm",data);
	data->img_exit = ft_convert_to_img("./Sources/Images/banque.xpm", data);
	data->img_player = ft_convert_to_img("./Sources/Images/players.xpm", data);
	data->img_floor = ft_convert_to_img("./Sources/Images/black_shape.xpm", data);
}

void	display_init(t_game *game)
{
	game->mlx_ptr = NULL;
	game->img = NULL ;
	game->win_ptr = NULL;
	game->img_coin = 0;
	game->img_exit = 0;
	game->img_floor = 0;
	game->img_player = 0;
	game->img_wall = 0;
	game->count_c = 0;
	game->count_e = 0;
	game->move = 0;
}
