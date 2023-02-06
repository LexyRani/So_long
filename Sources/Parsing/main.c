/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:20:07 by aceralin          #+#    #+#             */
/*   Updated: 2023/02/06 21:07:53 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

int	ft_arg_is_not_ber(char *s1, char *extension)
{
	int		i;

	i = (int)ft_strlen(s1) - 1;
	while(s1[i] && s1[i] != '.')
		i--;
	if(i <= 0)
		return(1);
	if(ft_strcmp(s1 + i, extension))
		return(1);
	return(0);
}

void 	ft_check_map(t_solong	**map, int fd)
{
	t_solong	*extract;
	char 		*ptr;
	
	//if(map == NULL)
		//ft_exit(NULL, "Error: Empty map");
	ptr = get_next_line(fd);
	while(ptr)
	{
		extract = ft_lstnew(ptr);
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
	t_solong	**map;
	t_solong	*lst;
	int	fd;

	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "COUCOU JE SUIS MOCHE <3");
	mlx_loop(mlx_ptr);
	
	lst = NULL;
	map = &lst;
	if (argc != 2)
		ft_exit(NULL, "Error");
	if((ft_arg_is_not_ber(argv[1], ".ber")))
		ft_exit(NULL,"Error: Your file is not .ber");
	fd = open(argv[1], O_RDONLY);
	if(fd == -1)
		ft_exit(NULL, "Error to open the file");
	ft_check_map(map, fd);
	ft_map_is_valid(map);

	ft_exit(*map,"");
}
//• Vous devez pouvoir parser tout type de carte du moment qu’elle respecte les règles
	//énoncées ci-dessus.
	//Si une erreur de configuration est détectée, le programme doit quitter proprement
	//et retourner "Error\n" suivi d’un message d’erreur explicite de votre choix.
//--leak-check=full --show-leak-kinds=