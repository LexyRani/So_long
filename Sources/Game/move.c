/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:11:40 by aceralin          #+#    #+#             */
/*   Updated: 2023/02/17 13:09:44 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	get_count(t_game *game)
{
	int	i;
	int j;
	
	i = 0;
	while(game->map_game[i])
	{
		j = 0;
		while(game->map_game[i][j])
		{
			if(game->map_game[i][j] == 'E')
				game->count_e++;
			if(game->map_game[i][j] == 'C')
				game->count_c++;
			j++;
		}
		i++;
	}
	printf("%d\n - %d\n", game->count_c, game->count_e );
}

void	ft_move_left(t_game *game)
{
	/*gerer le cas de 1CEP1*/
	game->x = game->x - 1;
	if(game->map_game[game->y][game->x] != '1')
	{
		if(game->map_game[game->y][game->x] == 'E')
		{
			game->count_e--;
            if(game->count_c == 0)
            {
                game->move++;
                // print le nombre//\n a la fin
                printf("%d\n", game->move);// a retirer
                exit(EXIT_SUCCESS);//ft_exit
            }
            return;;
		}
		if(game->map_game[game->y][game->x]== 'C')
            game->count_c--;
           
        game->map_game[game->y][game->x] = 'P';
        game->map_game[game->y][game->x + 1] = '0';
		/*if(game->count_e == -1)
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_exit, game->x * 50,game->y * 50);
			game->count_e++;
		}*/
		//si compteur de e = -1
            // remplacer le P par le E
            //compteur de e++  */   
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_player, game->x * 50,game->y * 50);
		print_double_array(game->map_game);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_floor, game->x * 50, game->y * 50);
        game->move++;
		printf("%d\n", game->move);//a retirer
        //print le nombre
        //\n a la fin
	}	
}
void	ft_move_right(t_game *game)
{
	/*gerer le cas de 1CEP1*/
	game->x = game->x + 1;
	if(game->map_game[game->y][game->x] != '1')
	{
		if(game->map_game[game->y][game->x] == 'E')
		{
			game->count_e--;
            if(game->count_c == 0)
            {
                game->move++;
                // print le nombre//\n a la fin
                printf("%d\n", game->move);// a retirer
                exit(EXIT_SUCCESS);//ft_exit
            }
            return;;
		}
		if(game->map_game[game->y][game->x]== 'C')
		{
            game->count_c--;
		}
        //si compteur de e = -1
            // remplacer le P par le E
            //compteur de e++        
        game->map_game[game->y][game->x] = 'P';
        game->map_game[game->y][game->x - 1] = '0';
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_player, game->x * 50,game->y * 50);
		print_double_array(game->map_game);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_floor, game->x * 50, game->y * 50);
        game->move++;
		printf("%d\n", game->move);//a retirer
        //print le nombre
        //\n a la fin
	}	
}

void	ft_move_down(t_game *game)
{
		/*gerer le cas de 1CEP1*/
	game->y = game->y + 1;
	if(game->map_game[game->y][game->x] != '1')
	{
		if(game->map_game[game->y][game->x] == 'E')
		{
			game->count_e--;
            if(game->count_c == 0)
            {
                game->move++;
                // print le nombre//\n a la fin
                printf("%d\n", game->move);// a retirer
                exit(EXIT_SUCCESS);//ft_exit
            }
            return;;
		}
		if(game->map_game[game->y][game->x]== 'C')
		{
            game->count_c--;
		}
        
        //si compteur de e = -1
            // remplacer le P par le E
            //compteur de e++  */      
        game->map_game[game->y][game->x] = 'P';
        game->map_game[game->y - 1][game->x] = '0';
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_player, game->x * 50,game->y * 50);
		print_double_array(game->map_game);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_floor, game->x * 50, game->y * 50);
       	game->move++;
		printf("%d\n", game->move);//a retirer
        //print le nombre
        //\n a la fin
	}	
}

void ft_move_up(t_game *game)
{
	/*gerer le cas de 1CEP1*/
	game->y = game->y - 1;
	if(game->map_game[game->y][game->x] != '1')
	{
		if(game->map_game[game->y][game->x] == 'E')
		{
			game->count_e--;
            if(game->count_c == 0)
            {
                game->move++;
                // print le nombre//\n a la fin
                printf("%d\n", game->move);// a retirer
                exit(EXIT_SUCCESS);//ft_exit
            }
            return;;
		}
		if(game->map_game[game->y][game->x]== 'C')
		{
            game->count_c--;
		}
		
        //si compteur de e = -1
            // remplacer le P par le E
			//remettre E si tout les C pas encore recoltes
            //compteur de e++        
        game->map_game[game->y][game->x] = 'P';
		/*if(game->count_e == -1 && game->map_game[game->y - 1][game->x] == 'P') 
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_exit, game->x * 50,(game->y - 1) * 50);
			game->count_e++;
		}*/
        game->map_game[game->y + 1][game->x] = '0';
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_player, game->x * 50,game->y * 50);
		print_double_array(game->map_game);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_floor, game->x * 50, game->y * 50);
        game->move++;
		printf("%d\n", game->move);//a retirer
        //print le nombre
        //\n a la fin
	}	
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
	}
	else if (key == XK_a)
		ft_move_left(game);
	else if (key == XK_d)
		ft_move_right(game);
	else if (key == XK_s)
		ft_move_down(game);
	return(0);
}