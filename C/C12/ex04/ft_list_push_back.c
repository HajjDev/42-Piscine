/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 23:56:45 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/13 00:07:06 by cel-hajj         ###   ########.fr       */
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

void	ft_list_push_back(t_list **begin_list, void	*data)
{
	t_list	*element;
	t_list	*temp;

	element = ft_create_elem(data);
	if (element == NULL)
		return ;
	if (*begin_list == NULL)
		*begin_list = element;
	temp = *begin_list;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = element;
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

int	main(void)
{
	t_list	*llist = (t_list *)malloc(sizeof(t_list));
	int	a = 1;
	int	b = 2;
	int	c = 3;
	int d = 8;

	void	*data1 = &a;
	void	*data2 = &b;
	void	*data3 = &c;
	void	*data4 = &d;

	llist = ft_create_elem(data1);
	llist->next = ft_create_elem(data2);
	llist->next->next = ft_create_elem(data3);

	printf("Original Array\n");
	print_array(llist);

	printf("After Inserting\n");
	ft_list_push_back(&llist, data4);
	print_array(llist);

	free(llist);
}
*/