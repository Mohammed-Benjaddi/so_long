/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:11:38 by mben-jad          #+#    #+#             */
/*   Updated: 2024/06/02 19:54:14 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
	int			x;
	int			y;
	bool		up;
	bool		down;
	bool		left;
	bool		right;
}				t_player;

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
	char		direction;
	int			count_moves;
}				t_vars;

char			**ft_split(char const *s, char c);
char			*ft_strjoin(char **s1, char const *s2);
char			*ft_strdup(const char *s1);
int				ft_strlcpy(char *dst, const char *src, int dstsize);
int				ft_strlen(const char *s);
char			*ft_substr(char const *s, unsigned int start, int len);
int				ft_strcmp(char *s1, char *s2);
char			*ft_itoa(int n);
void			ft_putstr_fd(char *str, int fd);
char			*get_next_line(int fd);
int				ft_strchr_gnl(char *s, char c);
void			ft_strlcat_gnl(char *dst, char *src);
void			ft_strlcpy_gnl(char *dst, char *src);
void			error(char *msg, t_vars *vars);
void			put_textures_on_map(t_vars *vars, char **map);
void			check_walls(t_vars *vars, char **map);
char			**get_map(char *file_name, t_vars *vars);
void			check_filename(int size, char *filename);
void			coins_init(t_vars *vars, t_coins *coins, char **map);
void			ft_put_asset(void *param, char *path, int x, int y);
void			move_up(t_vars *vars, int x, int y);
void			move_down(t_vars *vars, int x, int y);
void			move_right(t_vars *vars, int x, int y);
void			move_left(t_vars *vars, int x, int y);
void			flood_fill(t_vars *vars, int x, int y, char **map_copy);
mlx_image_t		*get_png(char *path, t_vars *vars);
void			get_player_position(t_player *player, char **map);
void			ft_player_hook(mlx_key_data_t keydata, void *param);
void			set_moves(t_vars *vars);
void			ft_free(char **arg);
void			change_direction(t_vars *vars, char flag);
void			set_direction(t_vars *vars, char flag);
void			is_map_valid(t_vars *vars);
int				is_empty_line(char *line);
void			check_player_exit(t_vars *vars, char **map, char flag);
void			check_coins(t_vars *vars, char **map, char flag);
void			check_textures(void);

#endif
