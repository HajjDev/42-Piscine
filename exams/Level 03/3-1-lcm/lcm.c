/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 19:28:51 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/28 19:31:32 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int    hcf(unsigned int a, unsigned int b)
{
    if (b == 0)
        return (a);
    return (hcf(b, a % b));
}

unsigned int    lcm(unsigned int a, unsigned int b)
{
    return ((a * b) / hcf(a, b));
}