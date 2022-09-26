CC = gcc
#CFLAGS = -Wall -Wextra -Werror
RACEFLAG = -g -fsanitize=thread
NAME = philo
SRCS = *.c

all : $(NAME)

$(NAME):
	$(CC) $(SRCS) -o $(NAME)

race :
	$(CC) $(SRCS) $(RACEFLAG) -o $(NAME)_race

clean :
	rm -rf $(NAME)

fclean : clean
	rm -rf $(NAME)_race

re : clean all

#WINDOWS COMPILE gcc -g -pthread *.c -o philo
