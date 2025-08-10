/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:14:29 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/09 13:00:50 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*ft_reverse(char *reversed_nb, int i, char *to_print_nb)
{
	int	k;
	int	l;

	k = i - 1;
	l = 0;
	while (k >= 0)
	{
		to_print_nb[k] = reversed_nb[l];
		k--;
		l++;
	}
	return (to_print_nb);
}

void	ft_convert_and_print(int nb)
{
	int		signe;
	char	reversed_nb[12];
	char	to_print_nb[12];
	int		i;

	signe = nb;
	i = 0;
	if (nb < 0)
	{
		nb = -nb;
	}
	while (nb > 0)
	{
		reversed_nb[i] = nb % 10 + '0';
		nb /= 10;
		i++;
	}
	if (signe < 0)
	{
		reversed_nb[i] = '-';
		i++;
	}
	reversed_nb[i] = '\0';
	ft_reverse(reversed_nb, i, to_print_nb);
	write(1, to_print_nb, i);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (nb == 0)
	{
		write(1, "0", 1);
	}
	else
	{
		ft_convert_and_print(nb);
	}
}
