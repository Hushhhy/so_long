/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:56:30 by acarpent          #+#    #+#             */
/*   Updated: 2024/05/28 12:58:10 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

void	ft_initmap(char *map)
{
	char	*line;
	int		fd;

	fd = open("map1.ber", O_WRONLY);
	line = get_next_line(fd);
	printf("%s\n", line);
}
