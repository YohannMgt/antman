##
## EPITECH PROJECT, 2023
## B-CPE-110-LYN-1-1-antman-yohann.mangenot
## File description:
## Makefile
##

SRC	=	giantman.c	\
		decompress_txt.c	\
		decompress_ppm.c	\
		create_huffman_tree.c	\
		functions/error_manager.c	\
		functions/print_man.c	\
		functions/insertion_sort.c	\
		functions/display_tree.c	\
		functions/generate_dict.c	\
		functions/generate_node_list.c	\
		functions/my_strcat_size.c	\
		functions/int_to_bin.c	\
		functions/size_check_txt.c	\
		functions/find_pos.c	\
		functions/create_sequence.c	\
		functions/file_size.c	\

NAME	=	giantman

LIBS = -L./lib/ -lmy

FLAGS = -Wall

$(NAME):	$(SRC) cpl
	gcc -o $(NAME) $(SRC) $(LIBS)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f *.out

cpl:
	cd lib && make && cd ..

re: cpl fclean all

run:
	@gcc -o $(NAME) $(SRC) $(LIBS) $(CSFML)
	@./$(NAME) $(ARGS)
