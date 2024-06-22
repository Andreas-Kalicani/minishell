# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stripet <stripet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/25 21:27:44 by tienshi           #+#    #+#              #
#    Updated: 2023/10/13 16:22:12 by stripet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Flags = -Wall -Werror -Wextra

NAME = libft.a

AllSrc = $(Base)\
		$(Bonus)\
		$(Extra)\

Base =	ft_memset.c\
		ft_bzero.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strlen.c\
		ft_strlcpy.c\
		ft_strlcat.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strnstr.c\
		ft_strncmp.c\
		ft_atoi.c\
		ft_isalpha.c\
		ft_isdigit.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_calloc.c\
		ft_strdup.c\
		ft_substr.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_split.c\
		ft_itoa.c\
		ft_strmapi.c\
		ft_striteri.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
	

Bonus = ft_lstnew.c\
		ft_lstadd_front.c\
		ft_lstsize.c\
		ft_lstlast.c\
		ft_lstadd_back.c\
		ft_lstdelone.c\
		ft_lstclear.c\
		ft_lstiter.c\
		ft_lstmap.c\
		
Extra = ft_isspace.c\
		ft_abs.c\
		get_next_line_bonus.c\
		get_next_line_utils_bonus.c\
		ft_printf.c\
		printchar.c\
		printdecimal.c\
		printhexadecimall.c\
		printhexadecimalu.c\
		printinteger.c\
		printpointer.c\
		printstring.c\
		printunsigneddecimal.c\
		ft_split_free.c\
		ft_isint.c\
		ft_argv_to_str.c\

AllObj = $(BaseObj)\
		$(BonusObj)\
		$(ExtraObj)\

BaseObj = $(Base:%.c=%.o)

BonusObj = $(Bonus:%.c=%.o)

ExtraObj = $(Extra:%.c=%.o)

all:$(NAME)

$(NAME):$(AllObj)
	ar rcs	$(NAME) $(AllObj)

bonus:$(BonusObj)
	ar rcs	$(NAME) $(BonusObj)

$(AllObj):
	gcc $(Flags) -c $(AllSrc)

%: %.c
	gcc $(Flags) -c $(^)
	ar rcs $(NAME) $(^:%.c=%.o) 

clean:
	rm -f $(AllObj)

fclean:
	rm -f $(NAME)
	make clean

re:
	@make fclean
	@make all
	@echo "Recompiled everything"

debug:
	make fclean
	gcc $(Flags) -g -c $(AllSrc)
	make $(NAME)
