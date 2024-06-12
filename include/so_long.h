/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:24:26 by acarpent          #+#    #+#             */
/*   Updated: 2024/06/12 14:22:27 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf.h"
# include "libft.h"

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>

typedef struct s_map {
	char	*map;
	char	**split;
	int		fd;
	int		width;
	int		height;
	int		C;
	int		E;
	int		P;
	int		x;
	int		y;
}				t_map;

int		ft_checkname(char *str);
char	*get_next_line(int fd);
char	**ft_getmap(t_map *map, char *str);
void	ft_parsemap(char **map, t_map *game);
char	*ft_lastline(char **map, t_map *game);
void	ft_sizecheck(char **map);
void	walls(char **map, char *first, char *last);
void	gamecheck(char **map, t_map *game);
void	ft_emptyline(char *map);
void	ft_count(t_map *game, char **map);
void	ft_floodfill(int x, int y, char **copy);
void	checkfloodfill(t_map *ptr);
char	**ft_mapcopy(char **map, t_map *ptr);

#endif