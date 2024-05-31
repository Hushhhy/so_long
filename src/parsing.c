/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:26:46 by acarpent          #+#    #+#             */
/*   Updated: 2024/05/31 14:43:21 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

char	*ft_getmap(char *str);
void	ft_checkname(char *str);
void	ft_parsemap(char **map);

char	*ft_getmap(char *str)
{
	char	*map;
	int		fd;
	char	*line;
	char	*tmp;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = ft_strdup("");
	if (!map)
		return (NULL);
	while ((line = get_next_line(fd)) != NULL)
	{
		tmp = map;
		map = ft_strjoin(map, line);
		free(tmp);
		if (!map)
		{
			close(fd);
			return (NULL);
		}
	}
	close(fd);
	return (map);
}

void	ft_checkname(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i + 1] == '\0')
		{
			i -= 3;
			if (str[i] == '.' && str[i + 1] == 'b' && str[i + 2] == 'e'
				&& str[i + 3] == 'r')
				return ;
			else
			{
				ft_printf("Wrong map name !");
				exit(0);
			}
		}
		i++;
	}
}

void	ft_parsemap(char **map)
{
	char	*first;
	char	*last;
	int		i;
	int		j;
	
	first = map[0];
	last = ft_lastline(map);
	ft_sizecheck(map);
	i = 0;
	while (first[i] && last[i])
	{
		if (first[i] != '1' || last[i] != '1')
		{
			ft_printf("Error! Wrong map format!");
			exit(1);
		}
		i++;
	}
	i = 0;
	j = ft_strlen(map[i]) - 1;
	while (map[i])
	{
		if (map[i] == first || map[i] == last)
			i++;
		if (map[i][0] == '1' && map[i][j] == '1')
			i++;
		else
		{
			ft_printf("Error! Wrong map format!");
			exit(1);
		}
		i++;
	}
}
