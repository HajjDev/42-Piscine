/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:41:39 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/27 22:27:28 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	**map_error(void)
{
	write(2, "map error\n", 10);
	return (NULL);
}

int	is_in(char c, char *str)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	correct_chars(char *str, char **lines)
{
	int	i;
	int	j;

	i = 1;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			if (!is_in(lines[i][j], str))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	assign_legend(char *line_0, char *legend)
{
	int	i;

	while (*line_0 >= '0' && *line_0 <= '9')
		line_0++;
	i = 0;
	while (*line_0 && i < 3)
	{
		legend[i] = *line_0;
		i++;
		line_0++;
	}
	legend[i] = '\0';
}

char	**init_map(char **lines, char *legend)
{
	int		i;
	char	**map;

	i = 1;
	while (lines[i])
		i++;
	map = (char **)malloc(sizeof(char *) * (i + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (lines[i + 1])
	{
		map[i] = lines[i + 1];
		i++;
	}
	map[i] = NULL;
	assign_legend(lines[0], legend);
	free(lines);
	return (map);
}
