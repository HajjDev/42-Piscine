/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 00:09:14 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/13 00:28:47 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*to_add_elem;

	to_add_elem = (t_list *)malloc(sizeof(t_list));
	if (to_add_elem == NULL)
		return (0);
	to_add_elem->data = data;
	to_add_elem->next = NULL;
	return (to_add_elem);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*element;

	element = ft_create_elem(data);
	if (element == NULL)
		return ;
	if (*begin_list == NULL)
		*begin_list = element;
	else
	{
		element->next = *begin_list;
		*begin_list = element;
	}
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*linked_list;
	t_list	*element_to_add;

	i = 0;
	linked_list = NULL;
	while (i < size)
	{
		ft_list_push_front(&linked_list, strs[i]);
		i++;
	}
	return (linked_list);
}

/*
#include <stdio.h>

void	print_array(t_list *llist)
{
	while (llist != NULL)
	{
		printf("%s\n", (char *)llist->data);
		llist = llist->next;
	}
}

int	main(void)
{
	char	*strs[] = {"Hola", "Como", "Vas", "Bien"};
	t_list	*llist = ft_list_push_strs(4, strs);

	printf("Function Result:\n");
	print_array(llist);

	free(llist);
}
*/