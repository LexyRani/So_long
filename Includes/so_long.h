/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:20:27 by aceralin          #+#    #+#             */
/*   Updated: 2023/02/19 20:18:42 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "../mlx/mlx.h"
# include <X11/keysym.h>

/* BUFFER*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define ERROR_ARG "Error: there must be only two arguments \
([./so_long] [path_map.ber])"
# define ERROR_EXT "Error: Your file is not .ber"
# define ERROR_FILE "Error: to open the file"
# define ERROR_MALLOC "Error: Malloc fail"
# define ERROR_EMPTY "Error: map is empty"
# define ERROR_REC "Error: map is not rectangle"
# define ERROR_CHAR "Error: char must be 0, 1, E, P, C"
# define ERROR_WALL "Error: map is missing wall"
# define ERROR_PATH "Error: map is not a valid path"

//#define ERROR "Error: Malloc or close fail"
//#define 
typedef struct s_coordinate
{
	int	y;
	int	x;	
}		t_coordinate;

typedef struct s_count
{
	int	p;
	int	e;
	int	c;
}			t_count;

typedef struct s_map
{
	char			*line;
	int				index;
	struct s_map	*prev;
	struct s_map	*next;
}						t_map;

typedef struct s_game
{
	t_map	**head_map;
	char	**map_game;
	int		x;
	int		y;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	void	*img_wall;
	void	*img_floor;
	void	*img_coin;
	void	*img_player;
	void	*img_exit;
	int		count_e;
	int		count_c;
	int		move;
}			t_game;

/******************************************************************************/
/*									PARSING	  								  */
/******************************************************************************/
/*________/MAIN\________*/
int			ft_arg_is_not_ber(char *s1, char *extension);
int			ft_check_map(t_map **map, int fd);

/*_____/VALID MAP_1\______*/
int			is_not_wall_framed(t_map **map);
int			valid_char(char c);
int			is_bad_char(t_map **map);

/*_____/VALID MAP_2\______*/
int			check_middle(t_map *map);
int			is_all_one( t_map *map);
int			is_not_rectangle(t_map **map);
void		ft_map_is_valid(t_game *game, t_map **map);

/*______/VALID PATH\_____*/
int			is_not_valid_count(t_map **map, t_count *count);
int			change_nextp(char **map, t_count *count, t_coordinate *coor);
int			is_what_kind(char tmp, t_count *count);
int			is_not_valid_path(t_game *game, t_map **map, t_count *count);

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

void		free_map(t_map *map);
int			free_game(t_game *game);
int			ft_close(t_game *s_game);
void		ft_exit(t_map *map, t_game *game, char *msg);
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
void		ft_putnbr_fd(int n, int fd);
/******************************************************************************/
/*									GAME	  								  */
/******************************************************************************/

/*_______/GAME\______*/
int			put_images(t_game *game);
void		display_the_map(t_game *game);
void		get_count(t_game *game);

//void	put_images(t_game *game);
void		*ft_convert_to_img(char *img, t_game *data);

/*_______/INIT\_______*/
void		image_init(t_game *game);
void		display_init(t_game *game);

/*_______/LEN_TAB\______*/

int			ft_len(char *s);
int			ft_len_tab(char **s);

/*______/PRINT_MAP\_____*/
//int	print_map(t_map *tmp);
//void 	print_double_array(char **array);
/******************************************************************************/
/*									MOVE	  								  */
/******************************************************************************/

int			ft_key_move( int key, t_game *game);
void		player_position(t_game *game);

/*left*/
void		move_if_c_left(t_game *game);	
void		move_if_0_left(t_game *game);
void		move_if_e_left(t_game *game);
void		ft_move_left(t_game *game);

/*rigth*/

void		move_if_c_rigth(t_game *game);	
void		move_if_0_right(t_game *game);
void		move_if_e_right(t_game *game);
void		ft_move_right(t_game *game);

/*down*/

void		move_if_c_down(t_game *game);	
void		move_if_0_down(t_game *game);
void		move_if_e_down(t_game *game);
void		ft_move_down(t_game *game);

/*up*/

void		move_if_c_up(t_game *game);	
void		move_if_0_up(t_game *game);
void		move_if_e_up(t_game *game);
void		ft_move_up(t_game *game);

#endif