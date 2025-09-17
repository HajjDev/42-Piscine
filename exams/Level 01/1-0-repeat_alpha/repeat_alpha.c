/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:41:16 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/28 17:48:00 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int get_repeat(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (c - 'A' + 1);
    else
        return (c - 'a' + 1);
}

int main(int argc, char **argv)
{
    int i;
    int j;
    int times;

    if (argc != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    i = 1;
    times = 0;
    while (argv[i])
    {
        j = 0;
        while (argv[i][j])
        {
            if ((argv[i][j] >= 'a' && argv[i][j] <= 'z') || ((argv[i][j] >= 'A' && argv[i][j] <= 'Z')))
            {
                times = get_repeat(argv[i][j]);
                while (times)
                {
                    write(1, &argv[i][j], 1);
                    times--;
                }
            }
            else
                write(1, &argv[i][j], 1);
            j++;
        }
        i++;
    }
    write(1, "\n", 1);
    return (0);
}