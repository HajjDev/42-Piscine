/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:25:18 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/08 09:21:23 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(char c)
{
	write(1, &c, 1);
}

void	ft_display_comb(char i, char j)
{
	ft_print(i / 10 + '0');
	ft_print(i % 10 + '0');
	ft_print(' ');
	ft_print(j / 10 + '0');
	ft_print(j % 10 + '0');
	if (!(i == 98 && j == 99))
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 99)
	{
		j = i + 1;
		while (j <= 99)
		{
			ft_display_comb(i, j);
			j++;
		}
		i++;
	}
}
