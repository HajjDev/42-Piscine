/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:00:34 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/13 12:07:51 by cel-hajj         ###   ########.fr       */
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

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*reversed_list;
	t_list	*to_copy;

	to_copy = *begin_list;
	reversed_list = NULL;
	while (to_copy)
	{
		ft_list_push_front(&reversed_list, to_copy->data);
		to_copy = to_copy->next;
	}
	*begin_list = reversed_list;
}

/*
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

	printf("Original Array:\n");
	print_array(llist);

	printf("Reversed Array:\n");
	ft_list_reverse(&llist);
	print_array(llist);

	free(llist);
}
*/