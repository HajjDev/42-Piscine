/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_place.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 12:08:15 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/16 13:34:29 by thde-moo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

/* This is the main algorithm that is going to solve the problem. */
/* We use backtracking to try every possible combination. */
/* The function will start placing numbers, if something goes wrong */
/* it removes the last number it placed and tries to place another number */
/* while following all the rules, once it finds 1 solution, it stops. */

int	line_col_check(int grid[4][4], int clues[4][4], int row, int col)
{
	if ((col == 3
			&& !row_vis_ok(grid, row, clues[2][row], clues[3][row])) == 0
			&& (row == 3
			&& !col_vis_ok(grid, col, clues[0][col], clues[1][col])) == 0)
		return (1);
	return (0);
}

int	try_place(int grid[4][4], int clues[4][4], int pos)
{
	int	row;
	int	col;
	int	val;

	if (pos == 16)
		return (1);
	row = pos / 4;
	col = pos % 4;
	val = 1;
	while (val <= 4)
	{
		grid[row][col] = val;
		if (row_unique_ok(grid, row) && col_unique_ok(grid, col))
		{
			if (line_col_check(grid, clues, row, col))
			{
				if (try_place(grid, clues, pos + 1))
					return (1);
			}
		}
		grid[row][col] = 0;
		val++;
	}
	return (0);
}
