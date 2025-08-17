/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:12:53 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/13 16:17:34 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*current;
	t_list	*last_element;

	current = *begin_list1;
	last_element = current;
	if (*begin_list1 == NULL)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	while (last_element->next != NULL)
	{
		last_element = last_element->next;
	}
	last_element->next = begin_list2;
	*begin_list1 = current;
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

int	main(void)
{
	t_list	*llist = (t_list *)malloc(sizeof(t_list));
	t_list	*llist2 = (t_list *)malloc(sizeof(t_list));
	int	a = 1;
	int	b = 2;
	int	c = 3;
	int d = 8;
	int	e = 9;
	int	f = 1;

	void	*data1 = &a;
	void	*data2 = &b;
	void	*data3 = &c;
	void	*data4 = &d;
	void	*data5 = &e;
	void	*data6 = &f;

	llist = ft_create_elem(data1);
	llist->next = ft_create_elem(data2);
	llist->next->next = ft_create_elem(data3);

	llist2 = ft_create_elem(data4);
	llist2->next = ft_create_elem(data5);
	llist2->next->next = ft_create_elem(data6);

	printf("Original Array - 1:\n");
	print_array(llist);
	printf("Original Array - 2:\n");
	print_array(llist2);
	printf("After merge:\n");
	ft_list_merge(&llist, llist2);
	print_array(llist);

	free(llist);
	free(llist2);
}
*/