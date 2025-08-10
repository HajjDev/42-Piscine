/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 22:49:17 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/08 23:07:03 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
		{
			return ((int)s1[i] - (int)s2[i]);
		}
		i++;
	}
	return ((int)s1[i] - (int)s2[i]);
}

void	ft_sort_matrix(char **matrix, int length)
{
	int		i;
	int		j;
	char	*temp;

	i = 1;
	while (i < length)
	{
		j = i + 1;
		while (j < length)
		{
			if (ft_strcmp(matrix[j], matrix[i]) < 0)
			{
				temp = matrix[j];
				matrix[j] = matrix[i];
				matrix[i] = temp;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	ft_sort_matrix(argv, argc);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
