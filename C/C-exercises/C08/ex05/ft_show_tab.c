/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:40:43 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/11 13:14:40 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
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

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != NULL)
	{
		ft_putstr(par[i].str);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		i++;
	}
}

/*
int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
	{
		length++;
	}
	return (length);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	if (src == NULL)
		return (0);
	dest = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (dest == NULL)
	{
		return (0);
	}
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_free_memory(struct s_stock_str *array, int i)
{
	while (i >= 0)
	{
		free(array[i].copy);
		free(array[i].str);
		i--;
	}
	free(array);
	return (NULL);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*array;
	int					i;

	array = malloc(sizeof(t_stock_str) * (ac + 1));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		if (av[i] == NULL)
		{
			return (ft_free_memory(array, i));
		}
		array[i].size = ft_strlen(av[i]);
		array[i].str = av[i];
		array[i].copy = ft_strdup(av[i]);
		if (array[i].copy == NULL || array[i].str == NULL)
			return (ft_free_memory(array, i));
		i++;
	}
	array[i].str = NULL;
	return (array);
}

int	main(int argc, char **argv)
{
	ft_show_tab(ft_strs_to_tab(argc, argv));
	return (0);
}
*/