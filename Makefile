NAME = so_long
SRC = src/main.c\
		src/check_map.c\
		src/destroy.c\
		src/for_free.c\
		src/ft_keybinds.c\
		src/graphic.c\
		src/init_game.c\
		src/loop.c\
		src/setup_data.c\
		src/check_map_utils.c\
		src/check_map_utils2.c\

HEADER = src/so_long.h
LIBFT_PATH = libft/

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I $(HEADER) -O0
MLXFLAGS = -L ./minilibx-linux/ -lmlx -Ilmlx -lXext -lX11

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_PATH)/libft.h $(HEADER)
	make -C $(LIBFT_PATH)
	make -C minilibx-linux/
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_PATH)/libft.a minilibx-linux/libmlx.a -Lmlx_linux -lmlx_Linux -Lminilibx-linux/ -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o:%.c $(HEADER) $(LIBFT_PATH)/libft.h
	$(CC) $(CFLAGS) -Imlx_linux -c $< -o $@

clean:
	rm -rf $(OBJ)
	make clean -C $(LIBFT_PATH)
	rm -rf minilibx/obj/*.o

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_PATH)
	make clean -C minilibx-linux/

re: fclean all

.PHONY: all clean fclean re 

MAP_PTH		=	map/
INV_MAP_PTH	=	$(MAP_PTH)invalid/
VLD_MAP_PTH	=	$(MAP_PTH)valid/

v	= 1

define	test_ber
	@echo "$(D_GREEN)Map: $(addprefix $1, $2)$(NC)"
	cat $(addprefix $1, $2) -e
	@-echo ""
	@-valgrind --log-file="valgrind.out" ./$(NAME) $(addprefix $1, $2)
	@-grep --color=auto -E "no leaks" valgrind.out || @-grep echo "leaks found"
	@-grep --color=auto -E "definitely lost:|indirectly lost:|possibly lost:|still reachable:| suppressed:" valgrind.out || true
	@-grep --color=auto "ERROR SUMMARY" valgrind.out || true
	@-echo ""
endef

# invalid map test

BER	=	.ber

$(BER):
	cp $(INV_MAP_PTH)file/.ber .ber

inv_file: all | $(BER)
	@echo "$(D_BLUE)### run test cases: invalid file$(NC)"
	-$(call test_ber, "", .ber)
	-$(call test_ber, $(INV_MAP_PTH)file/, .ber)
	-$(call test_ber, $(INV_MAP_PTH)file/, invalid_filepath.ber)
	-$(call test_ber, $(INV_MAP_PTH)file/, not_a_ber_file.sus)
	@echo "$(D_BLUE)# End of test cases ----- -------  ---- --- \n$(NC)"

inv_size: all
	@echo "$(D_BLUE)### run test cases: invalid size$(NC)"
	-$(call test_ber, $(INV_MAP_PTH)size/, empty.ber)
	-$(call test_ber, $(INV_MAP_PTH)size/, not_rectangle.ber)
	-$(call test_ber, $(INV_MAP_PTH)size/, 1_col.ber)
	-$(call test_ber, $(INV_MAP_PTH)size/, 2_cols.ber)
	-$(call test_ber, $(INV_MAP_PTH)size/, 1_line.ber)
	-$(call test_ber, $(INV_MAP_PTH)size/, 2_lines.ber)
	-$(call test_ber, $(INV_MAP_PTH)size/, uneven_lines.ber)
	-$(call test_ber, $(INV_MAP_PTH)size/, uneven_line_at_first.ber)
	-$(call test_ber, $(INV_MAP_PTH)size/, uneven_line_at_last.ber)
	-$(call test_ber, $(INV_MAP_PTH)size/, uneven_line_at_middle.ber)
	@echo "$(D_BLUE)# End of test cases ----- -------  ---- --- \n$(NC)"

inv_line: all
	@echo "$(D_BLUE)### run test cases: invalid layout of lines$(NC)"
	-$(call test_ber, $(INV_MAP_PTH)line/, empty_line.ber)
	-$(call test_ber, $(INV_MAP_PTH)line/, initial_empty_lines.ber)
	-$(call test_ber, $(INV_MAP_PTH)line/, following_empty_lines.ber)
	-$(call test_ber, $(INV_MAP_PTH)line/, first_empty_line.ber)
	-$(call test_ber, $(INV_MAP_PTH)line/, last_empty_line.ber)
	@echo "$(D_BLUE)# End of test cases ----- -------  ---- --- \n$(NC)"

inv_layout: all
	@echo "$(D_BLUE)### run test cases: invalid layout$(NC)"
	-$(call test_ber, $(INV_MAP_PTH)layout/, no_walls.ber)
	-$(call test_ber, $(INV_MAP_PTH)layout/, no_top_walls.ber)
	-$(call test_ber, $(INV_MAP_PTH)layout/, no_bottom_walls.ber)
	-$(call test_ber, $(INV_MAP_PTH)layout/, no_left_walls.ber)
	-$(call test_ber, $(INV_MAP_PTH)layout/, no_right_walls.ber)
	-$(call test_ber, $(INV_MAP_PTH)layout/, no_corner_walls.ber)
	-$(call test_ber, $(INV_MAP_PTH)layout/, only_corners.ber)
	-$(call test_ber, $(INV_MAP_PTH)layout/, no_top_walls_but_corners.ber)
	-$(call test_ber, $(INV_MAP_PTH)layout/, no_bottom_walls_but_corners.ber)
	-$(call test_ber, $(INV_MAP_PTH)layout/, no_left_walls_but_corners.ber)
	-$(call test_ber, $(INV_MAP_PTH)layout/, no_right_walls_but_corners.ber)
	-$(call test_ber, $(INV_MAP_PTH)layout/, so_much_gaps.ber)
	@echo "$(D_BLUE)# End of test cases ----- -------  ---- --- \n$(NC)"

inv_char: all
	@echo "$(D_BLUE)### run test cases: invalid character$(NC)"
	-$(call test_ber, $(INV_MAP_PTH)char/, invalid_character.ber)
	-$(call test_ber, $(INV_MAP_PTH)char/, multiple_E.ber)
	-$(call test_ber, $(INV_MAP_PTH)char/, multiple_P.ber)
	-$(call test_ber, $(INV_MAP_PTH)char/, no_C.ber)
	-$(call test_ber, $(INV_MAP_PTH)char/, no_E.ber)
	-$(call test_ber, $(INV_MAP_PTH)char/, no_P.ber)
#	-$(call test_ber, $(INV_MAP_PTH)char/, not_even_a_map.ber)
	@echo "$(D_BLUE)# End of test cases ----- -------  ---- --- \n$(NC)"

inv_path: all
	@echo "$(D_BLUE)### run test cases: invalid path$(NC)"
	-$(call test_ber, $(INV_MAP_PTH)path/, unreachable_C.ber)
	-$(call test_ber, $(INV_MAP_PTH)path/, unreachable_E.ber)
	-$(call test_ber, $(INV_MAP_PTH)path/, blocked_by_E.ber)
	-$(call test_ber, $(INV_MAP_PTH)path/, blocked_by_Walls.ber)
	@echo "$(D_BLUE)# End of test cases ----- -------  ---- --- \n$(NC)"

i: inv

inv: all
	@-make --no-print-directory inv_file	
	@-make --no-print-directory inv_size
	@-make --no-print-directory inv_line
	@-make --no-print-directory inv_layout
	@-make --no-print-directory inv_char
	@-make --no-print-directory inv_path