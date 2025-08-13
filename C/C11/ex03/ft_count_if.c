/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:50:56 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/12 11:57:26 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	element_count;
	int	i;

	element_count = 0;
	i = 0;
	while (i < length)
	{
		if (f(tab[i]) != 0)
			element_count++;
		i++;
	}
	return (element_count);
}

/*
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

int	is_even(char *str)
{
	return (ft_strlen(str) % 2 == 0);
}

int	main(void)
{
	char* tab1[] = {"hiiibrooo", "hihia", "blobloa"};
	char* tab2[] = {"hiiibroo", "hihi", "blobloa"};
	char* tab3[] = {"hiiibrooo", "hihia", "bloblo"};

	printf("%d\n", ft_count_if(tab1, 3, &is_even));
	printf("%d\n", ft_count_if(tab2, 3, &is_even));
	printf("%d\n", ft_count_if(tab3, 3, &is_even));
	return (0);
}
*/