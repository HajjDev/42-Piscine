/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:58:42 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/14 00:46:10 by cel-hajj         ###   ########.fr       */
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

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int
(*cmp)())
{
	while (begin_list2)
	{
		ft_sorted_list_insert(begin_list1, begin_list2->data, cmp);
		begin_list2 = begin_list2->next;
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
	t_list	*llist2 = (t_list *)malloc(sizeof(t_list));

	int	a = 1;
	int	b = 3;
	int	c = 5;
	int d = 7;
	int	e = 9;
	int	f = 11;
	void	*data1 = &a;
	void	*data2 = &b;
	void	*data3 = &c;
	void	*data4 = &d;
	void	*data5 = &e;
	void	*data6 = &f;

	int	a2 = 2;
	int	b2 = 4;
	int	c2 = 6;
	int d2 = 8;
	int	e2 = 10;
	int	f2 = 12;
	void	*data12 = &a2;
	void	*data22 = &b2;
	void	*data32 = &c2;
	void	*data42 = &d2;
	void	*data52 = &e2;
	void	*data62 = &f2;

	llist = ft_create_elem(data1);
	llist->next = ft_create_elem(data2);
	llist->next->next = ft_create_elem(data3);
	llist->next->next->next = ft_create_elem(data4);
	llist->next->next->next->next = ft_create_elem(data5);
	llist->next->next->next->next->next = ft_create_elem(data6);

	llist2 = ft_create_elem(data12);
	llist2->next = ft_create_elem(data22);
	llist2->next->next = ft_create_elem(data32);
	llist2->next->next->next = ft_create_elem(data42);
	llist2->next->next->next->next = ft_create_elem(data52);
	llist2->next->next->next->next->next = ft_create_elem(data62);

	printf("Before Merge:\n");
	print_array(llist);
	printf("After Merge:\n");
	ft_sorted_list_merge(&llist, llist2, &cmp);
	print_array(llist);

	free(llist);
	free(llist2);
}
*/