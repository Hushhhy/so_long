/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:26:46 by acarpent          #+#    #+#             */
/*   Updated: 2024/05/29 16:08:28 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

char    *ft_getmap(char *str)
{
    char    *map;
    int     fd;
    char    *line;
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
        map = ft_strjoin(line, map);
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
