NAME = libftprintf.a

AR = ar
ARFLAGS = rcs

CC = cc
CCFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRC = ft_putchar.c ft_putnbr.c ft_putstr.c \
# src/ft_putnbr_hex src/ft_putnbr_hex src/ft_printf

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(ARFLAGS) $@ $^

%.o: %.c
	@$(CC) $(CCFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re