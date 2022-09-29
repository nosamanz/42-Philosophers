CC = gcc
CFLAGS = -Wall -Wextra -Werror
RACEFLAG = -g -fsanitize=thread
NAME = philo.a
SRCS = philo/*.c

BONUS = philo_bonus/*.c
B_NAME = philo_bonus.a

all : $(NAME)

$(NAME): $(SRCS)
	$(CC) $(SRCS) $(CFLAGS) -o $(NAME)

race : $(SRCS)
	$(CC) $(SRCS) $(RACEFLAG) -o $(NAME)_race

bonus : $(BONUS)
	$(CC) $(BONUS) $(CFLAGS) -o $(B_NAME)

bonusrace : $(BONUS)
	$(CC) $(BONUS) $(RACEFLAG) -o bonus_race

clean :
	rm $(NAME)

fclean : clean
	rm -rf $(NAME)_race
	rm -rf philo_race.dSYM

re : clean all
