/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:39:31 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/28 18:43:57 by cel-hajj         ###   ########.fr       */
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

int ft_find(char *str, char c)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return (1);
        i++;
    }
    return (0);
}

int main(int argc, char **argv)
{
    int i;
    int j;

    if (argc != 3)
    {
        write(1, "\n", 1);
        return (0);
    }
    i = 0;
    j = 0;
    char    seen[ft_strlen(argv[1]) + ft_strlen(argv[2]) + 1];
    while (argv[1][i])
    {
        if (!ft_find((char *)seen, argv[1][i]))
        {
            write(1, &argv[1][i], 1);
            seen[j] = argv[1][i];
            j++;
        }
        i++;
    }
    i = 0;
    while (argv[2][i])
    {
        if (!ft_find((char *)seen, argv[2][i]))
        {
            write(1, &argv[2][i], 1);
            seen[j] = argv[2][i];
            j++;
        }
        i++;
    }
    return (0);
}