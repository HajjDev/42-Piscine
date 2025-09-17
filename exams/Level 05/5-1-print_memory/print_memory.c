/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 23:53:42 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/29 00:07:49 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_hex(int n, char *base, int base_length)
{
    char c;

    if (n >= base_length)
        ft_hex(n / base_length, base, base_length);
    c = base[n % 16];
    write(1, &c, 1);
}

void    ft_putchar(char c)
{
    if (c >= 32 && c <= 126)
        write(1, &c, 1);
    else
        write(1, ".", 1);
}

void    print_memory(const void *addr, size_t size)
{
    unsigned char   *t;
    size_t          i;
    int             col;
    size_t          temp;

    i = 0;
    t = (unsigned char *)addr;
    while (i < size)
    {
        temp = i;
        col = 0;
        while (col < 16)
        {
            if (i < size)
            {
                if (t[i] < 16)
                    ft_putchar('0');
                ft_hex(t[i], "0123456789abcdef", 16);
            }
            else
                write(1, "  ", 2);
            if (col % 2 == 1)
                write(1, " ", 1);
            col++;
            i++;
        }
        col = 0;
        i = temp;
        while (col < 16 && i < size)
        {
            ft_putchar(t[i]);
            col++;
            i++;
        }
        write(1, "\n", 1);
    }
}

int		main(void)
{
	int		tab[15] = {3772900067, 58597, 59111,
		59625, 60139, 60653, 61167, 61681, 62195, 62709, 63223, 63737, 64251,
	64765, 65279};

	print_memory(tab, sizeof(tab));
	return (0);
}