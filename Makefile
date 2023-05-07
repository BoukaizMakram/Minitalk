
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mboukaiz <mboukaiz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/06 00:33:56 by mboukaiz          #+#    #+#              #
#    Updated: 2023/05/06 01:06:07 by mboukaiz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PrintfObjects = ft_printf.o ft_extra.o

Include = ft_printf.h

Code = server.c client.c server_bonus.c client_bonus.c

CFLAGS = -Wall -Wextra -Werror

CC = cc

NAME = client server

NAME_B = client_bonus server_bonus

all : $(NAME) 

bonus : server_bonus client_bonus

client : client.o libftprintf.a
	$(CC) $(CFLAGS) libftprintf.a  client.o -o $@

server : server.o libftprintf.a
	$(CC) $(CFLAGS) libftprintf.a server.o -o $@

server_bonus : server_bonus.o libftprintf.a
	$(CC) $(CFLAGS) libftprintf.a server_bonus.o -o $@

client_bonus : client_bonus.o libftprintf.a
	$(CC) $(CFLAGS) libftprintf.a client_bonus.o -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $<

libftprintf.a : $(PrintfObjects) $(Include)
	ar rc libftprintf.a $(PrintfObjects)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME) $(NAME_B) *.a

re: fclean all
