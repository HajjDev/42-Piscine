/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:31:52 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/12 11:56:17 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char *))
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (f(tab[i]) != 0)
			return (1);
		i++;
	}
	return (0);
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
	char* tab1[] = {"hiiibrooo", "hihia", "blobloa", NULL};
	char* tab2[] = {"hiiibroo", "hihi", "blobloa", NULL};
	char* tab3[] = {"hiiibrooo", "hihia", "bloblo", NULL};

	printf("%d\n", ft_any(tab1, &is_even));
	printf("%d\n", ft_any(tab2, &is_even));
	printf("%d\n", ft_any(tab3, &is_even));
	return (0);
}
*/