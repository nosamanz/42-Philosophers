CC = gcc
CFLAGS = -Wall -Wextra -Werror
RACEFLAG = -g -fsanitize=thread
NAME = philo
SRCS = philo-mandatory/*.c

all : $(NAME)

$(NAME): $(SRCS)
	$(CC) $(SRCS) $(CFLAGS) -o $(NAME)

race : $(SRCS)
	$(CC) $(SRCS) $(RACEFLAG) -o $(NAME)_race

clean :
	rm -rf $(NAME)

fclean : clean
	rm -rf $(NAME)_race

re : clean all
