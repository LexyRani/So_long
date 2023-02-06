NAME = so_long
MLX_DIR = mlx
MLX_LIB = mlx_Linux
#Sources

#****************************PARSING**************************#
SRCS += Sources/Parsing/main.c
SRCS += Sources/Parsing/valid_map.c
SRCS += Sources/Parsing/valid_path.c
#SRCS += sources

#****************************MOVE*****************************#
#SRCS += sources
#SRCS += sources
#SRCS += sources
#SRCS += sources

#***************************Errors****************************#
#SRCS += sources
#SRCS += sources
SRCS += Sources/Errors/Exit.c

#****************************UTILS****************************#
SRCS += Sources/Utils/get_next_line/get_next_line.c
SRCS += Sources/Utils/get_next_line/get_next_line_utils.c
SRCS += Sources/Utils/ft_putendl_fd.c
SRCS += Sources/Utils/ft_putstr_fd.c
SRCS += Sources/Utils/ft_lstnew.c
SRCS += Sources/Utils/ft_lstlast.c
SRCS += Sources/Utils/ft_lstadd_back.c

OBJS = $(SRCS:.c=.o)

HEADER += Includes/so_long.h


#**************************Compilateurs***********************#
CC = cc
CFLAGS = -g -Wall -Wextra -Werror


#*****************************RULES***************************#

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
		$(MAKE) -C $(MLX_DIR)
		${CC} ${CFLAGS} ${SRCS} -I mlx -Lmlx -lmlx -lm -lXext -lX11 -o ${NAME} 
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I $(MLX_DIR) -o $@ -c $< 

clean:
		rm -f $(OBJS)
		$(MAKE) clean -C $(MLX_DIR)

fclean: clean
		rm -f $(NAME)
			

re: fclean all

.PHONY: all clean fclean re