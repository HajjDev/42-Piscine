/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:17:59 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/13 14:06:36 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int
(*cmp)(), void (*free_fct)(void *))
{
	t_list	*current;
	t_list	*next;
	t_list	*previous_element;

	current = *begin_list;
	next = NULL;
	previous_element = NULL;
	while (current)
	{
		next = current->next;
		if ((*cmp)(current->data, data_ref) == 0)
		{
			if (!previous_element)
				*begin_list = current->next;
			else
				previous_element->next = next;
			(*free_fct)(current->data);
			free(current);
		}
		else
			previous_element = current;
		current = next;
	}
}
