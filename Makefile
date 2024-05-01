NAME = push_swap
BNAME = checker
CFILES = mandatory/main.c mandatory/operations_part1.c mandatory/operations_part2.c mandatory/operations_part_3.c mandatory/oper_before_push.c mandatory/swap.c mandatory/utils_1.c mandatory/utils_2.c mandatory/utils_3.c mandatory/utils_4.c mandatory/moves_a_to_b.c mandatory/moves_b_to_a.c 
OFILES = $(CFILES:.c=.o)
BCFILES = bonus/main_bonus.c bonus/utils1_bonus.c bonus/utils2_bonus.c bonus/utils3_bonus.c bonus/operations_part1_bonus.c bonus/operations_part2_bonus.c bonus/operations_part3_bonus.c bonus/get_next_line.c bonus/get_next_line_utils.c
BOFILES = $(BCFILES:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -o $(NAME) 

bonus: $(BNAME)

$(BNAME): $(BOFILES)
	$(CC) $(CFLAGS) $(BOFILES) -o $(BNAME)

clean: 
	rm -f $(OFILES) $(BOFILES)

fclean: clean
	rm -f $(NAME) $(BNAME)

re: fclean all

phony: all clean fclean re 