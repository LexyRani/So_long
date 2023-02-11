/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:11:39 by aceralin          #+#    #+#             */
/*   Updated: 2023/02/11 14:21:10 by aceralin         ###   ########.fr       */
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
		exit(EXIT_SUCCESS);
		return 0;
}
//ft_close fermer les processus minilibx