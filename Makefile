# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkobeliev <rkobeliev@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/17 20:46:44 by rkobeliev         #+#    #+#              #
#    Updated: 2024/06/17 16:06:07 by rkobeliev        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc

CFLAGS = -Werror -Wall -Wextra

RM = rm -rf

SRCS = 	pipex.c\
		pipex_utils.c\
		pipex_libft_utils.c\
		ft_split.c\

$(NAME) :
	gcc $(CFLAGS) $(SRCS) -o $(NAME)


all : $(NAME)

clean :
	$(RM) $(NAME)

fclean : clean
	$(RM) $(NAME)
	
re : fclean all

