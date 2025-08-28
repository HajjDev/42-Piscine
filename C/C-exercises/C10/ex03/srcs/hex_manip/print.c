/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 11:54:40 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/26 11:54:42 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	ft_printaddress(int nbr, char *base, int width)
{
	int		address[9];
	int		i;
	char	c;

	i = 0;
	if (nbr == 0)
		ft_zeros(width);
	else
	{
		while (nbr > 0)
		{
			address[i++] = nbr % 16;
			nbr /= 16;
		}
		ft_zeros(width - i);
		while (i > 0)
		{
			c = base[address[--i]];
			write(1, &c, 1);
		}
	}
}

void	ft_printhex(int status, char *buffer, char *base)
{
	int		j;
	char	n1;
	char	n2;

	j = 0;
	write(1, "  ", 2);
	while (j < 16)
	{
		if (j < status)
		{
			n1 = base[((unsigned char)buffer[j] / 16)];
			n2 = base[((unsigned char)buffer[j] % 16)];
			write(1, &n1, 1);
			write(1, &n2, 1);
		}
		else
			write(1, "  ", 2);
		write(1, " ", 1);
		if (j == 7)
			write(1, " ", 1);
		j++;
	}
}

void	ft_printhex_default(int status, char *buffer, char *base)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		write(1, " ", 1);
		if (i + 1 < status)
		{
			write(1, &base[((unsigned char)buffer[i + 1] / 16)], 1);
			write(1, &base[((unsigned char)buffer[i + 1] % 16)], 1);
			write(1, &base[((unsigned char)buffer[i] / 16)], 1);
			write(1, &base[((unsigned char)buffer[i] % 16)], 1);
		}
		else if (i < status)
		{
			write(1, &base[0], 1);
			write(1, &base[0], 1);
			write(1, &base[((unsigned char)buffer[i] / 16)], 1);
			write(1, &base[((unsigned char)buffer[i] % 16)], 1);
		}
		else
			write(1, "    ", 4);
		i += 2;
	}
}

void	ft_printchar(int status, char *buffer)
{
	int				j;
	unsigned char	c;

	j = 0;
	write(1, " |", 2);
	while (j < status)
	{
		c = buffer[j];
		if (c >= 32 && c <= 126)
			write(1, &c, 1);
		else
			write(1, ".", 1);
		j++;
	}
	write(1, "|", 1);
}
