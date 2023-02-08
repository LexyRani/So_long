/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:20:27 by aceralin          #+#    #+#             */
/*   Updated: 2023/02/08 15:35:49 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "../mlx/mlx.h"

/* BUFFER*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
typedef struct s_data
{
			
			char	*addr;
			int		bits_per_pixel;
			int		line_lenght;
			int		endian;			
}				t_data;



typedef struct s_map
{
			int	p; //compteur 
			int	e; //compteur
			int	c; //compteur
			
}			t_map; 

typedef struct s_solong
{
			char	*extract;
			int		index;		
			struct s_solong	*prev;
			struct s_solong	*next;
}						t_solong;


typedef struct s_mlxa
{
	//t_solong	**map;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
} 			t_mlxa;

/******************************************************************************/
/*									PARSING	  								  */
/******************************************************************************/
/*________/MAIN\________*/
int			ft_arg_is_not_ber(char *s1, char *extension);
void 		ft_check_map(t_solong	**lst_begin, int fd);
					
/*_____/VALID MAP\______*/
void		ft_map_is_valid(t_solong **map);
int			is_not_rectangle(t_solong **map);
int			is_not_wall_framed(t_solong **map);
int			check_middle(t_solong *map);
int			is_all_one( t_solong *map);

/*______/VALID MAP\_____*/
int			is_not_valid_path(t_solong **map, t_map *count);
void		is_not_valid_count(t_solong **map, t_map *count);
void		ft_init_count(t_map	count);
int			change_nextp(t_solong *map, t_map *count, int i);
int			change_c_to_p_np(t_solong *map, t_map *count, int i, char c);
int			change_c_to_p_i(t_solong *map, t_map *count, int i,char c);
t_map 		*is_what_kind(char tmp, t_solong **map, t_map * count);
/******************************************************************************/
/*									GET_NEXT_LINE	  						  */
/******************************************************************************/

char		*ft_copy_and_stick(char *buffer, char *line_read);
char		*get_next_line(int fd);
int			found_new_line(char *str);
char		*buffer_after_new_line(char *buffer, int len_line_read);
size_t		ft_strlen(const char *s);
void		*ft_memcpy(void *dest, const void *src, size_t n);

/******************************************************************************/
/*									ERRORS  								  */
/******************************************************************************/

void   		ft_exit(t_solong *map, char *msg);
/******************************************************************************/
/*									UTILS	  								  */
/******************************************************************************/

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
int			ft_strcmp(char *s1, char *s2);
t_solong	*ft_lstnew(void *content);
t_solong	*ft_lstlast(t_solong *lst);
void		ft_lstadd_back(t_solong **lst, t_solong *new);
char		*ft_strdup_without_nl(const char *s);
int			ft_lstsize(t_solong *lst);


#endif