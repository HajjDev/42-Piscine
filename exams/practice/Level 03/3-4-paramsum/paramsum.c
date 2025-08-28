/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 20:33:49 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/28 20:35:24 by cel-hajj         ###   ########.fr       */
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

int main(int argc, char **argv)
{
    ft_putnbr(argc - 1);
    return (0);
}