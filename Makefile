NAME = push_swap
CC = cc

PRINTF_DIR = srcs/printf
PRINTF = $(PRINTF_DIR)/libftprintf.a
LIBFT_DIR = srcs/libft
LIBFT = $(LIBFT_DIR)/libft.a
CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/main.c \
	   srcs/stack_methods/push.c \
	   srcs/stack_methods/rotate.c \
	   srcs/stack_methods/rrotate.c \
	   srcs/stack_methods/swap.c \
	   srcs/stack_methods/check.c \
	   srcs/parser/parser_utils.c \
	   srcs/parser/parser.c \
	   srcs/stack_methods/new.c \
	   srcs/parser/checker.c \
	   srcs/mem_man/freeall.c \
	   srcs/solver/solver.c \
	   srcs/stack_methods/solvemethods/extremum.c \
	   srcs/stack_methods/solvemethods/interval.c \
	   srcs/stack_methods/solvemethods/cost.c \
	   srcs/stack_methods/solvemethods/cost_utils.c \
	   srcs/stack_methods/solvemethods/placer.c \


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) $(LIBFT) -o $(NAME) -g

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@ -g

fclean: clean
	rm -f $(NAME) && $(MAKE) fclean -C $(LIBFT_DIR) && $(MAKE) fclean -C $(PRINTF_DIR)


clean:
	rm -f $(OBJS) && $(MAKE) clean -C $(LIBFT_DIR) && $(MAKE) clean -C $(PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re
