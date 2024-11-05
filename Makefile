# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/31 11:28:17 by drabadan          #+#    #+#              #
#    Updated: 2024/11/05 16:14:39 by drabadan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I $(LIBFT_DIR)
SRC = *.c
OBJ = $(SRC:.c = .o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	cc $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) $(INCLUDES)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean:
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME) 

re: fclean all

.PHONY: all re fclean clean
