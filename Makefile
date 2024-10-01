gcc:
	gcc *.c GNL/*.c MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm libft/libft.a -g
#-O3 este flag puede dar prooblemas pero optimiza el codigo en teoria

exec: gcc
	./a.out
