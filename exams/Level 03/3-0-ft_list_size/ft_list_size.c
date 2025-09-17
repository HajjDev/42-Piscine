/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 20:14:30 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/28 20:15:04 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
    int size;

    size = 0;
    while (begin_list)
    {
        size++;
        begin_list = begin_list->next;
    }
    return (size);
}