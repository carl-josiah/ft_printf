NAME = libftprintf.a

AR = ar
ARFLAGS = rcs

CC = cc
CCFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRC = ft_printf.c \
	ft_putchar.c \
	ft_putnbr.c \
	ft_putstr.c \
	ft_puthex_low.c \
	ft_puthex_upp.c \
	ft_putptr.c \
	ft_putnbr_uns.c \

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