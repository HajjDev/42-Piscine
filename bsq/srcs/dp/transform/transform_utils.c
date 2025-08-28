/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:26:09 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/27 16:26:10 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_size(char **map, int *col, int *row)
{
	(*row) = 0;
	if (!map || !map[0])
	{
		(*col) = 0;
		return ;
	}
	(*col) = ft_strlen(map[0]);
	while (map[*row])
	{
		(*row)++;
	}
}

int	*ft_add(char *line, int size, char sep)
{
	int	*array_line;
	int	i;

	i = 0;
	array_line = (int *)malloc(sizeof(int) * (size + 1));
	if (!array_line)
		return (NULL);
	while (i < size)
	{
		if (line[i] == sep)
			array_line[i] = 0;
		else
			array_line[i] = 1;
		i++;
	}
	array_line[i] = -1;
	return (array_line);
}

void	ft_free_all(int **array, int i)
{
	int	j;

	j = i;
	while (j >= 0)
	{
		free(array[j]);
		j--;
	}
	free(array);
}
