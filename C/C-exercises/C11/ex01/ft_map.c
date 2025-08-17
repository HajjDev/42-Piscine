/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:18:40 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/12 11:29:26 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*modified_array;
	int	i;

	modified_array = (int *)malloc(length * sizeof(int));
	i = 0;
	if (modified_array == NULL)
		return (0);
	while (i < length)
	{
		modified_array[i] = f(tab[i]);
		i++;
	}
	return (modified_array);
}

/*
#include <stdio.h>

void	print_array(int *array, int length)
{
	for (int i = 0; i < length; i++)
		printf("%d\n", array[i]);
}

int	add_one(int n)
{
	return (n + 1);
}

int	times_two(int n)
{
	return (n * 2);
}

int	minus_one(int n)
{
	return (n - 1);
}

int	main(void)
{
	int	array[] = {1, 2, 3, 4, 5};

	printf("Original:\n");
	print_array(array, 5);
	
	printf("Test 1:\n");
	printf("Modified - Test1:\n");
	print_array(ft_map(array, 5, &add_one), 5);

	printf("Test 2:\n");
	printf("Modified - Test2:\n");
	print_array(ft_map(array, 5, &times_two), 5);

	printf("Test 3:\n");
	printf("Modified - Test3:\n");
	print_array(ft_map(array, 5, &minus_one), 5);

	return (0);
}
*/