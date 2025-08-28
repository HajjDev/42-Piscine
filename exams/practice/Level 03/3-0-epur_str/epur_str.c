/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 20:06:21 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/28 20:13:25 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    int last_word_index;

    if (argc != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    i = 0;
    last_word_index = 0;
    while (argv[1][i])
    {
        if (!(argv[1][i] == ' ' || (argv[1][i] >= 9 && argv[1][i] <= 13)))
            last_word_index = i;
        i++;
    }
    i = 0;
    while (argv[1][i])
    {
        while(argv[1][i] && (argv[1][i] == ' ' || (argv[1][i] >= 9 && argv[1][i] <= 13)))
            i++;
        if (argv[1][i] && !(argv[1][i] == ' ' || (argv[1][i] >= 9 && argv[1][i] <= 13)))
        {
            while (argv[1][i] && !(argv[1][i] == ' ' || (argv[1][i] >= 9 && argv[1][i] <= 13)))
            {
                write(1, &argv[1][i], 1);
                i++;
            }
            if (i - 1 != last_word_index)
                write(1, " ", 1);
        }
    }
    write(1, "\n", 1);
    return (0);
}