NAME = so_long
MLX_DIR = mlx
MLX_LIB = mlx_Linux

#--Source--s

#******************************************************************************#
#*									PARSING	  								  *#
#******************************************************************************#

SRCS += Sources/Parsing/main.c
SRCS += Sources/Parsing/valid_map_1.c
SRCS += Sources/Parsing/valid_map_2.c
SRCS += Sources/Parsing/valid_path.c
SRCS += Sources/Parsing/valid_path_2.c
SRCS += Sources/Parsing/make_array_chain.c

#******************************************************************************#
#*									GAME	  								  *#
#******************************************************************************#
SRCS += Sources/Game/game.c
SRCS += Sources/Game/init.c
SRCS += Sources/Game/len_tab.c
SRCS += Sources/Game/move.c
SRCS += Sources/Game/move_left.c
SRCS += Sources/Game/move_right.c
SRCS += Sources/Game/move_down.c
SRCS += Sources/Game/move_up.c

#******************************************************************************#
#*									ERRORS  								  *#
#******************************************************************************#
SRCS += Sources/Errors/Exit.c

#******************************************************************************#
#*									UTILS	  								  *#
#******************************************************************************#
SRCS += Sources/Utils/get_next_line/get_next_line.c
SRCS += Sources/Utils/get_next_line/get_next_line_utils.c
SRCS += Sources/Utils/ft_putendl_fd.c
SRCS += Sources/Utils/ft_putstr_fd.c
SRCS += Sources/Utils/ft_lstnew.c
SRCS += Sources/Utils/ft_lstlast.c
SRCS += Sources/Utils/ft_lstadd_back.c

OBJS = $(SRCS:.c=.o)

HEADER += Includes/so_long.h


#******************************************************************************/
#*									COMPILATEURS	  						  */
#******************************************************************************/
CC = cc
CFLAGS = -Wall -Wextra -Werror #-g3 #-fsanitize=address


#******************************************************************************/
#*									RULES	  								  */
#******************************************************************************/

#-- COLORS --#
NOC         = \033[0m
GREEN       = \033[1;32m
CYAN        = \033[1;36m
YELLOW		= \033[0;33m
BACK_WHITE  = \033[0;47;30m

all:  $(NAME) header

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

header:
	clear
	@echo " $(CYAN) $$HEADER_PROJECT $(NOC)" 

.PHONY: all clean fclean re

define HEADER_PROJECT                                                                       

                    888                            
 dP"Y  e88 88e      888  e88 88e  888 8e   e88 888 
C88b  d888 888b     888 d888 888b 888 88b d888 888 
 Y88D Y888 888P     888 Y888 888P 888 888 Y888 888 
d,dP   "88 88"      888  "88 88"  888 888  "88 888 
                888                         ,  88P 
                                           "8",P"  
                                                     
endef
export HEADER_PROJECT