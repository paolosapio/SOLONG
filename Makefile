gcc:
	gcc *.c MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm libft/libft.a
#-O3 este flag puede dar prooblemas pero optimiza el codigo en teoria

exec: gcc
	./a.out
