CC = gcc
NAME = minishell
BONUS_NAME = minishell_bonus
CFLAGS = -Wall -Werror -Wextra
Libraries = -lft -L ./libft

src_dir = ./source
bonus_dir = ./source_bonus
src = 	$(src_dir)/minishell.c\

bonus_src =

obj = $(src:.c=.o)
bonus_obj = $(bonus_src:.c=.o)

all: $(NAME)

$(NAME):$(obj)
	cc $(Libraries) $^ -o $@

bonus:$(bonus_obj)
	cc $(Libraries) $^ -o $(BONUS_NAME)

clean:
	rm -f $(src_dir)/*.o
	rm -f $(bonus_dir)/*.o

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all

bre: fclean bonus

debug:
	gcc -g $(CFLAGS) $(Libraries) $(src) -o $(NAME)

bdebug:
	gcc -g $(CFLAGS) $(Libraries) $(bonus_src) -o $(NAME)

sanitize:
	gcc -g -fsanitize=address $(CFLAGS) $(Libraries) $(src) -o $(NAME)

bsanitize:
	gcc -g -fsanitize=address $(CFLAGS) $(Libraries) $(bonus_src) -o $(NAME)

test:
	@printf 'begining of sanitize tests\n'
	@make sanitize
	@printf '\n'
	-./$(NAME)
	@printf '\n'
	-./$(NAME) wrong
	@printf '\n'
	-./$(NAME) 1
	@printf '\n'
	-./$(NAME) 1 wrong 2 3
	@printf '\n'
	-./$(NAME) 1 2 5 2 1
	@printf '\n'
	-./$(NAME) "1" "wrong" "2" "3"
	@printf '\n'
	-./$(NAME) "1" "2" "5" "2" "1"

	@printf '\n'
	-./$(NAME) "0 1 2 3 4 5 6 7 8 9 10" | wc -l
	ARG="0 1 2 3 4 5 6 7 8 9 10"; ./push_swap $$ARG | ./checker_Mac $$ARG
	@printf '\n'
	-./$(NAME) "10 9 8 7 6 5 4 3 2 1 0" | wc -l
	ARG="10 9 8 7 6 5 4 3 2 1 0"; ./push_swap $$ARG | ./checker_Mac $$ARG
	@printf '\n'
	-./$(NAME) "4 67 3 87 23" | wc -l
	ARG="4 67 3 87 23"; ./push_swap $$ARG | ./checker_Mac $$ARG
	@printf '\n'

	@printf 'End of sanitize tests\n\n\n\n\n\n\n\n\n'

	@printf 'begining of leaks tests\n'
	@make re
	@printf '\n'
	-Leaks --atExit --quiet -- ./$(NAME)
	@printf '\n'
	-Leaks --atExit --quiet -- ./$(NAME) wrong
	@printf '\n'
	-Leaks --atExit --quiet -- ./$(NAME) 1
	@printf '\n'
	-Leaks --atExit --quiet -- ./$(NAME) 1 wrong 2 3
	@printf '\n'
	-Leaks --atExit --quiet -- ./$(NAME) 1 2 5 2 1
	@printf '\n'
	-Leaks --atExit --quiet -- ./$(NAME) "1" "wrong" "2" "3"
	@printf '\n'
	-Leaks --atExit --quiet -- ./$(NAME) "1" "2" "5" "2" "1"

	@printf '\n'
	-Leaks --atExit --quiet -- ./$(NAME) "0 1 2 3 4 5 6 7 8 9 10"
	ARG="0 1 2 3 4 5 6 7 8 9 10"; ./push_swap $$ARG | ./checker_Mac $$ARG
	@printf '\n'
	-Leaks --atExit --quiet -- ./$(NAME) "10 9 8 7 6 5 4 3 2 1 0"
	ARG="10 9 8 7 6 5 4 3 2 1 0"; ./push_swap $$ARG | ./checker_Mac $$ARG
	@printf '\n'
	-Leaks --atExit --quiet -- ./$(NAME) "4 67 3 87 23"
	ARG="4 67 3 87 23"; ./push_swap $$ARG | ./checker_Mac $$ARG
	@printf '\n'

	@printf 'end of leaks tests\n'
