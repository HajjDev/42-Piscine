/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:30:11 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/12 23:04:49 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	char	*temp;

	i = 0;
	while (tab[i + 1])
	{
		if (cmp(tab[i], tab[i + 1]) > 0)
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

/*
#include <stdio.h>

void	print_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}
}


int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((int)s1[i] - (int)s2[i]);
		i++;
	}
	return ((int)s1[i] - (int)s2[i]);
}

int	main(void)
{
	char	*str1[] = {"Hola", "Alo", "Ball", "Zebra", NULL};
	char	*str2[] = {"Aha", "Bawlright", "Call", NULL};

	printf("Test1\n");
	ft_advanced_sort_string_tab(str1, &ft_strcmp);
	print_array(str1);

	printf("Test2\n");
	ft_advanced_sort_string_tab(str2, &ft_strcmp);
	print_array(str2);
}
*/