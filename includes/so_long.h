/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 09:58:44 by ebenoist          #+#    #+#             */
/*   Updated: 2025/07/03 12:06:52 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>

typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
	int		p;
	int collect; // collectibles restants
	int		moves;
	void	*mlx;
	void	*win;
	void *img[5]; // sol, mur, joueur, C, E
}			t_game;

void		ft_arg_error(int ac, char *file);
void		ft_error_file(void);
char		**read_file(char *file);
void		ft_error_malloc(char **tab);
void		free_map(char **map);
void		ft_invalid_map(char **map);
void		ft_check_norm(char **game);
void		parse_map_char(char **game);
int			ft_path(map);

# define TILE_SIZE 64

#endif