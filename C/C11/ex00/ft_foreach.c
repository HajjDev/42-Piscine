/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:47:52 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/12 11:16:45 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}

/*
#include <stdio.h>

void	ft_putnbr(int n)
{
	printf("%d\n", n);
}

void	ft_putnbr_squared(int n)
{
	printf("%d\n", n * n);
}

void	ft_putnbr_neg(int n)
{
	printf("%d\n", -n);
}

int	main(void)
{
	int tab[] = {1, 2, 3, 4, 5};

	printf("Test 1:\n");
	ft_foreach(tab, 5, &ft_putnbr);

	printf("Test 2:\n");
	ft_foreach(tab, 5, &ft_putnbr_squared);

	printf("Test 3:\n");
	ft_foreach(tab, 5, &ft_putnbr_neg);

	return 0;
}
*/