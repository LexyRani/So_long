/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:40:38 by aceralin          #+#    #+#             */
/*   Updated: 2023/02/10 18:25:45 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	*ft_convert_to_img(char *img, t_game *data)
{
	void	*img_ptr;
	int len  = 23;
	int width = 3;

	img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, img, &width, &len);
	printf("img+ptr = %p \n", &img_ptr);
	return (img_ptr);
}

void	image_init(t_game *data)
{
	data->img_coin = ft_convert_to_img("./Sources/Images/dollar.xpm", data);
}


/*void	image_init(t_game *game)
{
	int len  = 23;
	int width = 3;
	game->img_coin = mlx_xpm_file_to_image(game->mlx_ptr, "../Images/dollar.xpm",  &width, &len );
}*/




void    display_the_map(t_game *game, t_map **map)
{
	int	i;
	t_map *tmp;
		
	i = 0;
	tmp = *map;

    game->mlx_ptr = NULL;
	game->img = NULL ;
	game->win_ptr = NULL;
	
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

	// while(tmp)
	// {
	// 	while(tmp->extract[i])
	// 	{
	// 		if()
	// 			mlx_put_image_to_window()
	// 		i++;
	// 	}
	// 	tmp = tmp->next;
	// }
	mlx_hook(game->win_ptr, 17, (1L << 17), ft_close, &game);
  	mlx_loop(game->mlx_ptr);
	
    
    
}