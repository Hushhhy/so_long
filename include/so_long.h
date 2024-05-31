/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:24:26 by acarpent          #+#    #+#             */
/*   Updated: 2024/05/31 14:22:17 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf.h"
# include "libft.h"

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>

typedef struct t_map {
	char	**map;
	int		C;
	int		E;
	int		P;
}				s_map;

void    ft_checkname(char *str);
char	*get_next_line(int fd);
char	*ft_getmap(char *str);
void	ft_parsemap(char **map);
char	*ft_lastline(char **map);
void    ft_sizecheck(char **map);

#endif