/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:32:19 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/28 18:34:05 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int main(int argc, char **argv)
{
    int i;

    if (argc != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    i = ft_strlen(argv[1]) - 1;
    while (argv[1][i] && (argv[1][i] == ' ' || (argv[1][i] >= 9 && argv[1][i] <= 13)))
        i--;
    while (argv[1][i] && !(argv[1][i] == ' ' || (argv[1][i] >= 9 && argv[1][i] <= 13)))
        i--;
    i++;
    while (argv[1][i] && !(argv[1][i] == ' ' || (argv[1][i] >= 9 && argv[1][i] <= 13)))
    {
        write(1, &argv[1][i], 1);
        i++;
    }
    write(1, "\n", 1);
    return (0);
}