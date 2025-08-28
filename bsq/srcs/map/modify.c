/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:25:15 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/27 16:29:35 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_modify(char **map, t_max_square *max_element, char fill)
{
	int	start_row;
	int	start_col;
	int	end_row;
	int	end_col;

	end_row = max_element->i;
	end_col = max_element->j;
	start_row = end_row - max_element->size + 1;
	while (start_row <= end_row)
	{
		start_col = end_col - max_element->size + 1;
		while (start_col <= end_col)
		{
			map[start_row][start_col] = fill;
			start_col++;
		}
		start_row++;
	}
}
