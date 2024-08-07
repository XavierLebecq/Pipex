#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 18:00:37 by xlebecq           #+#    #+#              #
#    Updated: 2024/08/07 16:26:17 by xlebecq          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lib.a

CC = clang

CFLAGS = -Wall -Wextra -Werror -g3

RM = rm -f

HEADER = -I.

SRC_DIR = ./src/

SRC = $(addprefix $(SRC_DIR), $(C_FILE))

C_FILE = ft_addfunctions.c ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_lstadd_front.c ft_lstnew.c ft_lstsize.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstclear.c ft_lstlast.c ft_lstadd_back.c ft_printf.c get_next_line.c get_next_line_bonus.c get_next_line_utils_bonus.c get_next_line_utils.c
		
OBJ = $(SRC:.c=.o)

OBJ_PATH		= .obj/

OBJ_DIR			= $(addprefix $(OBJ_PATH), $(OBJ))


all: $(NAME)

$(NAME): $(OBJ_DIR)
	ar rcs $(NAME) $(OBJ_DIR)
		ranlib $(NAME)

$(OBJ_PATH)%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADER)

clean:
	$(RM) $(OBJ_DIR)
	$(RM) -r $(OBJ_PATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
