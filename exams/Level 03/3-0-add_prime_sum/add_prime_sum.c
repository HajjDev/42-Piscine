/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 19:52:46 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/28 20:05:35 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int is_prime(int n)
{
    int i;

    i = 2;
    if (n == 1 || n == 0)
        return (0);
    while (i < n)
    {
        if (n % i == 0)
            return (0);
        i++;
    }
    return (1);
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

void    ft_putnbr(int n)
{
    char    number;

    if (n == -2147483648)
    {
        write(1, "-2147483648", 11);
        return ;
    }
    if (n < 0)
    {
        write(1, "-", 1);
        ft_putnbr(-n);
        return ;
    }
    if (n >= 10)
        ft_putnbr(n / 10);
    number = (n % 10) + '0';
    write(1, &number, 1);
}

int main(int argc, char **argv)
{
    int sum;
    int num;
    int i;

    if (argc != 2 || ft_atoi(argv[1]) < 0)
    {
        ft_putnbr(0);
        write(1, "\n", 1);
        return (0);
    }
    num = ft_atoi(argv[1]);
    i = 0;
    sum = 0;
    while (i <= num)
    {
        if (is_prime(i))
            sum += i;
        i++;
    }
    ft_putnbr(sum);
    write(1, "\n", 1);
    return (0);
}