# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dayun <dayun@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 14:48:38 by dayun             #+#    #+#              #
#    Updated: 2023/04/12 14:55:40 by dayun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=thread
RM = rm -f

NAME 		=	philo

SRCS		=	main.c \
				philo.c \
				init.c \
				utils.c \
				error.c \
				property.c \
				
OBJS		= $(SRCS:%.c=%.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o			:	%.c
		$(CC) $(CFLAGS) -c $^ -I./ -o $@

clean		:
		$(RM) $(OBJS)
		
fclean		:	clean
		$(RM) $(NAME)
		
re			:
		$(MAKE) fclean
		$(MAKE) all

.PHONY		:	all clean fclean re bonus
