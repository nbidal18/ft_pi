CC = CC
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
UTILS = utils
MANDATORY_SOURCES = $(UTILS)/ft_printf.c $(UTILS)/ft_putchar.c $(UTILS)/ft_puthex_up.c $(UTILS)/ft_puthex.c $(UTILS)/ft_putnbr_u.c $(UTILS)/ft_putnbr.c $(UTILS)/ft_putptr.c $(UTILS)/ft_putstr.c $(UTILS)/ft_specifiers.c
MANDATORY_OBJECTS = $(MANDATORY_SOURCES:.c=.o)
HEADER = ft_printf.h

all: $(NAME)

$(NAME): $(MANDATORY_OBJECTS)
	ar rc $(NAME) $(MANDATORY_OBJECTS)
	ranlib $(NAME)

%.o:%.c ${HEADER}
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(MANDATORY_OBJECTS)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re