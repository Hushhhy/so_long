/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:19:29 by acarpent          #+#    #+#             */
/*   Updated: 2024/05/31 14:23:55 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    ft_sizecheck(char **map);
char	*ft_lastline(char **map);

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