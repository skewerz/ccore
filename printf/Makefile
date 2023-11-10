NAME	= libftprintf.a

SRCS	= ./sources/ft_printf.c \
	   	./sources/print_char.c \
		./sources/print_digit.c \
		./sources/print_format.c \
		./sources/print_pointer.c \
		./sources/print_str.c \
		./sources/print_unsigned.c \
		./sources/print_xc.c \
		./sources/print_xl.c \

RED=\033[31m
YELLOW=\033[33m
GREEN=\033[32m
CYAN=\033[36m
BLUE=\033[34m
MAGENTA=\033[35m
RESET=\033[0m

OBJS	= $(SRCS:.c=.o)

CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJS)

fclean:		clean
	@$(RM) $(NAME)
	@echo "$(RED)DOSYALARIN SİLİNDİ$(RESET)"

re:			fclean all

.PHONY:		all clean fclean re