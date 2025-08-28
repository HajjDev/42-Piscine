/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 20:24:31 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/28 20:32:43 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putnbr_base(int n, char *base, int base_length)
{
    char    num;

    if (n >= base_length)
        ft_putnbr_base(n / base_length, base, base_length);
    num = base[n % base_length];
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
    return (number *sign);
}

int main(int argc, char **argv)
{
    int n;

    if (argc != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    n = ft_atoi(argv[1]);
    ft_putnbr_base(n, "0123456789abcdef", 16);
    write(1, "\n", 1);
    return (0);
}