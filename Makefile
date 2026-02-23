# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/23 13:36:52 by ksener            #+#    #+#              #
#    Updated: 2026/02/23 21:30:37 by ksener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	push_swap.a

LIBFT_DIR	=	LibFT
LIBFT		=	$(LIBFT_DIR)/libft.a

SRC	=	sa.c \
		sb.c \
		ss.c \
		pb.c \
		pa.c \
		ra.c \
		rb.c \
		rr.c \
		rra.c \
		rrb.c

OBJ	=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): ${LIBFT} $(OBJ)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)
	
$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c libft.h
	cc -Wall -Werror -Wextra -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re