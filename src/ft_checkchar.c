/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:29:51 by acarpent          #+#    #+#             */
/*   Updated: 2024/08/23 11:08:57 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_checkchar(t_map *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (!ft_strchr("01PNEC\n", game->map[i]))
		{
			ft_printf("Error !\nCharacter invalid in map !\n");
			free(game->map);
			exit(0);
		}
		i++;
	}
}
void	ft_doublen(t_map *game, int i)
{
	if (game->map[i] == '\n' && game->map[i])
	{
		if (game->map[i + 1] == '\n')
		{
			ft_printf("Error!\nWrong map format!4\n");
			free(game->map);
			exit(1);
		}
	}
}
