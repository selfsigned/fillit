# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/26 20:55:13 by xperrin           #+#    #+#              #
#    Updated: 2017/11/28 23:09:41 by xperrin          ###   ########.fr        #
#                                                                              #
# ****************************************************************************a#

NAME = fillit
CC = clang
CFLAGS = -Wall -Wextra -Werror

# Directories
LIBFTDIR = libft
FT = -L$(LIBFTDIR) -lft
SRCDIR = src
OBJDIR = obj
INC = -Iincludes -Ilibft/includes \

# Files
SRCFILES = main.c
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
