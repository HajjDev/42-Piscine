/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:58:52 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/28 18:01:22 by cel-hajj         ###   ########.fr       */
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
        if ((argv[1][i] >= 'a' && argv[1][i] <= 'm') || (argv[1][i] >= 'A' && argv[1][i] <= 'M'))
        {
            c = argv[1][i] + 13;
            write(1, &c, 1);
        }
        else if ((argv[1][i] >= 'n' && argv[1][i] <= 'z') || (argv[1][i] >= 'N' && argv[1][i] <= 'Z'))
        {
            c = argv[1][i] - 13;
            write(1, &c, 1);
        }
        else
            write(1, &argv[1][i], 1);
        i++;
    }
    write(1, "\n", 1);
    return (0);
}