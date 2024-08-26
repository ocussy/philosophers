NAME = philo
SRC_FILES = main.c \
			philo.c \

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