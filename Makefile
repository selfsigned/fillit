# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 14:45:12 by xperrin           #+#    #+#              #
#    Updated: 2017/12/12 16:10:04 by bede-fre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = clang
##### Final Cflags:
##### CFLAGS = -Wall -Wextra -Werror
##### Debug Cflags
CFLAGS = -Wall -Wextra -g -fsanitize=address

# Directories
LIBFTDIR = libft
FT = -L$(LIBFTDIR) -lft
INC = -I. -I$(LIBFTDIR)
INCFILES = fillit.h libft/libft.h

# Files
SRC =	helpers.c	\
	read.c		\
	parse_move.c	\
	solve.c		\
	solvefun.c	\
	print.c		\
	main.c
OBJ = $(SRC:.c=.o)
LIBAR = $(LIBFTDIR)/libft.a

# Threads
OS = $(shell uname)
ifeq ($(OS), Darwin)
	THREADS = $(shell sysctl -n hw.ncpu)
else ifeq ($(OS), Linux)
	THREADS = $(shell nproc)
else
	THREADS = 2
endif

# MSGS
LIBFTCOMPILE_MSG = "Compiling the libft with $(THREADS) threads."
LIBFTCLEAN_MSG = "Removing the libft objects"
OBJCLEAN_MSG = "Removing the objectsy"

.PHONY: all clean fclean re

all: $(NAME)

$(LIBAR):
	@echo $(LIBFTCOMPILE_MSG)
	@$(MAKE) -C $(LIBFTDIR) -j $(THREADS) --no-print-directory

$(NAME): $(LIBAR) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(FT)

%.o: %.c $(INCFILES)
	$(CC) $(CFLAGS) -c -o $@ $< $(INC)

# Cleanup

clean:
	@echo $(LIBFTCLEAN_MSG).
	@$(MAKE) clean -C $(LIBFTDIR) --no-print-directory
	@echo  $(OBJCLEAN_MSG).
	$(RM) $(OBJ)

fclean:
	@echo "$(LIBFTCLEAN_MSG) and archive."
	@$(MAKE) fclean -C $(LIBFTDIR) --no-print-directory
	@echo "$(OBJCLEAN_MSG) and the binary."
	$(RM) $(OBJ) $(NAME)

re: fclean all
