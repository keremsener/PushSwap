# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/23 13:36:52 by ksener            #+#    #+#              #
#    Updated: 2026/03/05 13:04:02 by ksener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

SRC_SORTS		=	simple/bublesort.c \
					simple/instertionsort.c \
					simple/selectionsort.c \

SRC_UTILS		=	printnode.c \
					get_value.c

SRCS			=	$(addprefix src/,$(SRC)) \
					$(addprefix src/commands/,$(SRC_COMMANDS)) \
					$(addprefix src/sorts/,$(SRC_SORTS)) \
					$(addprefix src/utils/,$(SRC_UTILS))

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
