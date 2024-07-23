/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:19:29 by acarpent          #+#    #+#             */
/*   Updated: 2024/07/10 14:10:43 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_sizecheck(t_map *game);
char	*ft_lastline(t_map *game);
void	walls(t_map *game);

char	*ft_lastline(t_map *game)
{
	char	*last;
	int		i;

	i = 0;
	game->width = ft_strlen(game->split[0]);
	while (game->split[i + 1])
		i++;
	last = game->split[i];
	game->height = i + 1;
	return (last);
}

void	ft_sizecheck(t_map *game)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = game->split[0];
	while (game->split[++i])
	{
		if (ft_strlen(tmp) != ft_strlen(game->split[i]))
		{
			ft_printf("Error!\nWrong map format!\n");
			exit_handler(game);
		}
	}
}

void	walls(t_map *game)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(game->split[i]) - 1;
	while (game->split[i])
	{
		if (game->split[i][0] == '1' && game->split[i][j] == '1')
			i++;
		else
		{
			ft_printf("Error!\nWrong map format!\n");
			exit_handler(game);
		}
	}
}

void	ft_emptyline(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(game->map) - 1;
	while (game->map[i] != '1')
		i++;
	while (game->map[j] != '1')
		j--;
	while (i != j)
	{
		if (game->map[i] == '\n' && game->map[i + 1] == '\n')
		{
			ft_printf("Error!\nWrong map format!\n");
			free(game->map);
			exit(1);
		}
		i++;
	}
}
