/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:20:27 by aceralin          #+#    #+#             */
/*   Updated: 2023/02/10 18:08:31 by aceralin         ###   ########.fr       */
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


typedef struct s_count // compteur
{
			int	p; //compteur 
			int	e; //compteur
			int	c; //compteur
			
}			t_count; 

typedef struct s_map //map
{
			char	*extract;
			int		index;		
			struct s_map	*prev;
			struct s_map	*next;
}						t_map;


typedef struct s_game //game
{
	//t_solong	**map;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
//	void	*img_wall;
//	void	*img_floor;
	void	*img_coin;
//	void	*img_player;
//	void	*img_exit;
} 			t_game;

/******************************************************************************/
/*									PARSING	  								  */
/******************************************************************************/
/*________/MAIN\________*/
int			ft_arg_is_not_ber(char *s1, char *extension);
void 		ft_check_map(t_map	**lst_begin, int fd);
					
/*_____/VALID MAP\______*/
void		ft_map_is_valid(t_map **map);
int			is_not_rectangle(t_map **map);
int			is_not_wall_framed(t_map **map);
int			check_middle(t_map *map);
int			is_all_one( t_map *map);

/*______/VALID MAP\_____*/
int			is_not_valid_path(t_map **map, t_count *count);
void		is_not_valid_count(t_map **map, t_count *count);
void		ft_init_count(t_count	count);
int			change_nextp(t_map *map, t_count *count, int i);
int			change_c_to_p_np(t_map *map, t_count *count, int i, char c);
int			change_c_to_p_i(t_map *map, t_count *count, int i,char c);
t_count 	*is_what_kind(char tmp, t_map **map, t_count *count);
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

void   		ft_exit(t_map *map, char *msg);
int			ft_close(t_game *s_game);
/******************************************************************************/
/*									UTILS	  								  */
/******************************************************************************/

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
int			ft_strcmp(char *s1, char *s2);
t_map		*ft_lstnew(void *content);
t_map		*ft_lstlast(t_map *lst);
void		ft_lstadd_back(t_map **lst, t_map *new);
char		*ft_strdup_without_nl(const char *s);
int			ft_lstsize(t_map *lst);

/******************************************************************************/
/*									UTILS	  								  */
/******************************************************************************/

void    display_the_map(t_game *game, t_map **map);
void	image_init(t_game *game);
#endif