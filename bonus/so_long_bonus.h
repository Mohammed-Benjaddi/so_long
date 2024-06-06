/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:11:38 by mben-jad          #+#    #+#             */
/*   Updated: 2024/05/19 17:43:44 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# include <MLX42/MLX42.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct window_s
{
	int			w;
	int			h;
}				t_window;

typedef struct coins_s
{
	int			total;
	int			rest;
	int			eaten;
}				t_coins;

typedef struct s_player
{
	mlx_image_t	*p;
	int			idle_count;
	int			current_player_png;
	int			x;
	int			y;
	bool		up;
	bool		down;
	bool		left;
	bool		right;
}				t_player;

typedef struct s_enemy
{
	mlx_image_t	*e;
	int			x;
	int			y;
	int			fly_count;
}				t_enemy;

typedef struct map_s
{
	char		**map;
	int			x_len;
	int			y_len;
	int			valid_coins;
	int			valid_exit;
}				t_map;

typedef struct s_vars
{
	void		*mlx;
	t_window	window;
	t_player	player;
	t_coins		coins;
	mlx_image_t	*exit;
	t_map		*map_info;
	t_enemy		*enemies;
	int			enemies_count;
	int			enemy_fly;
	char		direction;
	int			count_moves;
	void		**enemy_moves;
	void		**player_moves;
	int			fly_count;
	int			current_enemy_png;
}				t_vars;

char			**ft_split(char const *s, char c);
char			*ft_strjoin(char **s1, char const *s2);
char			*ft_strdup(const char *s1);
int				ft_strlcpy(char *dst, const char *src, int dstsize);
int				ft_strlen(const char *s);
char			*ft_substr(char const *s, unsigned int start, int len);
int				ft_strcmp(char *s1, char *s2);
char			*ft_itoa(int n);
char			*get_next_line(int fd);
int				ft_strchr_gnl(char *s, char c);
void			ft_strlcat_gnl(char *dst, char *src);
void			ft_strlcpy_gnl(char *dst, char *src);
void			error(char *msg, t_vars *vars);
void			put_textures_on_map(t_vars *vars, char **map);
void			check_walls(char **map, t_vars *vars);
void			is_map_valid(t_vars *vars);
char			**get_map(char *file_name, t_vars *vars);
void			check_filename(int size, char *filename);
void			coins_init(t_coins *coins, char **map);
void			ft_put_asset(void *param, char *path, int x, int y);
void			move_up(t_vars *vars, int x, int y);
void			move_down(t_vars *vars, int x, int y);
void			move_right(t_vars *vars, int x, int y);
void			move_left(t_vars *vars, int x, int y);
void			flood_fill(t_vars *vars, int x, int y, char **map_copy);
void			set_background(t_vars *vars, int y, int x);
void			set_moves(t_vars *vars);
int				count_enemies(t_vars *vars);
mlx_image_t		*get_png(char *path, t_vars *vars);
void			get_player_position(t_player *player, char **map);
void			ft_player_hook(mlx_key_data_t keydata, void *param);
void			update_player_position(t_player *player, char **map);
void			ft_free(char **arg);
void			animations(void *param);
void			get_all_enemies_positions(t_vars *vars);
void			change_direction(t_vars *vars, char flag);
void			set_direction(t_vars *vars, char flag);
void			make_game_ready(t_vars *vars, char *arg);
void			check_player_exit(char **map, char flag, t_vars *vars);
int				is_empty_line(char *line);
mlx_image_t		*make_player_breath(t_vars *vars, int nbr);
void			delete_player_textures(t_vars *vars);
void			**get_player_textures(char direction, t_vars *vars);
void			get_right_direction(void **textures, bool at_exit);
void			get_left_direction(void **textures, bool at_exit);
void			player_animation(t_vars *vars);
void			*load_the_png(char *path);
void			draw_map(t_vars *vars, char c, int x, int y);
void			put_textures_on_map(t_vars *vars, char **map);
void			ft_put_asset(void *param, char *path, int x, int y);
int				is_key_up(mlx_key_data_t keydata, bool up);
int				is_key_down(mlx_key_data_t keydata, bool down);
int				is_key_left(mlx_key_data_t keydata, bool left);
int				is_key_right(mlx_key_data_t keydata, bool right);
void			ft_putstr_fd(char *str, int fd);
void			check_coins_enemy(char **map, char flag, t_vars *vars);
void			**get_player_exit_textures(char direction, t_vars *vars);
void			check_textures(void);
void			check_other_txt(void);
void			check_enemy_txt(void);
void			check_if_loaded(void **textures, int size);

#endif