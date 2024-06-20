/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:24:26 by acarpent          #+#    #+#             */
/*   Updated: 2024/06/20 15:47:46 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf.h"
# include "libft.h"
# include "../minilibx-linux/mlx.h"

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>

# define WALL_FRAMES 18
# define EXIT_FRAMES 19
# define SPAWN_FRAMES 8
# define PLAYER_FRAMES 6
# define FRAME_DELAY 1000
# define WALL_DELAY 3000
# define EXIT_DELAY 1500
# define SPAWN_DELAY 15000
# define PLAYER_DELAY 1500

enum	e_keys {
	KEY_ESC = 65307,
	KEY_W = 119,
	KEY_UP = 65362,
	KEY_S = 115,
	KEY_DOWN = 65364,
	KEY_A = 97,
	KEY_LEFT = 65361,
	KEY_D = 100,
	KEY_RIGHT = 65363,
};

typedef struct s_anim_wall {
	void	*anim[WALL_FRAMES];
	int		frame;
}	t_anim_wall;

typedef struct s_anim_exit {
	void	*anim[EXIT_FRAMES];
	int		frame;
}	t_anim_exit;

typedef struct s_anim_spawn {
	void	*anim[SPAWN_FRAMES];
	int		frame;
}	t_anim_spawn;

typedef struct s_anim_player {
	void	*anim[PLAYER_FRAMES];
	int		frame;
}	t_anim_player;

typedef struct s_img {
	void	*floor;
	void	*collect;
	void	*enemies;
}	t_img;

typedef struct s_map {
	char			*map;
	char			**split;
	int				fd;
	int				width;
	int				height;
	int				screen_width;
	int				screen_height;
	int				steps;
	int				c;
	int				e;
	int				p;
	int				x;
	int				y;
	void			*mlx;
	void			*win;
	t_img			img;
	t_anim_wall		wall;
	t_anim_spawn	spawn;
	t_anim_exit		exit;
	t_anim_player	player;
}				t_map;

int		ft_checkname(char *str);
char	*get_next_line(int fd);
char	**ft_getmap(t_map *map, char *str);
void	ft_parsemap(t_map *game);
char	*ft_lastline(t_map *game);
void	ft_sizecheck(t_map *game);
void	walls(t_map *game);
void	gamecheck(t_map *game);
void	ft_emptyline(t_map *game);
void	ft_count(t_map *game);
void	ft_floodfill(int x, int y, char **copy, t_map *map);
void	checkfloodfill(t_map *ptr);
char	**ft_mapcopy(char **map, t_map *ptr);
void	exit_handler(t_map *game);
void	ft_gaming(t_map *game);
int		close_game(t_map *game);
void	exit_game(t_map *game, int win);
void	put_img(t_map *game);
void	display_steps(t_map *game);
void	move_up(t_map *game);
void	move_down(t_map *game);
void	move_left(t_map *game);
void	move_right(t_map *game);
int		update_anim(t_map *game);
void	update_player_anim(t_map *game, int fcount);
void	update_spawn_anim(t_map *game, int fcount);
void	update_exit_anim(t_map *game, int fcount);
void	update_wall_anim(t_map *game, int fcount);

#endif