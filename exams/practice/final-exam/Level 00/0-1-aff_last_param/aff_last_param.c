/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_last_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 22:18:46 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/26 22:20:29 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    int j;

    if (argc < 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    i = argc - 1;
    j = 0;
    while (argv[i][j])
    {
        write(1, &argv[i][j], 1);
        j++;
    }
    write(1, "\n", 1);
    return (0);
}