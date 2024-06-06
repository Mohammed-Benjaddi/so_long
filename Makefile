all:
	cd ./mandatory && make

bonus:
	cd ./bonus && make bonus

clean:
	cd ./mandatory && make clean
	cd ./bonus && make clean

fclean: clean
	cd ./mandatory && make fclean
	cd ./bonus && make fclean

re:
	cd mandatory && make re

.PHONY: all bonus clean fclean re
