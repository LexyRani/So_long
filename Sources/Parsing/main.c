/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:20:07 by aceralin          #+#    #+#             */
/*   Updated: 2023/02/20 14:56:13 by aceralin         ###   ########.fr       */
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
	t_game	*game;
	t_map	*lst;

	if (argc != 2)
		ft_exit(NULL, NULL, ERROR_ARG);
	if ((ft_arg_is_not_ber(argv[1], ".ber")))
		ft_exit(NULL, NULL, ERROR_EXT);
	lst = NULL;
	map = &lst;
	game = (void *)malloc(sizeof(t_game));
	if (!game)
		ft_exit(*map, NULL, ERROR_MALLOC);
	display_init(game);
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd == -1)
		ft_exit(NULL, game, ERROR_FILE);
	if (!ft_check_map(map, game->fd))
		ft_exit(*map, game, ERROR_MALLOC);
	game->head_map = map;
	ft_map_is_valid(game, game->head_map);
	display_the_map(game);
	ft_exit(*map, game, "");
	return (0);
}
