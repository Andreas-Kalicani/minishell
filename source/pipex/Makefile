Name = pipex
CFLAGS = -Wall -Werror -Wextra
Libraries = -lft -L ../libft

src_dir = ./source
src = $(src_dir)/errors_bonus.c\
      $(src_dir)/pipex_bonus.c\
      $(src_dir)/utils_bonus.c\

obj = $(src:.c=.o)

all: $(Name)

$(Name):$(obj)
	gcc $(Libraries) $^ -o $@

clean:
	rm -f $(src_dir)/*.o

fclean: clean
	rm -f $(Name)

re: fclean all