/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:30:04 by ebenoist          #+#    #+#             */
/*   Updated: 2025/06/27 12:28:41 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static	int	count_ligne(char *file)
{
	int	fd;
	int	count;
	char *line;
	
	fd = open(file, O_RDONLY);
	if(fd < 0)
		return(-1);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return(count);
}

static char **read_file_map(char *file, int fd)
{
	char	**map;
	char	**tmp;
	int		count;
	char	*line;

	count = count_ligne(file);
	line = get_next_line(fd);
	tmp = malloc(sizeof(char *) * (count + 1));
		if(!tmp)
			ft_error_malloc(char **tmp);
	while(line)
	{	
		tmp[i] = line;
		i++;
	}
	tmp[count = NULL]
	return(map);
}

char **read_file(char *file)
{
	int	fd;
	char **map;

	fd = open(file, O_RDONLY);
	if(fd == -1)
		ft_error_file();
	map = read_file_map(fd);
	if(!map)
	{
		write(2, "Error\nReading Failed", 21);
		exit(1);
	}
	close(fd);
	return(map);
}