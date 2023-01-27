##
## EPITECH PROJECT, 2023
## B-CPE-110-LYN-1-1-antman-yohann.mangenot
## File description:
## Makefile
##

all:
	cd antman/ && make && cd ../giantman/ && make && cd ..

clean:
	cd antman/ && clean && cd ../giantman/ && clean && cd ..

fclean:	clean
	cd antman/ && fclean && cd ../giantman/ && fclean && cd ..

re:
	cd antman/ && re && cd ../giantman/ && re && cd ..
