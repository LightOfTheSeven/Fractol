.PHONY: all clean fclean re bonus

NAME	=	fractol
CC		=	clang
FLAGS	=	-O3 -Wall -Wextra -Werror
INC		=	include
OBJ		=	objs
SRC		=	sources
LIBMLX 	=	libmlx
INCS	=	$(addprefix $(INC)/, fractol.h)
OBJS	=	$(addprefix $(OBJ)/, $(SRCS:.c=.o))
SRCS 	=	main.c \
		color.c \
		draw.c \
		exit.c \
		hook.c \
		hook_utils.c \
		init.c \
		maths.c \
		utils.c \

all: bonus $(NAME)

bonus:
	mkdir -p $(OBJ)
	make -C $(LIBMLX)

$(NAME): $(OBJS) $(INCS)
	$(CC) $(FLAGS) -I$(INC) -o $(NAME) $(OBJS) -Llibmlx -lmlx -lX11 -lbsd -lm -lXext

$(OBJ)/%.o: $(SRC)/%.c $(INCS)
	$(CC) $(FLAGS) -I$(INC) -c $< -o $@

clean:
	rm -rf $(OBJ)
	make -C $(LIBMLX) clean

fclean: clean
	rm -rf $(NAME)

re: fclean all
