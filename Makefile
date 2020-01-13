.PHONY: all install clean uninstall reinstall

NAME	=	pathfinder

CC 		= 	clang

FLAGS	=	-std=c11 -Wall -Wextra -Werror -Wpedantic

SRCDIR	=	./src/

INCDIR	=	./inc/

OBJDIR	=	./obj/

INC		=	pathfinder.h

SRC		= 	main.c mx_count_set.c mx_create_l.c mx_create_island.c mx_pI.c \
			mx_pop_front_island.c mx_pop_middle_island.c \
			mx_addIndexPathes.c mx_sortPath.c mx_join.c \
			mx_printOutput.c mx_delMat.c mx_create_path.c \
			mx_delPath.c mx_addPath.c mx_pushPath.c mx_copyPath.c \
			mx_uniquePath.c mx_check_empty_line.c mx_errors.c mx_parse.c \
			mx_create_arrarr.c mx_create_set.c mx_create_matrix.c \
			mx_print_mat.c mx_algo.c mx_shortest.c

OBJ		=	$(addprefix $(OBJDIR), $(SRC:.c=.o))

LIB 	= libmx.a

LIBDIR 	= ./libmx/

all: install clean

install: $(NAME)

$(NAME): $(OBJDIR) $(OBJ) $(LIBDIR)$(LIB)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBDIR)/$(LIB)

$(OBJ): $(OBJDIR)%.o : $(SRCDIR)%.c
	@$(CC) -o $@ -c $< $(FLAGS) -I $(INCDIR)

$(LIBDIR)$(LIB):
	@make -sC $(LIBDIR)

$(OBJDIR):
	@mkdir $(OBJDIR)

clean:
	@make -sC $(LIBDIR) $@
	@rm -rf $(OBJDIR)

uninstall: clean
	@make -sC $(LIBDIR) $@
	@rm -rf $(NAME)

reinstall: uninstall install
