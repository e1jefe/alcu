CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SOURCE = ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_isnumber.c \
		ft_toupper.c \
		ft_touppers.c \
		ft_tolower.c \
		ft_tolowers.c \
		ft_isalpha.c \
		ft_strdup.c \
		ft_strndup.c \
		ft_atoi.c \
		ft_atoi_base.c \
		ft_strlen.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_memset.c \
		ft_memcpy.c \
		ft_bzero.c \
		ft_memccpy.c \
		ft_memcmp.c \
		ft_memchr.c \
		ft_memmove.c \
		ft_strlcat.c \
		ft_memalloc.c \
		ft_strnew.c \
		ft_memdel.c \
		ft_strclr.c \
		ft_strdel.c \
		ft_strdel2.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strrev.c \
		ft_strtrim.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_itoa.c \
		ft_itoa_base.c \
		ft_utoa.c \
		ft_utoa_base.c \
		ft_lltoa.c \
		ft_lltoa_base.c \
		ft_ulltoa.c \
		ft_ulltoa_base.c \
		ft_strsplit.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstaddtail.c \
		ft_abs.c \
		ft_swap.c \
		ft_cswap.c \
		ft_arrintsort.c \
		ft_pow.c \
		ft_max.c \
		ft_min.c \
		ft_sqrt.c \
		ft_round.c \
		ft_unictoa.c \
		ft_count_words.c \
		get_next_line.c \
		freetab.c \
		t_info.c

OBJECTS = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<

.PHONY: all clean fclean re

.NOTPARALLEL: all clean fclean re
