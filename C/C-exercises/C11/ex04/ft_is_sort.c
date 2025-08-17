/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:41:00 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/12 15:55:42 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort_asc(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_sort_des(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	if (ft_is_sort_asc(tab, length, f) || ft_is_sort_des(tab, length, f))
		return (1);
	return (0);
}

/*
#include <stdio.h>

int	function(int a, int b)
{
	return (a - b);
}

int	main(void)
{
	int	tab1[] = {1, 2, 3, 4, 5};
	int	tab2[] = {1, 4, 5, 6, 2};
	
	printf("Test 1\n");
	printf("%d\n", ft_is_sort(tab1, 5, &function));
	printf("Test 2\n");
	printf("%d\n", ft_is_sort(tab2, 5, &function));
	return (0);
}
*/
