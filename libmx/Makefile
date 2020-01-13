.PHONY:	all install uninstall clean reinstall

CC 		= clang

FLAGS 	= -std=c11 -Wall -Werror -Wpedantic -Wextra

NAME 	= libmx.a

INC 	= libmx.h
INCD 	= inc

SRCDIR 	= src/

SRC 	= mx_isspace.c mx_printchar.c mx_print_unicode.c  mx_printstr.c mx_print_strarr.c mx_printint.c \
		mx_pow.c mx_sqrt.c mx_nbr_to_hex.c mx_hex_to_nbr.c mx_itoa.c mx_foreach.c mx_binary_search.c \
		mx_bubble_sort.c mx_quicksort.c mx_strlen.c mx_swap_char.c mx_str_reverse.c mx_strcmp.c \
		mx_strdel.c mx_del_strarr.c mx_get_char_index.c mx_strdup.c mx_strndup.c mx_strcpy.c mx_strncpy.c \
		mx_strnew.c mx_strcat.c mx_strstr.c mx_get_substr_index.c mx_count_substr.c mx_count_words.c \
		mx_strtrim.c mx_del_extra_spaces.c mx_strsplit.c mx_strjoin.c mx_file_to_str.c mx_strncmp.c \
		mx_replace_substr.c mx_memset.c mx_memcpy.c mx_memccpy.c mx_memcmp.c mx_memchr.c mx_memrchr.c \
		mx_memmem.c mx_memmove.c mx_realloc.c mx_create_node.c mx_push_front.c mx_push_back.c \
		mx_pop_front.c mx_pop_back.c mx_list_size.c mx_sort_list.c mx_displaylist.c mx_atoi.c mx_isdigit.c \
		mx_printerr.c mx_isalpha.c mx_del_intarr.c mx_get_file_length.c

OBJDIR 	= obj/

OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))

all: install uninstall

$(NAME): $(OBJDIR) $(OBJ)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)

$(OBJDIR):
		@mkdir $(OBJDIR)

$(OBJ): $(OBJDIR)%.o : $(SRCDIR)%.c
	@$(CC) $(FLAGS) -I $(INCD) -c $< -o $@

install: $(NAME)

clean:
	@rm -rf $(OBJDIR)

uninstall: clean
	@rm -rf $(NAME)

reinstall: uninstall install
