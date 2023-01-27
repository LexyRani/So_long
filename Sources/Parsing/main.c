/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:20:07 by aceralin          #+#    #+#             */
/*   Updated: 2023/01/27 18:40:42 by aceralin         ###   ########.fr       */
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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_arg_is_ber(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int 	j;
	
	i = strlen(s1) - n ;
	j = 0;
	while (s1[i] != '\0' && (s1[i] == s2[j]) && (i <= strlen(s1)))
	{
		i++;
		//printf("%s\n - %s\n",s1[i], s2[j]);
	}
	printf("%s\n",s1);
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}
/*
int	ft_check_map(char *argv[])
{
	int	fd;
    char	*extract;
    int	i;
	
	 extract = "";
	fd = open(*argv, O_RDONLY);
	i = 0;
	while(extract)
	{
    	extract = get_next_line(fd);
		i ++;
	}
	if (close(fd) == -1)
		ft_exit(NULL, "Error\n");
}*/

int	main(int argc, char *argv[])
{
	if (argc < 2)
		ft_exit(NULL, "Error\n");
	//int i;
	
	/*i = 0;
	if(argc == 2)
	{
		while(argc)
		{
			printf("%s",*argv);
			i++;
		}
	}*/
	if(argv[1])	
	{
		if(ft_arg_is_ber(argv[1],".ber", 4))
			ft_exit(NULL,"Error: Your file is not .ber\n");
	}
	//verifier si le nom du fichier est bien un .ber
	
    
    //recuperer la map et la lire
    //checker si la map recu est valide
    
	
	//ft_check_map();
		
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