/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:24:26 by acarpent          #+#    #+#             */
/*   Updated: 2024/06/13 16:32:32 by acarpent         ###   ########.fr       */
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

typedef struct s_img {
	void	*floor;
	void	*collect;
	void	*enemies;
}	t_img;

typedef struct s_map {
	char	*map;
	char	**split;
	int		fd;
	int		width;
	int		height;
	int		screen_width;
	int		screen_height;
	int		c;
	int		e;
	int		p;
	int		x;
	int		y;
	int		steps;
	void	*mlx;
	void	*win;
	t_img	img;
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

#endif