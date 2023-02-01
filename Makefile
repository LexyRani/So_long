NAME = so_long

#Sources

#****************************PARSING**************************#
SRCS += Sources/Parsing/main.c
SRCS += Sources/Parsing/valid_map.c
#SRCS += sources
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
		${CC} ${SRCS} -o ${NAME} ${CFLAGS} ${INCLUDES_DIR}

%.o: %.c $(HEADER)
	$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDES_DIR)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)
			

re: fclean all

.PHONY: all clean fclean re