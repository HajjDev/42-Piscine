/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 23:02:36 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/09 23:08:24 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	nb_to_add;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	i = 0;
	nb_to_add = min;
	*range = malloc((max - min) * sizeof(int));
	if (*range == NULL)
		return (-1);
	while (i < (max - min))
	{
		(*range)[i] = nb_to_add;
		i++;
		nb_to_add++;
	}
	return (i);
}
