/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:11:39 by aceralin          #+#    #+#             */
/*   Updated: 2023/02/18 19:56:07 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	ft_exit(t_map *map ,t_game *game, char *msg)
{
	t_map	*head_map_aux;
	t_map	*tmp;

	(void)map;
	if (game)
	{
		if (game->map_game)//
		{
			int i = -1;
			while(game->map_game[++i])
				free(game->map_game[i]);
			i++;
		}
		if (game->head_map)
		{
			printf("Here\n");
			tmp = NULL;
			head_map_aux = *game->head_map;
			while (head_map_aux)
			{
				tmp = head_map_aux;
				head_map_aux = head_map_aux->next;
				free(tmp->line);
				free(tmp);
			}
		}
		free_game(game);
		game = NULL;		
	}
	// if (!game)
	// {
	// 	printf("Here\n");
	// 	if (map)
	// 	{
	// 		printf("Here\n");
	// 		while (map)
	// 		{
	// 			tmp = map;
	// 			map = map->next;
	// 			free(tmp->line);
	// 			free(tmp);
	// 		}
	// 	}
	// }
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
		free(tmp->line);
		free(tmp);
	}
	free(map);
}

int	free_game(t_game *game)
{
	free(game->map_game);//
	free(game->mlx_ptr);
	if(game->win_ptr)
		free(game->win_ptr);//
	free(game->img);
	free(game->img_wall);
	free(game->img_floor);
	free(game->img_player);
	free(game->img_coin);//
	free(game->img_exit);

	free(game);
	return (1);
}

/*void	ft_free_game(t_game *game)
{

}*/
int		ft_close(t_game *game)
{
	// (void) map;

	
		mlx_loop_end(game->mlx_ptr);
		if(game->mlx_ptr && game->img_coin)
			mlx_destroy_image(game->mlx_ptr, game->img_coin);
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_display(game->mlx_ptr);
		
		//ft_exit
		// free_map(game->head_map);
		free_game(game);
		exit(EXIT_SUCCESS);
		return 0;
}
//ft_close fermer les processus minilibx