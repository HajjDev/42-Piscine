/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:29:16 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/27 21:23:05 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static void	process_map(char **map, char *legend)
{
	int				**array;
	t_max_square	*max_element;
	int				row;
	int				col;

	array = transform(map, legend[1]);
	ft_size(map, &col, &row);
	if (array && init_max(&max_element))
	{
		ft_solve(array, max_element, row, col);
		ft_modify(map, max_element, legend[2]);
		ft_print(map);
		ft_free_array(array);
		free_max_element(&max_element);
	}
	else
	{
		if (array)
			ft_free_array(array);
		free(map);
	}
}

void	find_largest_cube(char *file_name)
{
	char	**lines;
	char	*file_content;
	char	**map;
	char	legend[4];

	lines = parse_file(file_name, &file_content);
	if (lines)
	{
		map = init_map(lines, legend);
		if (map)
		{
			process_map(map, legend);
		}
		free(file_content);
	}
}

int	main(int argc, char **argv)
{
	int				i;

	if (argc == 1)
	{
		find_largest_cube(NULL);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		find_largest_cube(argv[i]);
		if (i < argc - 1)
			write(1, "\n", 1);
		i++;
	}
	return (0);
}
