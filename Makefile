# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 14:45:12 by xperrin           #+#    #+#              #
#    Updated: 2017/12/05 15:31:27 by bede-fre         ###   ########.fr        #
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
SRCDIR = src
OBJDIR = obj
INC = -Iincludes -Ilibft/includes \

# Files
SRCFILES =	helpers.c	\
			read.c		\
			solve.c		\
			print.c		\
			main.c
OBJFILES = $(SRCFILES:.c=.o)
OBJ = $(addprefix $(OBJDIR)/, $(OBJFILES))

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

.PHONY: libft all clean fclean re

all: libft $(OBJDIR) $(NAME)

libft:
	@echo $(LIBFTCOMPILE_MSG)
	@$(MAKE) -C $(LIBFTDIR) -j $(THREADS) --no-print-directory

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(FT)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
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
