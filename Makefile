NAME := fractol

SRC := main.c fractal.c keys.c helpers.c

SRCDIR := ./srcs

OBJDIR := objs

HEADER := -I minilibx_macos -I libft

MLIBXDIR := ./minilibx_macos

FRAME := -framework OpenGL -framework AppKit

LIBFTDIR := ./libft

OBJS := $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

CC := gcc

CFLAGS := -Wall -Werror -Wextra -c -g

.PHONY: all clean fclean re
.SUFFIXES: .c .o

all: $(NAME)

$(NAME): OBJS
		$(CC) $(OBJS) -o $(NAME) $(HEADER) -L $(LIBFTDIR) -lft -L $(MLIBXDIR) -lmlx $(FRAME) -O3

OBJS: LIB
		mkdir $(OBJDIR)
		$(CC) $(CFLAGS) $(SRC) $(HEADER)
		mv *.o $(OBJDIR)

LIB:
	make -C $(LIBFTDIR)
	make -C $(MLIBXDIR)
	rm -rf $(OBJDIR)

clean:
	make -C $(LIBFTDIR) clean
	make -C $(MLIBXDIR) clean
	rm -rf $(OBJDIR)

fclean: clean
		make -C $(LIBFTDIR) fclean
		make -C $(MLIBXDIR) clean
		rm -f $(NAME)

re: fclean all

