/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:40:45 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/27 16:40:49 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static void	fill_array(int **array, char **map, int row_col[2], char sep)
{
	t_coords	c;

	c.y = 0;
	while (c.y < row_col[0])
	{
		c.x = 0;
		while (c.x < row_col[1])
		{
			if (map[c.y][c.x] == sep)
				array[c.y][c.x] = 0;
			else
				array[c.y][c.x] = 1;
			c.x++;
		}
		c.y++;
	}
}

int	**transform(char **map, char sep)
{
	int	**array;
	int	*data_block;
	int	row_col[2];
	int	i;

	ft_size(map, &row_col[1], &row_col[0]);
	if (row_col[0] == 0 || row_col[1] == 0)
		return (NULL);
	array = malloc(sizeof(int *) * row_col[0]);
	data_block = malloc(sizeof(int) * row_col[0] * row_col[1]);
	if (!array || !data_block)
	{
		free(array);
		free(data_block);
		return (NULL);
	}
	i = 0;
	while (i < row_col[0])
	{
		array[i] = data_block + (i * row_col[1]);
		i++;
	}
	fill_array(array, map, row_col, sep);
	return (array);
}
