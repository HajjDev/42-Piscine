/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 11:12:00 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/16 13:27:33 by thde-moo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	main(int argc, char **argv)
{
	int	grid[4][4];
	int	clues[4][4];
	int	row;
	int	col;

	if (argc != 2 || !parse_input(argv[1], clues))
		return (error());
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
			grid[row][col++] = 0;
		row++;
	}
	if (try_place(grid, clues, 0))
		print_grid(grid);
	else
		return (error());
	return (0);
}
