/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 21:32:15 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/26 22:06:16 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "options.h"
#include <stdio.h>

void	ft_split_print(char bits[])
{
	int	i;
	int	offset;

	i = 31;
	offset = 8;
	while (bits[i])
	{
		if (offset == 0)
		{
			offset = 8;
			write(1, " ", 1);
		}
		write(1, &bits[i], 1);
		offset--;
		i--;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	char bits[] = "00000000000000000000000000000000";

	if (argc == 1 || (argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0'))
	{
		write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 37);
		return (0);
	}
	i = 1;
	while (argv[i])
	{
		if (ft_valid(argv[i]))
		{
			ft_add(&argv[i][1], bits);
		}
		else
			return (error());
		i++;
	}
	ft_split_print(bits);
	return (0);
}