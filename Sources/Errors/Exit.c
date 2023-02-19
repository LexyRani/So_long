/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:11:39 by aceralin          #+#    #+#             */
/*   Updated: 2023/02/19 17:50:24 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	ft_exit(t_map *map, t_game *game, char *msg)
{
	t_map	*head_map_aux;
	t_map	*tmp;
	int		i;
	(void)map;

	if (game)
	{
		if (game->map_game)
		{
			i = 0;
			while (game->map_game[i])
			{
				free(game->map_game[i]);
				i++;
			}
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
	if (msg)
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
	free(game->map_game);
	if (game->mlx_ptr)
		free(game->mlx_ptr);
	// if (game->fd > 2)
	// 	close(game->fd);
	free(game);
	return (1);
}

int	ft_close(t_game *game)
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
	ft_exit (NULL, game, "");
	return (0);
}
//ft_close fermer les processus minilibx