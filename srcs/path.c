/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:05:13 by ebenoist          #+#    #+#             */
/*   Updated: 2025/07/14 11:58:30 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	**ft_copy_map(char **map)
{
	int		i;
	char	**copy;

	i = 0;
	while (map[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	if (!copy)
		ft_error_malloc(map);
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			free(map);
			ft_error_malloc(copy);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	ft_flood_fill_c(char **copy, int x, int y)
{
	if (x < 0 || y < 0 || !copy[y] || copy[y][x] == '\0')
		return ;
	if (copy[y][x] == '1' || copy[y][x] == 'V' || copy[y][x] == 'M')
		return ;
	copy[y][x] = 'V';
	ft_flood_fill_c(copy, x - 1, y);
	ft_flood_fill_c(copy, x + 1, y);
	ft_flood_fill_c(copy, x, y - 1);
	ft_flood_fill_c(copy, x, y + 1);
}

static void	ft_flood_fill_e(char **copy, int x, int y)
{
	if (x < 0 || y < 0 || !copy[y] || copy[y][x] == '\0')
		return ;
	if (copy[y][x] == '1' || copy[y][x] == 'V' || copy[y][x] == 'M' || copy[y][x] == 'E')
		return ;
	copy[y][x] = 'V';
	ft_flood_fill_e(copy, x - 1, y);
	ft_flood_fill_e(copy, x + 1, y);
	ft_flood_fill_e(copy, x, y - 1);
	ft_flood_fill_e(copy, x, y + 1);
}
static int	ft_check_E_C(char **copy, char c)
{
	int	y;
	int	x;

	y = 0;
	while (copy[y])
	{
		x = 0;
		while (copy[y][x])
		{
			if (copy[y][x] == c)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	ft_path(char **map)
{
	char	**copy;
	int		y;
	int		x;

	copy = ft_copy_map(map);
	y = 0;
	while (copy[y])
	{
		x = 0;
		while (copy[y][x])
		{
			if (copy[y][x] == 'P')
			{
				ft_flood_fill_e(copy, y, x);
				ft_check_E_C(copy, 'E');
				ft_flood_fill_c(copy, y, x);
				ft_check_E_C(copy, 'C');
				break ;
			}
			x++;
		}
		y++;
	}
	x = 1;
	if (!ft_check_E_C(copy))
		x = 0;
	free_map(copy);
	return (x);
}
