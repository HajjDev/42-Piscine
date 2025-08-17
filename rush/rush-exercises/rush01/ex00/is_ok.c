/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ok.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-moo <thde-moo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 12:19:40 by thde-moo          #+#    #+#             */
/*   Updated: 2025/08/16 13:05:51 by thde-moo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	row_unique_ok(int grid[4][4], int row)
{
	int	seen[5];
	int	col;
	int	val;

	col = 0;
	while (col < 5)
		seen[col++] = 0;
	col = 0;
	while (col < 4)
	{
		val = grid[row][col];
		if (val && seen[val])
			return (0);
		if (val)
			seen[val] = 1;
		col++;
	}
	return (1);
}

int	col_unique_ok(int grid[4][4], int col)
{
	int	seen[5];
	int	row;
	int	val;

	row = 0;
	while (row < 5)
		seen[row++] = 0;
	row = 0;
	while (row < 4)
	{
		val = grid[row][col];
		if (val && seen[val])
			return (0);
		if (val)
			seen[val] = 1;
		row++;
	}
	return (1);
}

int	row_vis_ok(int grid[4][4], int row, int left, int right)
{
	if (vis_row_left(grid, row) != left)
		return (0);
	if (vis_row_right(grid, row) != right)
		return (0);
	return (1);
}

int	col_vis_ok(int grid[4][4], int col, int top, int bot)
{
	if (vis_col_top(grid, col) != top)
		return (0);
	if (vis_col_bottom(grid, col) != bot)
		return (0);
	return (1);
}
