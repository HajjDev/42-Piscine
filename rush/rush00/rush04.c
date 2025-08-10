/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoemaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 10:19:52 by vgoemaer          #+#    #+#             */
/*   Updated: 2025/08/10 16:47:42 by vgoemaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

#include <unistd.h>

/*
void	ft_rush04(int x, int y)
{
	int	x_now;
	int	y_now;

	x_now = 1;
	y_now = 1;
	if (y_now == 1)
	{
		ft_putchar('A');
		x_now++;
		while (x_now < x)
		{
			ft_putchar('B');
			x_now++;
		}
		if (x > 1)
		{
			ft_putchar('C');
		}
		ft_putchar('\n');
		y_now++;
		x_now = 1;
	}
	while (y_now < y)
	{
		ft_putchar('B');
		x_now++;
		while (x_now < x)
		{
			ft_putchar(' ');
			x_now++;
		}
		if (x > 1)
		{
			ft_putchar('B');
		}
		ft_putchar('\n');
		y_now++;
		x_now = 1;
	}
	if (y_now == y)
	{
		ft_putchar('C');
		x_now++;
		while (x_now < x)
		{
			ft_putchar('B');
			x_now++;
		}
		if (x > 1)
		{
			ft_putchar('A');
		}
	}
}
*/

void	ft_first(int x)
{
	int	x_now;

	x_now = 1;
	ft_putchar('A');
	x_now++;
	while (x_now < x)
	{
		ft_putchar('B');
		x_now++;
	}
	if (x > 1)
	{
		ft_putchar('C');
	}
	ft_putchar('\n');
}

void	ft_notlast(int x, int y)
{
	int	y_now;
	int	x_now;

	y_now = 2;
	x_now = 1;
	while (y_now < y)
	{
		ft_putchar('B');
		x_now++;
		while (x_now < x)
		{
			ft_putchar(' ');
			x_now++;
		}
		x_now = 1;
		if (x > 1)
		{
			ft_putchar('B');
		}
		ft_putchar('\n');
		y_now++;
	}
}

void	ft_last(int x)
{
	int	x_now;

	x_now = 1;
	ft_putchar('C');
	x_now++;
	while (x_now < x)
	{
		ft_putchar('B');
		x_now++;
	}
	if (x > 1)
	{
		ft_putchar('A');
	}
}

void	ft_rush04(int x, int y)
{
	if (x < 1 || y < 1)
		write(1, "Give a valid int", 16);
	else
	{
		ft_first(x);
		ft_notlast(x, y);
		ft_last(x);
	}
}
