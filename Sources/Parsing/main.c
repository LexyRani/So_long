/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:20:07 by aceralin          #+#    #+#             */
/*   Updated: 2023/02/08 15:38:30 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"
/*
void	ft_file_to_image(void *mlx_ptr)
{
	void *img;
	char	*img_path;
	
	
}*/


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
	int			fd;
	t_mlxa		*mlxa = NULL;
	mlxa = (void *) malloc(sizeof(t_mlxa));
	//void *img;
	lst = NULL;
	map = &lst;
	//void *mlx_ptr;
	//void	*win_ptr;
	//mlx = NULL;
	mlxa->mlx_ptr = 0;
	mlxa->img = 0 ;
	mlxa->win_ptr = 0;
	
	if (argc != 2)
		ft_exit(NULL, "Error");
	if((ft_arg_is_not_ber(argv[1], ".ber")))
		ft_exit(NULL,"Error: Your file is not .ber");
	fd = open(argv[1], O_RDONLY);
	if(fd == -1)
		ft_exit(NULL, "Error to open the file");
	ft_check_map(map, fd);
	ft_map_is_valid(map);
	
	mlxa->mlx_ptr = mlx_init(); // relie le logiciel a l affichage
	mlxa->img = mlx_new_image(mlxa->mlx_ptr, 1920, 1080);
	mlxa->win_ptr = mlx_new_window(mlxa->mlx_ptr, 1500, 550, "mlx 42"); // ouvre une nouvelle fenetre sur l ecran
	mlx_loop(mlxa->mlx_ptr); //atend la saisie du clavier et de la souris dans la fenetre, permet de redessiner la fenetre
	//ft_file_to_image(mlx_ptr);
	ft_exit(*map,"");
}
//• Vous devez pouvoir parser tout type de carte du moment qu’elle respecte les règles
	//énoncées ci-dessus.
	//Si une erreur de configuration est détectée, le programme doit quitter proprement
	//et retourner "Error\n" suivi d’un message d’erreur explicite de votre choix.
//--leak-check=full --show-leak-kinds=

//mlx_xpm_file_to_image
//mlx_hook pour gerer les event et fermer la fenetre
//mlx_put_image_to_window