/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 11:51:26 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/13 11:59:46 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	current_elem;

	current_elem = 0;
	while (begin_list)
	{
		if (current_elem == nbr)
			return (begin_list);
		begin_list = begin_list->next;
		current_elem++;
	}
	return (NULL);
}

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

	printf("The 4th element of the list is: %s\n", (char *)ft_list_at(llist, 3)->data);
	printf("The 1st element of the list is: %s\n", (char *)ft_list_at(llist, 0)->data);
	printf("The 8th element of the list is: %p\n", (char *)ft_list_at(llist, 8));
	free(llist);
}
