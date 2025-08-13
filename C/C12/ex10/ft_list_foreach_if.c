/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:35:31 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/13 14:09:48 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void
*data_ref, int (*cmp)())
{
	while (begin_list)
	{
		if ((*cmp)(begin_list->data, data_ref) == 0)
			(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}

/*
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

#include <stdio.h>

void	ft_mult(void *data)
{
	*(int *)data *= 3;
}

int	cmp(void *data1, void *data2)
{
	if (*(int *)data1 == *(int *)data2)
		return (0);
	return (1);
}

void	print_array(t_list *llist)
{
	while (llist != NULL)
	{
		printf("%d\n", *(int *)llist->data);
		llist = llist->next;
	}
}

int	main(void)
{
	t_list	*llist = NULL;
	int	n1 = 4;
	int n2 = 6;
	int comp = 4;
	void	*data1 = &n1;
	void	*data2 = &n2;
	void	*datacomp = &comp;
	
	ft_list_push_front(&llist, data1);
	ft_list_push_front(&llist, data2);
	printf("Before applying:\n");
	print_array(llist);

	printf("After applying:\n");
	ft_list_foreach_if(llist, &ft_mult, datacomp, &cmp);
	print_array(llist);

	free(llist);
}
*/