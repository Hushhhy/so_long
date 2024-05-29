/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:34:09 by acarpent          #+#    #+#             */
/*   Updated: 2024/05/29 16:09:41 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

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

int	main(int ac, char **av)
{
	char	*map;
	char	**split;
	
	if (ac == 2)
	{
		ft_checkname(av[1]);
		map = ft_getmap(av[1]);
		split = ft_split(map, '\n');
		ft_printf("%s\n", map);
	}
	else
	{
		ft_printf("Error\nArgument number must be 1 !");
		return (0);
	}
	free(map);
	return (0);
}
