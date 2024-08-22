/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:24:26 by acarpent          #+#    #+#             */
/*   Updated: 2024/08/22 13:22:57 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf.h"
# include "libft.h"
# include "../mlx/mlx.h"

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>

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

typedef struct s_img {
	void	*floor;
	void	*collect;
	void	*enemies;
	void	*exit;
	void	*player;
	void	*wall;
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
}				t_map;

void	ft_checkname(char *str);
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
void	get_image(t_map *game);
void	get_img(t_map *game, char *path, void **ptr);
void	del_img(t_map *game);
void	ft_checkchar(t_map *game);
int		ft_envcheck(char **env);

#endif