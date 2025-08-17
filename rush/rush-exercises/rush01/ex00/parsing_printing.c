/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_printing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-moo <thde-moo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 11:13:02 by thde-moo          #+#    #+#             */
/*   Updated: 2025/08/16 11:41:41 by thde-moo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rush01.h"

int	set_clue(int clues[4][4], int clue_idx, char ch)
{
	if (ch < '1' || ch > '4')
		return (0);
	if (clue_idx < 4)
		clues[0][clue_idx] = ch - '0';
	else if (clue_idx < 8)
		clues[1][clue_idx - 4] = ch - '0';
	else if (clue_idx < 12)
		clues[2][clue_idx - 8] = ch - '0';
	else if (clue_idx < 16)
		clues[3][clue_idx - 12] = ch - '0';
	else
		return (0);
	return (1);
}

int	parse_input(char *input, int clues[4][4])
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (n < 16)
	{
		if (!set_clue(clues, n, input[i]))
			return (0);
		i++;
		n++;
		if (n < 16)
		{
			if (input[i] != ' ')
				return (0);
			i++;
		}
	}
	if (input[i] != '\0')
		return (0);
	return (1);
}

void	print_grid(int grid[4][4])
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			ft_putchar ('0' + grid[row][col]);
			if (col != 3)
				ft_putchar(' ');
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
