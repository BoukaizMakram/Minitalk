NAME = ft_printf.a

Include = ft_printf.h

Objects = ft_printf.o ft_extra.o

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(Objects) $(Include)
	ar rc $(NAME) $(Objects)

clean :
	rm -rf $(Objects)

fclean : clean
	rm -rf $(NAME)

re: fclean all