/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:25:27 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/12 14:58:19 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_reverse(int i, char *reversed_nb, int j, char *nb_to_print)
{
	int		k;

	k = i - 1;
	while (k >= 0)
	{
		nb_to_print[k] = reversed_nb[j];
		j++;
		k--;
	}
	return (nb_to_print);
}

void	ft_convert(int nb)
{
	int		i;
	int		sign;
	char	reversed_nb_to_print[12];
	char	nb_to_print[12];

	i = 0;
	sign = nb;
	if (nb < 0)
	{
		nb = -nb;
	}
	while (nb > 0)
	{
		reversed_nb_to_print[i] = nb % 10 + '0';
		nb /= 10;
		i++;
	}
	if (sign < 0)
	{
		reversed_nb_to_print[i] = '-';
		i++;
	}
	reversed_nb_to_print[i] = '\0';
	ft_reverse(i, reversed_nb_to_print, 0, nb_to_print);
	write(1, nb_to_print, i);
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
		ft_convert(nb);
	}
}
