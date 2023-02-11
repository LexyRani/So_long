/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:11:39 by aceralin          #+#    #+#             */
/*   Updated: 2023/02/11 21:13:41 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	ft_exit(t_map *map, char *msg)
{
	t_map	*tmp;
	
	
	while (map)
	{
		tmp = map;
		map = map->next;
		free(tmp->extract);
		free(tmp);
		
	}
	
	if(msg)
		ft_putendl_fd(msg, 2);
	
	exit(EXIT_FAILURE);
}

void	free_map(t_map *map)
{
	t_map	*tmp;
	
	while (map)
	{
		tmp = map;
		map = map->next;
		free(tmp->extract);
		free(tmp);
	}
	free(map);
}

int	free_game(t_game *game)
{
	free(game->mlx_ptr);
	free(game->img);
	free(game->img_wall);
	free(game->img_floor);
	free(game->img_player);
	free(game->img_exit);
	free(game);
	return (1);
}

/*void	ft_free_game(t_game *game)
{

}*/
int	ft_close(t_game *game)
{
	// (void) map;

	
		mlx_loop_end(game->mlx_ptr);
		if(game->mlx_ptr && game->img_coin)
			mlx_destroy_image(game->mlx_ptr, game->img_coin);
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_display(game->mlx_ptr);
		free_map(game->head_map);
		free_game(game);
		exit(EXIT_SUCCESS);
		return 0;
}
//ft_close fermer les processus minilibx