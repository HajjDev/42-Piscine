/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 22:51:58 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/10 10:23:53 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*array;
	int	i;
	int	nb_to_add;

	if (min >= max)
		return (0);
	i = 0;
	nb_to_add = min;
	array = (int *)malloc((max - min) * sizeof(int));
	if (array == NULL)
		return (0);
	while (i < (max - min))
	{
		array[i] = nb_to_add;
		i++;
		nb_to_add++;
	}
	return (array);
}
