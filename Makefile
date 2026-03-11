# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/23 13:36:52 by ksener            #+#    #+#              #
#    Updated: 2026/03/12 02:03:53 by adede            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =========================================
# ANSI Escape Sequences
# =========================================

# Basic
ESC				:=	\033
RESET			:=	$(ESC)[0m

# Colors
GREEN			:=	$(ESC)[0;32m
YELLOW			:=	$(ESC)[0;33m
RED				:=	$(ESC)[0;31m
BLUE			:=	$(ESC)[0;34m

# Text Styles
BOLD			:=	$(ESC)[1m
DIM				:=	$(ESC)[2m
INVERSE			:=	$(ESC)[7m

# =========================================
# Sample testing
# =========================================

STRATEGY		=	adaptive
AMOUNT			=	100

# =========================================
# Compilation
# =========================================

NAME 			=	push_swap

LIBFT_DIR		=	libft
LIBFT			=	$(LIBFT_DIR)/libft.a

INCLUDES		=	-I . -I $(LIBFT_DIR)

SRC				=	main.c

SRC_COMMANDS	=	sa.c \
					sb.c \
					ss.c \
					pb.c \
					pa.c \
					ra.c \
					rb.c \
					rr.c \
					rra.c \
					rrb.c \
					rrr.c

SRC_SORTS		=	simple/buble_sort.c \
					simple/instertion_sort.c \
					simple/selection_sort.c \
					medium/chunk_sort.c

SRC_UTILS		=	print_stack.c \
					get_value.c \
					compute_disorder.c \
					get_int.c \
					print_bench.c

SRCS			=	$(addprefix src/,$(SRC)) \
					$(addprefix src/commands/,$(SRC_COMMANDS)) \
					$(addprefix src/sorts/,$(SRC_SORTS)) \
					$(addprefix src/utils/,$(SRC_UTILS))

OBJS			=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): ${LIBFT} $(OBJS)
	@printf "$(GREEN)$(BOLD)[$(NAME)]$(RESET)"
	@printf "$(GREEN) Linking$(RESET)\n"
	@cc -Wall -Werror -Wextra $(INCLUDES) $(OBJS) $(LIBFT) -o $@

$(LIBFT):
	@printf "$(BLUE)$(BOLD)[$(LIBFT_DIR)]$(RESET)"
	@printf "$(BLUE) Creating library$(RESET)\n"
	@$(MAKE) -s -C $(LIBFT_DIR)

%.o: %.c
	@printf "$(DIM)$(BOLD)[$(NAME)]$(RESET)"
	@printf "$(DIM) Compiling $<$(RESET)\n"
	@cc -Wall -Werror -Wextra $(INCLUDES) -c $< -o $@

clean:
	@printf "$(YELLOW)Cleaning objects$(RESET)\n"
	@rm -f $(OBJS)
	@$(MAKE) -s -C $(LIBFT_DIR) clean

fclean: clean
	@printf "$(RED)Cleaning all$(RESET)\n"
	@rm -f $(NAME)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean

re: fclean all

samples/%.txt:
	@shuf -i 0-9999 -n $(AMOUNT) > $@;

test: samples/$(AMOUNT).txt
	@$(MAKE) -s > /dev/null
	@./$(NAME) --$(STRATEGY) --bench $$(cat $<)

.PHONY: all clean fclean re test
