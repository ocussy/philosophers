# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/10 14:12:21 by ocussy            #+#    #+#              #
#    Updated: 2024/09/13 16:48:00 by ocussy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRC_FILES = philo.c \
			main.c \
			verif_data.c \
			init_philo.c \
			monitor.c \
			utils.c \
			eat.c \

OBJECTS = $(patsubst %.c, %.o, $(SRC_FILES))
INCLUDE = philo.h
CC = cc
FLAGS = -Wall -Wextra -Werror -O3 -g3
LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)libft.a

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C $(LIBFT_PATH)
	@$(CC) $(FLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

%.o: %.c $(INCLUDE)
	$(CC) $(FLAGS) -I$(LIBFT_PATH) -c $< -o $@

clean:
	@make clean -C $(LIBFT_PATH)
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
