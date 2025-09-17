/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 20:51:42 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/28 21:12:21 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putnbr(int n)
{
    char    num;

    if (n >= 10)
        ft_putnbr(n / 10);
    num = (n % 10) + '0';
    write(1, &num, 1);
}

int ft_atoi(const char *str)
{
    int i;
    int sign;
    int number;

    i = 0;
    sign = 1;
    number = 0;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        number = (number * 10) + str[i] - '0';
        i++;
    }
    return (number * sign);
}

int main(int argc, char **argv)
{
    int n;
    int mults;

    if (argc < 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    n = ft_atoi(argv[1]);
    mults = 1;
    while (mults < 10)
    {
        ft_putnbr(mults);
        write(1, " x ", 3);
        ft_putnbr(n);
        write(1, " = ", 3);
        ft_putnbr(mults * n);
        write(1, "\n", 1);
        mults++;
    }
    return (0);
}