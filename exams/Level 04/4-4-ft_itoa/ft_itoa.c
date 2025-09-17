/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 22:56:42 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/28 23:07:40 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_digits(long n)
{
    int size;

    size = 0;
    while (n > 0)
    {
        size++;
        n /= 10;
    }
    return (size);
}

char    *ft_strrev(char *str)
{
    int     i;
    int     size;
    char    temp;

    i = 0;
    size = 0;
    while (str[size])
        size++;
    size--;
    while (i < size)
    {
        temp = str[i];
        str[i] = str[size];
        str[size] = temp;
        i++;
        size--;
    }
    return (str);
}

char    *ft_itoa(int nbr)
{
    char    *number;
    long    n;
    int     neg;
    int     i;
    int     digits;

    if (nbr == 0)
    {
        number = malloc(2);
        if (!number)
            return (NULL);
        number[0] = '0';
        number[1] = '\0';
        return (number);
    }
    if (nbr < 0)
    {
        neg = 1;
        n = -(long)nbr;
    }
    else
        n = nbr;
    digits = ft_digits(n);
    number = (char *)malloc((digits + 1 + neg) * sizeof(char));
    if (!number)
        return (NULL);
    i = 0;
    while (n > 0)
    {
        number[i] = (n % 10) + '0';
        n = n / 10;
        i++;
    }
    if (neg)
    {
        number[i] = '-';
        i++;
    }
    number[i] = '\0';
    ft_strrev(number);
    return (number);
}