LIBFT		=		./libft/libft.a

NAME		=		libftprintf.a

SRCS		=		ft_printf.c \
					ft_manage_flags.c \
					ft_manage_convs.c \
					ft_conv_utils.c \
					ft_print_characters.c \
					ft_print_decimal.c \
					ft_print_hexa.c \
					ft_print_pointers.c
		
OBJS		=		${SRCS:.c=.o}

CC			=		gcc

FLAGS		=		-c -Wall -Wextra -Werror

$(NAME) : 	$(OBJS)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all :		$(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS)

fclean :	clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re :		fclean all

.PHONY :	all fclean clean re