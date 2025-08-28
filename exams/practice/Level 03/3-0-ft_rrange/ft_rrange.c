/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 20:17:28 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/28 20:21:49 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int *ft_rrange(int start, int end)
{
    int *array;
    int array_size;
    int i;

    if (end >= start)
        array_size = (end - start) + 1;
    else
        array_size =  (start - end) + 1;
    array = (int *)malloc(array_size * sizeof(int));
    if (!array)
        return (NULL);
    i = 0;
    while (i < array_size)
    {
        if (end >= start)
            array[i] = end + i;
        else
            array[i] = end - i;
        i++;
    }
    return (array);
}