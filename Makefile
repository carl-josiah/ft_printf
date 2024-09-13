NAME = libftprintf.a

AR = ar
ARFLAGS = rcs

CC = cc
CCFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRC = ft_printf ft_putchar ft_putnbr_hex ft_putnbr ft_putptr ft_putstr

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(ARFLAGS) $@ $^

%.o: %.c
	@$(CC) $(CCFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re