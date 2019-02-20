 #******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 13:17:38 by svovchyn          #+#    #+#              #
#    Updated: 2019/01/17 14:20:43 by dkozyr           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

CCFLAGS = -Wall -Wextra -Werror $(INC)
LIBFLAGS = -L $(LIBDIR) -lft -L $(MLXDIR)
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
LIB = $(LIBDIR)/libft.a

LIBDIR = ./libft
MLXDIR = ./minilibx
SRCDIR = ./src
OBJDIR = $(SRCDIR)/obj

SRC = main.c handle_keys.c read.c fdf.c draw_line.c draw_map.c interface.c \
		memory.c keys_action.c height.c colors.c utils.c
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
INC = -I $(LIBDIR)/inc -I $(SRCDIR) -I $(MLXDIR)

DEL = rm

all : $(NAME)

$(OBJDIR)/%.o : $(SRCDIR)/%.c
			@gcc -c $(CCFLAGS) $< -o $@ -I ./inc

$(NAME): $(OBJ)
		@$(MAKE) -C $(LIBDIR)
		@gcc $(CCFLAGS) $(LIB) $(OBJ) $(MLXFLAGS) -lm -o $(NAME)
		@echo "LIBRARY AND FDF COMPILED"


$(OBJ): | $(OBJDIR)

$(OBJDIR):
		@mkdir $(OBJDIR)

libcomp:
		@$(MAKE) -C $(LIBDIR)

mlxcomp:
		@$(MAKE) -C $(MLXDIR)

clean:
		@$(MAKE) -C $(LIBDIR) fclean
		@$(MAKE) -C $(MLXDIR) clean
		@$(DEL) -rf $(OBJDIR)
		@echo "LIBRARY AND OBJECTS DELETED"

fclean: clean
		@$(DEL) -f $(NAME)
		@echo "PROJECT IS CLEANED"	

re: fclean all