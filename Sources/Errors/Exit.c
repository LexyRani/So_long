/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:11:39 by aceralin          #+#    #+#             */
/*   Updated: 2023/02/20 15:01:44 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	free_for_chained_list( t_map *head_map_aux)
{
	t_map	*tmp;

	while (head_map_aux)
	{
		tmp = head_map_aux;
		head_map_aux = head_map_aux->next;
		free(tmp->line);
		free(tmp);
	}
}

void	ft_exit(t_map *map, t_game *game, char *msg)
{
	t_map	*head_map_aux;
	int		i;

	(void)map;
	if (game)
	{
		if (game->map_game)
		{
			i = 0;
			while (game->map_game[i])
				free(game->map_game[i++]);
		}
		if (game->head_map)
		{
			head_map_aux = *game->head_map;
			free_for_chained_list(*game->head_map);
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
	if (game->fd > 2)
		close(game->fd);
	free(game);
	return (1);
}

int	ft_close(t_game *game)
{
	ft_clean_mlx(game);
	ft_exit (NULL, game, NULL);
	return (0);
}
