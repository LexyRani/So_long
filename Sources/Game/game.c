/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:40:38 by aceralin          #+#    #+#             */
/*   Updated: 2023/02/18 19:18:45 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	*ft_convert_to_img(char *img, t_game *data)
{
	void	*img_ptr;
	int len  = 5;
	int width = 1;

	img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, img, &width, &len);
	return (img_ptr);
}

int	print_map(t_map *tmp)
{
	t_map	*head;

	head = tmp;
	while (tmp)
	{
		dprintf(2, "%s\n", tmp->line);
		tmp = tmp->next;
	}
	tmp = head;	
	return (1);
}

int	put_images(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while(game->map_game[y])
	{
		x = 0;
		while(game->map_game[y][x])
	 	{
	 		if(game->map_game[y][x] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_wall, x * 50, y* 50);
			if(game->map_game[y][x] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_coin, x * 50, y* 50);
			if(game->map_game[y][x] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_exit, x * 50, y* 50);
			if(game->map_game[y][x] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_player, x * 50, y* 50);
			if(game->map_game[y][x] == '0')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_floor, x * 50, y* 50);
			x++;
		}
		y++;
	}
	return(0);
}

void    display_the_map(t_game *game)
{
	int x;
	int y;
	int length;
	int width;

	y = 0;
	x = 0;
	x = ft_len(game->map_game[0]);
	y = ft_len_tab(game->map_game);
    game->mlx_ptr = mlx_init(); //proteger la mlx
	//if(!(game->mlx_ptr))
		//ft_exit(*)
	if(!game->mlx_ptr)
		ft_close(game);
	game->img = mlx_new_image(game->mlx_ptr, 1500, 550);
	if(!game->img)
        ft_close(game);
	mlx_get_screen_size(game->mlx_ptr, &length, &width);
	//printf("length = %d - width =%d\n", width, length);
	if(x * 50 > length || y * 50 > length)
		ft_exit(NULL, game, "Error: the map is too big for the screen");
	
	game->win_ptr = mlx_new_window(game->mlx_ptr, x * 50 , y * 50 , "LA CASA DE PAPEL");
	if(!game->win_ptr)
		ft_close(game);
	image_init(game);
	put_images(game);
	get_count(game);
	mlx_hook(game->win_ptr, 2 , 1L<<0, ft_key_move, game);
	mlx_hook(game->win_ptr, 17, (1L << 17), ft_close, game);
	mlx_loop_hook(game->mlx_ptr, put_images, game);
  	mlx_loop(game->mlx_ptr);
}