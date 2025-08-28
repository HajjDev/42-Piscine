/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:36:34 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/28 18:38:35 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bits(unsigned char octet)
{
    unsigned char r;
    unsigned int char_len;

    r = 0;
    char_len = 8;
    while (char_len)
    {
        r = (r << 1) | (octet & 1);
        octet >>= 1;
        char_len--;
    }
    return (r);
}