# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 14:45:12 by xperrin           #+#    #+#              #
#    Updated: 2017/12/07 18:20:54 by xperrin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = clang
##### Final Cflags:
##### CFLAGS = -Wall -Wextra -Werror
##### Debug Cflags
CFLAGS = -Wall -Wextra -g #-fsanitize=address

# Directories
LIBFTDIR = libft
FT = -L$(LIBFTDIR) -lft
SRCDIR = src
OBJDIR = obj
INC = -Iincludes -Ilibft/includes
INCFILES =	includes/fillit.h \
		libft/includes/libft.h \

# Files
SRCFILES =	helpers.c	\
		read.c		\
		move_checks.c	\
		solve.c		\
		print.c		\
		main.c
OBJFILES = $(SRCFILES:.c=.o)
OBJ = $(addprefix $(OBJDIR)/, $(OBJFILES))
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
OBJCLEAN_MSG = "Removing the object directory"

.PHONY: all clean fclean re

all: $(NAME)

$(LIBAR):
	@echo $(LIBFTCOMPILE_MSG)
	@$(MAKE) -C $(LIBFTDIR) -j $(THREADS) --no-print-directory

$(NAME): $(LIBAR) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(FT)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCFILES)
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $< $(INC)

# Cleanup

clean:
	@echo $(LIBFTCLEAN_MSG).
	@$(MAKE) clean -C $(LIBFTDIR) --no-print-directory
	@echo  $(OBJCLEAN_MSG).
	$(RM) -r $(OBJDIR)

fclean:
	@echo "$(LIBFTCLEAN_MSG) and archive."
	@$(MAKE) fclean -C $(LIBFTDIR) --no-print-directory
	@echo "$(OBJCLEAN_MSG) and the binary."
	$(RM) -r $(OBJDIR) $(NAME)

re: fclean all
