/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:51:51 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/27 16:25:54 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_solve(int **m, t_max_square *max_element, int row, int col)
{
	int	i;
	int	j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if (i > 0 && j > 0 && m[i][j] == 1)
			{
				m[i][j] = n(m[i - 1][j], m[i][j - 1], m[i - 1][j - 1]) + 1;
			}
			if (m[i][j] > max_element->size)
				ft_assign(m, i, j, max_element);
			j++;
		}
		i++;
	}
}
