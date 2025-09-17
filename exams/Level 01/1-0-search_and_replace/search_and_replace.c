/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:49:08 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/28 17:51:37 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    int j;
    
    if (argc != 4)
    {
        write(1, "\n", 1);
        return (0);
    }
    i = 0;
    while (argv[1][i])
    {
        if (argv[1][i] == argv[2][0])
            write(1, &argv[3][0], 1);
        else
            write(1, &argv[1][i], 1);
        i++;
    }
    write(1, "\n", 1);
    return (0);
}