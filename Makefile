NAME = philo

CFILES = philo_util_0.c philo.c philo_util_1.c free_data.c

CFLAGS = -Wall -Wextra -Werror 
OBJS = $(CFILES:.c=.o)

#-fsanitize=address 
$(NAME):$(OBJS)
	cc $(CFLAGS) -fsanitize=address  $^ -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all