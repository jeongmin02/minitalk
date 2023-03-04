# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jerhee <jerhee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/04 19:14:41 by jerhee            #+#    #+#              #
#    Updated: 2023/03/04 19:29:27 by jerhee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLALGS = -Wall -Werror -Wextra
NAME = client
CLIENT_M = client
SERVER_M = server
CLIENT_B = client_bonus
SERVER_B = server_bonus
SRCS_C = client.c utils.c
SRCS_S = server.c utils.c
OBJS_C = $(SRCS_C:.c=.o)
OBJS_S = $(SRCS_S:.c=.o)
SRCS_C_BONUS = client_bonus.c utils_bonus.c
SRCS_S_BONUS = server_bonus.c utils_bonus.c
OBJS_C_BONUS = $(SRCS_C_BONUS:.c=.o)
OBJS_S_BONUS = $(SRCS_S_BONUS:.c=.o)

ifdef WITH_BONUS
	OBJS_FILE_C = $(OBJS_C_BONUS)
	OBJS_FILE_S = $(OBJS_S_BONUS)
	CLIENT = $(CLIENT_B)
	SERVER = $(SERVER_B)
else
	OBJS_FILE_C = $(OBJS_C)
	OBJS_FILE_S = $(OBJS_S)
	CLIENT = $(CLIENT_M)
	SERVER = $(SERVER_M)

endif

all : $(NAME)

$(NAME) : $(OBJS_FILE_C) $(OBJS_FILE_S)
	$(CC) $(OBJS_FILE_C) -o $(CLIENT)
	$(CC) $(OBJS_FILE_S) -o $(SERVER)

bonus : $(OBJS_C_BONUS) $(OBJS_S_BONUS)
	make WITH_BONUS=1 all

clean :
	rm -f $(OBJS_C) $(OBJS_S) $(OBJS_C_BONUS) $(OBJS_S_BONUS)

fclean : clean
	rm -f $(CLIENT_M) $(SERVER_M) $(CLIENT_B) $(SERVER_B) $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re