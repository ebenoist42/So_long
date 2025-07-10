/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 09:58:44 by ebenoist          #+#    #+#             */
/*   Updated: 2025/07/10 13:18:05 by ebenoist         ###   ########.fr       */
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
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_enemy;
	void	*img_collect;
}			t_game;

void		ft_arg_error(int ac, char *file);
void		ft_error_file(void);
char		**read_file(char *file);
void		ft_error_malloc(char **tab);
void		ft_error_malloc_2(t_game *game);
void		free_map(char **map);
void		ft_invalid_map(char **map);
void		ft_check_norm(char **game);
void		parse_map_char(char **game);
int			ft_path(char **map);
void		error_mlx(t_game *game);
void	load_image(t_game *game);
void	error_load(t_game *game);
void	destroy_error(t_game *game);
void	render_map(t_game *game);

# define TILE_SIZE 64

#endif