NAME = philo

CFILES = philo_util_0.c philo.c philo_util_1.c

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

OBJS = $(CFILES:.c=.o)

$(NAME):$(OBJS)
	cc $(CFLAGS) $^ -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all