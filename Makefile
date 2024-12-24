NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files
SRC_DIR = src/
SRCS = $(SRC_DIR)ft_printf.c \
       $(SRC_DIR)ft_formats.c \
       $(SRC_DIR)ft_numbers.c

# Object files
OBJS = $(SRCS:.c=.o)

# Includes
INCLUDES = -I./includes

# External libraries
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

# Rules
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re