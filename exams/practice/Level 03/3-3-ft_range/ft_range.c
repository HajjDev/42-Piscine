/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 20:36:12 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/28 20:38:44 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int *ft_range(int start, int end)
{
    int *array;
    int array_size;
    int i;

    if (start >= end)
        array_size = (start - end) + 1;
    else
        array_size = (end - start) + 1;
    array = (int *)malloc(array_size * sizeof(int));
    if (!array)
        return (NULL);
    i = 0;
    while (i < array_size)
    {
        if (start >= end)
            array[i] = start + i;
        else
            array[i] = start - i;
        i++;
    }
    return (array);
}