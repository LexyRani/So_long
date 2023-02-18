/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:20:07 by aceralin          #+#    #+#             */
/*   Updated: 2023/02/18 20:13:24 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

int	ft_arg_is_not_ber(char *s1, char *extension)
{
	int		i;

	i = (int)ft_strlen(s1) - 1;
	while (s1[i] && s1[i] != '.')
		i--;
	if (i <= 0)
		return (1);
	if (ft_strcmp(s1 + i, extension))
		return (1);
	return (0);
}

int	ft_check_map(t_map **map, int fd)
{
	t_map	*extract;
	char	*ptr;

	ptr = get_next_line(fd);
	while (ptr)
	{
		extract = ft_lstnew(ptr);
		if (!extract)
			return (0);
		ft_lstadd_back(map, extract);
		free (ptr);
		ptr = get_next_line(fd);
	}
	if (close(fd) == -1)
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_map	**map;
	int		fd;
	t_game	*game;
	t_map	*lst;

	
	if (argc != 2)
	{
		ft_exit(NULL, NULL, "Error: there must be only two arguments \
						([./so_long] [path_map.ber] )");
	}
	if ((ft_arg_is_not_ber(argv[1], ".ber")))
		ft_exit(NULL, NULL, "Error: Your file is not .ber");
	lst = NULL;
	map = &lst;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_exit(NULL, NULL, "Error: to open the file");
	if (!ft_check_map(map, fd))
		ft_exit(*map, NULL, "Error: Malloc fail"); // Il faut change ce message (close or malloc)
	game = (void *)malloc(sizeof(t_game)); //liberer
	if (!game)
		ft_exit(*map, NULL, "Error: Malloc fail");
	game->head_map = map;
	display_init(game);
	ft_map_is_valid(game, game->head_map);
	// Tout est bon
	display_the_map(game);
	// free_game(game);
	ft_exit(*map, game, "");
}

//--leak-check=full --show-leak-kinds=

//mlx_xpm_file_to_image
//mlx_hook pour gerer les event et fermer la fenetre
//mlx_put_image_to_window