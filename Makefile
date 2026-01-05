NAME = philo
CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/main.c \
	   srcs/mem_man/frees.c \
	   srcs/parser/check.c \
	   srcs/parser/init.c \
	   srcs/parser/parser.c \
	   srcs/threads/routine.c \
	   srcs/utils/ft_atoi.c \
	   srcs/utils/ft_calloc.c \
	   srcs/utils/ft_strisnumeric.c \
	   srcs/time/time.c \
	   srcs/threads/join.c \
	   srcs/threads/monitor.c \



OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -g

.o:.c
	$(CC) $(CFLAGS) -c $< -o $@ -g

fclean: clean
	rm -f $(NAME) 
clean:
	rm -f $(OBJS)
re: fclean all

.PHONY: all clean fclean re
