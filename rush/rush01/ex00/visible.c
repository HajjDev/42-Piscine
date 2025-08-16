/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visible.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 11:32:38 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/16 13:08:05 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

/*
These function will check how many buildings are 
visible from each direction 
*/
/* This will make sure we respect every constraint given  */

/* From the top and the bottom of the columns */
int	vis_col_top(int grid[4][4], int col)
{
	int	row;
	int	max_value;
	int	visible;

	row = 0;
	visible = 0;
	max_value = 0;
	while (row < 4)
	{
		if (grid[row][col] > max_value)
		{
			max_value = grid[row][col];
			visible++;
		}
		row++;
	}
	return (visible);
}

int	vis_col_bottom(int grid[4][4], int col)
{
	int	row;
	int	max_value;
	int	visible;

	row = 3;
	max_value = 0;
	visible = 0;
	while (row >= 0)
	{
		if (grid[row][col] > max_value)
		{
			max_value = grid[row][col];
			visible++;
		}
		row--;
	}
	return (visible);
}

/* From the left and the right of the rows */
int	vis_row_left(int grid[4][4], int row)
{
	int	col;
	int	max_value;
	int	visible;

	col = 0;
	max_value = 0;
	visible = 0;
	while (col < 4)
	{
		if (grid[row][col] > max_value)
		{
			max_value = grid[row][col];
			visible++;
		}
		col++;
	}
	return (visible);
}

int	vis_row_right(int grid[4][4], int row)
{
	int	col;
	int	max_value;
	int	visible;

	col = 3;
	max_value = 0;
	visible = 0;
	while (col >= 0)
	{
		if (grid[row][col] > max_value)
		{
			max_value = grid[row][col];
			visible++;
		}
		col--;
	}
	return (visible);
}
