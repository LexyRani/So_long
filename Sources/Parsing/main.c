/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:20:07 by aceralin          #+#    #+#             */
/*   Updated: 2023/02/18 14:58:57 by aceralin         ###   ########.fr       */
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

void	ft_check_map(t_game *game, t_map **map, int fd)
{
	t_map	*extract;
	char	*ptr;

	ptr = get_next_line(fd);
	while (ptr)
	{
		extract = ft_lstnew(ptr);
		game->head_map = extract;
		if (!extract)
			ft_exit(NULL, "Error");
		ft_lstadd_back(map, extract);
		free (ptr);
		ptr = get_next_line(fd);
	}
	if (close(fd) == -1)
		ft_exit(NULL, "Error\n");
}

int	main(int argc, char *argv[])
{
	t_map	**map;
	int		fd;
	t_game	*game;
	t_map	*lst;

	
	if (argc != 2)
		ft_exit(NULL, "Error: there must be only two arguments \
						([./so_long] [path_map.ber] )");
	if ((ft_arg_is_not_ber(argv[1], ".ber")))
		ft_exit(NULL, "Error: Your file is not .ber");
	game = (void *)malloc(sizeof(t_game)); //liberer
	lst = NULL;
	map = &lst;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_exit(NULL, "Error to open the file");
	ft_check_map(game, map, fd);
	ft_map_is_valid(game, map);
	display_the_map(game);
	free_game(game);
	dprintf(1, "%s\n", "--- EXITED HERE ---\n");
	ft_exit(*map, "");
}

//--leak-check=full --show-leak-kinds=

//mlx_xpm_file_to_image
//mlx_hook pour gerer les event et fermer la fenetre
//mlx_put_image_to_window