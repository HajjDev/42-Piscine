/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoemaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 10:19:52 by vgoemaer          #+#    #+#             */
/*   Updated: 2025/08/10 12:35:06 by vgoemaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_first(int x)
{
	int	x_now;

	x_now = 1;
	ft_putchar('/');
	x_now++;
	while (x_now < x)
	{
		ft_putchar('*');
		x_now++;
	}
	if (x > 1)
	{
		ft_putchar('\\');
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
		ft_putchar('*');
		x_now++;
		while (x_now < x)
		{
			ft_putchar(' ');
			x_now++;
		}
		x_now = 1;
		if (x > 1)
		{
			ft_putchar('*');
		}
		ft_putchar('\n');
		y_now++;
	}
}

void	ft_last(int x)
{
	int	x_now;

	x_now = 1;
	ft_putchar('\\');
	x_now++;
	while (x_now < x)
	{
		ft_putchar('*');
		x_now++;
	}
	if (x > 1)
	{
		ft_putchar('/');
	}
}

void	ft_rush01(int x, int y)
{
	ft_first(x);
	ft_notlast(x, y);
	ft_last(x);
}
