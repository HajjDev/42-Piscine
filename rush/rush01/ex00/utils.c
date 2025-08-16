/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-moo <thde-moo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 11:42:38 by thde-moo          #+#    #+#             */
/*   Updated: 2025/08/16 13:06:14 by thde-moo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rush01.h"

void	ft_putchar(char ch)
{
	write (1, &ch, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
}

int	is_space(char ch)
{
	return (ch == ' ' || (ch >= 9 && ch <= 13));
}

int	error(void)
{
	ft_putstr("Error\n");
	return (0);
}
