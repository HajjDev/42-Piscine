/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:04:45 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/28 18:11:28 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    mini_put_nbr(int n)
{
    char c;
    if (n > 0)
        mini_put_nbr(n / 10);
    if (n != 0)
    {
        c = (n % 10) + '0';
        write(1, &c, 1);
    }
}

int main(void)
{
    int i;

    i = 1;
    while (i < 101)
    {
        if (i % 3 == 0 && i % 5 == 0)
            write(1, "fizzbuzz\n", 9);
        else if (i % 3 == 0)
            write(1, "fizz\n", 5);
        else if (i % 5 == 0)
            write(1, "buzz\n", 5);
        else
        {
             mini_put_nbr(i);
             write(1, "\n", 1);
        }
        i++;
    }
    return (0);
}