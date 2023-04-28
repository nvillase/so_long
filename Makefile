NAME = so_long
CC = gcc
CCFLAG = -g -Wall -Wextra -Werror
LIB = ./include/libft/libft.a
MLX = ./include/mlx/libmlx.a
RM = rm -f
SRCS =  calcul.c \
		create_map.c \
		key.c \
		main.c
OBJS = $(SRCS:.c=.o)
CMD = -L ./include/libft/ -lft -L ./include/mlx -lmlx -lXext -lX11 -lm -lbsd

all: ${MLX} $(LIB) $(NAME)

${MLX}:
		make -s -C ./include/mlx/ all
$(LIB):
	make -C ./include/libft/ all

.c.o:
	$(CC) $(CCFLAG) $(CMD) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CCFLAG) $(OBJS) $(CMD) -o $(NAME)

clean:
	$(RM) $(OBJS)
	make -s -C ./include/mlx/ clean
	make -C ./include/libft/ clean

fclean: clean
	$(RM) $(NAME)

re: fclean all
 
