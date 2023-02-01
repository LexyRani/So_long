/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:20:07 by aceralin          #+#    #+#             */
/*   Updated: 2023/02/01 00:18:49 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

//La carte doit être de forme rectangulaire.
//• La carte doit être fermée en étant encadrée par des murs. Si ce n’est pas le cas, le
//programme retourne une erreur.
//• Vous devez vérifier s’il existe un chemin valide (i.e. qu’il est possible d’emprunter)
//dans la carte.
//• Vous devez pouvoir parser tout type de carte du moment qu’elle respecte les règles
//énoncées ci-dessus.
//Si une erreur de configuration est détectée, le programme doit quitter proprement
//et retourner "Error\n" suivi d’un message d’erreur explicite de votre choix.

/*
int	ft_strcmp_end(char *s, char *t)
{
	if(ft_strlen(s) < ft_strlen(t))
		return(0);
	return()
}*/



int	ft_arg_is_not_ber(char *s1, char *extension)
{
	//lire a partir de la fin (dans le cas de ber.ber.ber ou toto.toto.ber)
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
	int	fd;

	lst = NULL;
	map = &lst;
	if (argc != 2)
		ft_exit(NULL, "Error");
	if((ft_arg_is_not_ber(argv[1], ".ber")))
		ft_exit(NULL,"Error: Your file is not .ber\n");
	fd = open(argv[1], O_RDONLY);
	if(fd == -1)
		ft_exit(NULL, "Error to open the file\n");
	ft_check_map(map, fd);
	ft_map_is_valid(map);

	ft_exit(*map,"");
	//La carte doit être de forme rectangulaire. <=> la longueur de chaque ligne doit etre egale
	//• La carte doit être fermée en étant encadrée par des murs. Si ce n’est pas le cas, le
	//programme retourne une erreur.
	//• Vous devez vérifier s’il existe un chemin valide (i.e. qu’il est possible d’emprunter)
	//dans la carte.
	//• Vous devez pouvoir parser tout type de carte du moment qu’elle respecte les règles
	//énoncées ci-dessus.
	//Si une erreur de configuration est détectée, le programme doit quitter proprement
	//et retourner "Error\n" suivi d’un message d’erreur explicite de votre choix.
    
	
	
	
	//recuperer la map et la lire
    //checker si la map recu est valide (est elle bien rectangulaire, et les autres conditions)
	
	//parsing
}

    /*
     if (fd == -1)
    {
        printf("\n[error open()\n]");
        return (1);
    }
	printf("\nopen()\n");
    while (extract != NULL)
	{
		extract = get_next_line(fd);
		printf("gnl -> %s\n", extract);
		free(extract);
		i++;
	}
	printf("i   -> %d\n", i);
    if (close(fd) == -1)
    {
        printf("\n[error close()]\n");
        return (2);
    }
	printf("\nclose()\n");
    return(0);
}
*/
//--leak-check=no|summary|full 