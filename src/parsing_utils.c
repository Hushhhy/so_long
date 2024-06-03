/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:19:29 by acarpent          #+#    #+#             */
/*   Updated: 2024/06/03 15:29:32 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    ft_sizecheck(char **map);
char	*ft_lastline(char **map);
void	walls(char **map, char *first, char *last);

char	*ft_lastline(char **map)
{
	char	*last;
	int		i;

	i = 0;
	while (map[i + 1])
		i++;
	last = map[i];
	return (last);
}

void    ft_sizecheck(char **map)
{
    char    *tmp;
    int     i;

    i = 0;
	tmp = map[0];
	while (map[++i])
	{
		if (ft_strlen(tmp) != ft_strlen(map[i]))
		{
			ft_printf("Error! Wrong map format!");
			exit(1);
		}
	}
}

void	walls(char **map, char *first, char *last)
{
	int		i;
	int		j;

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

void	ft_emptyline(char *map)
{
	int	i;
	int	j;
	
	i = 0;
	j = ft_strlen(map) - 1;
	while (map[i] != '1')
		i++;
	while (map[j] != '1')
		j--;
	while (i != j)
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			ft_printf("Error! Wrong map format!");
			exit(1);
		}
		i++;
	}
}
