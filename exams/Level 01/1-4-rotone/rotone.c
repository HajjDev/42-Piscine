/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:15:57 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/28 18:19:29 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
    int     i;
    char    c;

    if (argc != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    i = 0;
    while (argv[1][i])
    {
        if (argv[1][i] == 'z' || argv[1][i] == 'Z')
        {
            if (argv[1][i] == 'z')
                write(1, "a", 1);
            else
                write(1, "A", 1);
        }
        else if ((argv[1][i] >= 'a' && argv[1][i] <= 'z') || (argv[1][i] >= 'A' && argv[1][i] <= 'Z'))
        {
            c = argv[1][i] + 1;
            write(1, &c, 1);
        }
        else
            write(1, &argv[1][i], 1);
        i++;
    }
    return (0);
}