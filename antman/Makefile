##
## EPITECH PROJECT, 2023
## B-CPE-110-LYN-1-1-antman-yohann.mangenot
## File description:
## Makefile
##

SRC	=	antman.c	\
		init_node_list.c	\
		create_huffman_tree.c	\
		compress_txt.c	\
		compress_ppm.c	\
		make_compressed_file.c	\
		binary_file_conversion.c	\
		functions/count_item.c	\
		functions/find_frequency.c	\
		functions/insertion_sort.c	\
		functions/display_tree.c	\
		functions/error_manager.c	\
		functions/print_man.c	\
		functions/bin_to_int.c	\
		functions/extract_metadata.c	\
		functions/frees.c	\
		functions/my_strcat_size.c	\
		functions/file_size.c	\

NAME	=	antman

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
