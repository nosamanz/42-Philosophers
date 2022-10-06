CC = gcc
CFLAGS = -Wall -Wextra -Werror
RACEFLAG = -g -fsanitize=thread
NAME = philo_bonus
SRCS = *.c

all : $(NAME)

$(NAME): $(SRCS)
	$(CC) $(SRCS) $(CFLAGS) -o $(NAME)

clean :
	rm -rf $(NAME)

fclean : clean
	rm -rf $(NAME)

bonus : all

re : clean all
