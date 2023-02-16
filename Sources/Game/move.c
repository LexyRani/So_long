/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:11:40 by aceralin          #+#    #+#             */
/*   Updated: 2023/02/16 23:33:42 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void ft_move_up(t_game *game)
{
	/*gerer le cas de 1CEP1*/
	game->y = game->y - 1;
	if(game->map_game[game->x][game->y] != 1)
	{
		/*if(game->map_game[game->y][game->x] == 'E')
		{
            //compteur de e--
            //si compteur de c == 0
            {
                //compteur de move++
                // print le nombre
                //\n a la fin
                //ft_exit
            }
            //sinon return
		}
		if(game->map_game[game->y][game->x]== 'C')
		{
            //diminuer le compteur de c
		}
        */
        //si compteur de e = -1
            // remplacer le P par le E
            //compteur de e++        
        game->map_game[game->x][game->y] = 'P';
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_player, game->x * 50,game->y * 50);
		print_double_array(game->map_game);
        game->map_game[game->x][game->y + 1] = '0';
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_floor, game->x * 50, game->y * 50);
        // compteur de move ++;
        //print le nombre
        //\n a la fin
	}	
	//game->map_game[game->x][game->y] = 'P';
	//game->map_game[tmp_x][tmp_y] = '0';
	//player_position(game);
	 	
}

void	player_position(t_game *game)
{
	int i;
	int j;

	game->x = 0;
	game->y = 0;

	j = 0;
	while(game->map_game[j])
	{
		i = 0;
		while(game->map_game[j][i] != '\0')
		{
			if(game->map_game[j][i] == 'P')
			{
				//printf("%d - %d\n", i , j);
				game->x = i;
				game->y = j;
			}	
			i++;
		}
		j++;
	}
}

int	ft_key_move( int key, t_game *game)
{
	player_position(game);
	if(key == XK_Escape)
	{
		printf("Exit)\n");
		exit(EXIT_SUCCESS);
	}
	else if (key == XK_w)
	{
		ft_move_up(game);
		printf("%d - %d\n", game->x , game->y);
	}

		//printf("Haut)\n");
	else if (key == XK_a)
		printf("gauche)\n");
	else if (key == XK_d)
		printf("droit)\n");
	else if (key == XK_s)
		printf("bas)\n");
	return(0);
}