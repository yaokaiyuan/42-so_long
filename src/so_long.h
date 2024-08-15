/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <paradari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:54:55 by paradari          #+#    #+#             */
/*   Updated: 2024/07/28 13:45:01 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <X11/X.h>
# include <stdio.h>

# define IMG_SIZE 64
# define TILE "asset/tile.xpm"
# define WALL "asset/wall.xpm"
# define COLLECT "asset/item.xpm"
# define P1 "asset/player_stage1.xpm"
# define P2 "asset/player_stage2.xpm"
# define P3 "asset/player_stage3.xpm"
# define P4 "asset/player_stage4.xpm"
# define EXIT_L "asset/door_stage1.xpm"
# define EXIT_U "asset/door_stage2.xpm"

# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363
# define ESC 65307

typedef struct s_data
{
	void	*mlx;
	void	*window;
	int		width;
	int		height;

	char	**map;
	char	**tmp;
	int		line;
	int		column;

	int		pos_x;
	int		pos_y;
	int		exit_x;
	int		exit_y;
	int		move_counter;
	int		collect_counter;

	int		p_status;
	int		c_status;
	int		e_status;

	int		isize;
	void	*tile;
	void	*wall;
	void	*collect;
	void	*player;
	void	*player_1;
	void	*player_2;
	void	*player_3;
	void	*player_4;
	void	*exit;
	void	*exit_locked;
	void	*exit_unlocked;
}	t_data;

void	ft_check_input(char *av, int ac);
int		file_check(char *extension);

t_data	*ft_set_data(char *av, t_data *data);
void	ft_init_data(t_data *data);
void	ft_set_map(char *file, char **map, int *column);
char	**ft_get_map(int fd, int row, int *column, char **map);
int		ft_count_line(char *file);
void	ft_loop(t_data *data);

void	ft_init_game(t_data *data);
void	ft_set_status(char c, t_data *data, int i, int j);
void	ft_init_image(t_data *data);
void	ft_init_mlx(t_data *data);
void	ft_init_player(t_data *data);

int		ft_put_graphic(t_data *data);
void	ft_fill(t_data *data, int i, int j);

int		ft_check_map(t_data *data);
int		check_wall(t_data *data);
int		check_rect(t_data *data);
int		check_missing(t_data *data);
int		check_valid(t_data *data);
void	ft_free_map(char **map);
void	ft_full_fill(t_data *data);
void	fill_horizon(t_data *data, int x, int y);
void	fill_vertical(t_data *data, int x, int y);
int		ft_check_left(t_data *data);
int		ft_is_left(t_data *data);
int		check_x(t_data *data, int y, int x);

int		ft_keybinds(int key, t_data *data);
void	ft_move(t_data *data, int new_x, int new_y);
void	ft_check_collect(t_data *data);
void	ft_suit_up(t_data *data);

int		ft_destroy(t_data *data);
int		ft_destroy_2(t_data *data);
void	ft_clear_mlx(t_data *data);
void	ft_clear_img(t_data *data);

#endif
