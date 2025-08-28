/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 19:24:08 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/28 19:28:04 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int pgcd(int n1, int n2)
{
    if (n2 == 0)
        return (n1);
    return (pgcd(n2, n1 % n2));
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("\n");
        return (0);
    }
    printf("%d\n", pgcd(atoi(argv[1]), atoi(argv[2])));
    return (0);
}