/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 20:51:38 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/28 20:51:39 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_find(char *str, char c, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (str[i] == c)
            return (i);
        i++;
    }
    return (-1);
}

int ft_inbase(char c, int str_base)
{
    char str[] = "0123456789abcdef";
    char str2[] = "0123456789ABCDEF";
    if (ft_find((char *)str, c, str_base) != -1)
        return (ft_find((char *)str, c, str_base));
    return (ft_find((char *)str2, c, str_base));
}

int	ft_atoi_base(const char *str, int str_base)
{
    int number;
    int i;
    int sign;

    i = 0;
    number = 0;
    sign = 1;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    while (ft_inbase(str[i], str_base) != -1)
    {
        number = (number * str_base) + ft_inbase(str[i], str_base);
        i++;
    }
    return (number * sign);
}