/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 23:53:42 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/13 00:00:28 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	if (begin_list == NULL)
		return (NULL);
	while (begin_list->next != NULL)
		begin_list = begin_list->next;
	return (begin_list);
}

/*
#include <stdio.h>

void	print_array(t_list *llist)
{
	while (llist != NULL)
	{
		printf("%d\n", *(int *)llist->data);
		llist = llist->next;
	}
}

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

int	main(void)
{
	t_list	*llist = (t_list *)malloc(sizeof(t_list));
	int	a = 1;
	int	b = 2;
	int	c = 3;

	void	*data1 = &a;
	void	*data2 = &b;
	void	*data3 = &c;

	llist = ft_create_elem(data1);
	llist->next = ft_create_elem(data2);
	llist->next->next = ft_create_elem(data3);

	printf("Original Array\n");
	print_array(llist);
	printf("The last element is: %d\n", *(int *)ft_list_last(llist)->data);

	free(llist);
}
*/