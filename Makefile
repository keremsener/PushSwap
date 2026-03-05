# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/23 13:36:52 by ksener            #+#    #+#              #
#    Updated: 2026/03/05 11:55:58 by adede            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			=	push_swap

LIBFT_DIR		=	libft
LIBFT			=	$(LIBFT_DIR)/libft.a

INCLUDES		=	-I . -I $(LIBFT_DIR)

SRC				=	main.c \
					utils/printnode.c

SRC_COMMANDS	=	commands/sa.c \
					commands/sb.c \
					commands/ss.c \
					commands/pb.c \
					commands/pa.c \
					commands/ra.c \
					commands/rb.c \
					commands/rr.c \
					commands/rra.c \
					commands/rrb.c \
					commands/rrr.c

SRC_SORTS		=	sorts/simple/bublesort.c \
					sorts/simple/instertionsort.c \

SRCS			=	$(addprefix src/,$(SRC)) \
					$(addprefix src/,$(SRC_COMMANDS)) \
					$(addprefix src/,$(SRC_SORTS))

OBJS			=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) ${LIBFT}
	cc -Wall -Werror -Wextra $(INCLUDES) $^ -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	cc -Wall -Werror -Wextra $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
