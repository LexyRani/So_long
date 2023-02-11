/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:40:38 by aceralin          #+#    #+#             */
/*   Updated: 2023/02/11 19:48:32 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	*ft_convert_to_img(char *img, t_game *data)
{
	void	*img_ptr;
	int len  = 5;
	int width = 1;

	img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, img, &width, &len);
	// printf("img+ptr = %p \n", &img_ptr);
	return (img_ptr);
}

void	image_init(t_game *data)
{
	data->img_coin = ft_convert_to_img("./Sources/Images/coin.xpm", data);
	//mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_coin, 0, 150);
	data->img_wall = ft_convert_to_img("./Sources/Images/walls.xpm",data);
	//mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_wall, 0, 100);
	data->img_exit = ft_convert_to_img("./Sources/Images/banque.xpm", data);
	//mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_exit, 0, 0);
	data->img_player = ft_convert_to_img("./Sources/Images/players.xpm", data);
	//mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_player, 0, 300);
	data->img_floor = ft_convert_to_img("./Sources/Images/plus.xpm", data);
	//mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_floor, 0, 400);
}


/*void	image_init(t_game *game)
{
	int len  = 23;
	int width = 3;
	game->img_coin = mlx_xpm_file_to_image(game->mlx_ptr, "../Images/dollar.xpm",  &width, &len );
}*/

void	display_init(t_game *game)
{
	game->mlx_ptr = NULL;
	game->img = NULL ;
	game->win_ptr = NULL;	
}

int	print_map(t_map *tmp)
{
	t_map	*head;

	head = tmp;
	while (tmp)
	{
		dprintf(2, "%s\n", tmp->extract);
		tmp = tmp->next;
	}
	tmp = head;	
	return (1);
}

void	put_images(t_game *game, t_map **map)
{
	int		i;
	t_map 	*tmp;

	i = 0;

	tmp = *map;
	tmp ->index = 0;
	while(tmp)
	{
		printf("%c\n", (*map)->extract[i]);
		while(tmp->extract[i])
	 	{
			printf("ici\n");
	 		if(tmp->extract[i] == '1')
			{
				printf("%d - %d\n", tmp->extract[i], tmp->index);
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_wall, tmp->extract[i], tmp->index );
			}
	 		i++;
			tmp->index++;
	 	}
	 	tmp = tmp->next;
	}
}

void    display_the_map(t_game *game, t_map **map)
{
	display_init(game);
    game->mlx_ptr = mlx_init();
	if(!game->mlx_ptr)
		ft_close(game);
	game->img = mlx_new_image(game->mlx_ptr, 1500, 550);
	if(!game->img)
        ft_close(game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, 1500, 550, "mlx 42");
	if(!game->win_ptr)
		ft_close(game);
	image_init(game);
	put_images(game, map);
	mlx_hook(game->win_ptr, 17, (1L << 17), ft_close, game);
  	mlx_loop(game->mlx_ptr);
	
    
    
}