/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:16:36 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/14 00:45:47 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	beginning_check(t_list **begin_list, t_list *element_to_add,
void *data, int (*cmp)())
{
	t_list	*current;

	current = *begin_list;
	if (!element_to_add)
		return (0);
	if (!current)
	{
		*begin_list = element_to_add;
		return (1);
	}
	if ((*cmp)(data, current->data) < 0)
	{
		element_to_add->next = current;
		*begin_list = element_to_add;
		return (1);
	}
	return (0);
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*current;
	t_list	*element_to_add;

	current = *begin_list;
	element_to_add = ft_create_elem(data);
	if (!element_to_add)
		return ;
	if (!beginning_check(begin_list, element_to_add, data, cmp))
	{
		while (current->next)
		{
			if ((*cmp)(data, current->next->data) < 0)
			{
				element_to_add->next = current->next;
				current->next = element_to_add;
				return ;
			}
			current = current->next;
		}
		current->next = element_to_add;
	}
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

int	cmp(void *a, void *b)
{
	return (*(int *)a - *(int *)b);
}

int	main(void)
{
	t_list	*llist = (t_list *)malloc(sizeof(t_list));
	int	a = 1;
	int	b = 2;
	int	c = 3;
	int d = 8;
	int	e = 9;
	int	f = 12;
	
	int to_insert = -1;
	void	*data_to_insert = &to_insert;

	void	*data1 = &a;
	void	*data2 = &b;
	void	*data3 = &c;
	void	*data4 = &d;
	void	*data5 = &e;
	void	*data6 = &f;

	llist = ft_create_elem(data1);
	llist->next = ft_create_elem(data2);
	llist->next->next = ft_create_elem(data3);
	llist->next->next->next = ft_create_elem(data4);
	llist->next->next->next->next = ft_create_elem(data5);
	llist->next->next->next->next->next = ft_create_elem(data6);

	printf("Original Array:\n");
	print_array(llist);
	printf("After insertion Array:\n");
	ft_sorted_list_insert(&llist, data_to_insert, &cmp);
	print_array(llist);

	free(llist);
}
*/