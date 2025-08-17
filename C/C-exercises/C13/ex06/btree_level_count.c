/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 12:39:38 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/17 13:01:52 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	max(int height1, int height2)
{
	if (height1 > height2)
		return (height1);
	return (height2);
}

int	btree_level_count(t_btree *root)
{
	if (root == 0)
		return (0);
	return (1 + max(btree_level_count(root->left), \
	btree_level_count(root->right)));
}

/* ************************************************************************** */
/*                                                                            */
/* ************************************************************************** */

/*
Here are the trees used in these examples:
Random value trees, they dont have to be bsts.

Tree 1:
       21
      /  \
    13    34

Tree 2:
               5
             /   \
           6       8
         /  \     /  \
        9    2   8    10
       / \        \
      1   4        7

Tree 3:
                12
                   \
                     15
                    /   \
                  14     18
                        / \
                       17  20
                             \
                              40
                                \
                                 49
                                  \
                                   10
*/

/*
#include <stdio.h>

t_btree	*btree_create_node(void *item)
{
	t_btree	*root;

	root = malloc(sizeof(t_btree));
	if (root == NULL)
		return (NULL);
	root->item = item;
	root->left = 0;
	root->right = 0;
	return (root);
}

void btree_free(t_btree *root)
{
	if (!root)
		return;
	btree_free(root->left);
	btree_free(root->right);
	free(root->item);
	free(root);
}

int *make_int(int value)
{
	int *ptr = malloc(sizeof(int));
	if (!ptr)
		return NULL;
	*ptr = value;
	return ptr;
}

t_btree *create_tree1(void)
{
	t_btree *n21 = btree_create_node(make_int(21));
	t_btree *n13 = btree_create_node(make_int(13));
	t_btree *n34 = btree_create_node(make_int(34));

	n21->left = n13;
	n21->right = n34;

	return (n21);
}


t_btree *create_tree2(void)
{
	t_btree *n5 = btree_create_node(make_int(5));
	t_btree *n6 = btree_create_node(make_int(6));
	t_btree *n8a = btree_create_node(make_int(8));
	t_btree *n9 = btree_create_node(make_int(9));
	t_btree *n2 = btree_create_node(make_int(2));
	t_btree *n8b = btree_create_node(make_int(8));
	t_btree *n10 = btree_create_node(make_int(10));
	t_btree *n1 = btree_create_node(make_int(1));
	t_btree *n4 = btree_create_node(make_int(4));
	t_btree *n7 = btree_create_node(make_int(7));

	n5->left = n6;
	n5->right = n8a;
	n6->left = n9;
	n6->right = n2;
	n9->left = n1;
	n9->right = n4;
	n8a->left = n8b;
	n8a->right = n10;
	n8b->right = n7;

	return (n5);
}


t_btree *create_tree3(void)
{
	t_btree *n12 = btree_create_node(make_int(12));
	t_btree *n15 = btree_create_node(make_int(15));
	t_btree *n14 = btree_create_node(make_int(14));
	t_btree *n18 = btree_create_node(make_int(18));
	t_btree *n17 = btree_create_node(make_int(17));
	t_btree *n20 = btree_create_node(make_int(20));
	t_btree *n40 = btree_create_node(make_int(40));
	t_btree *n49 = btree_create_node(make_int(49));
	t_btree *n10 = btree_create_node(make_int(10));
	

	n12->right = n15;
	n15->left = n14;
	n15->right = n18;
	n18->left = n17;
	n18->right = n20;
	n20->right = n40;
	n40->right = n49;
	n49->right = n10;

	return (n12);
}

int	main(void)
{
	t_btree	*tree1 = create_tree1();
	t_btree	*tree2 = create_tree2();
	t_btree	*tree3 = create_tree3();

	printf("The size of the largest branch in Tree 1 is: %d\n", \
	btree_level_count(tree1));
	printf("The size of the largest branch in Tree 2 is: %d\n", \
	btree_level_count(tree2));
	printf("The size of the largest branch in Tree 3 is: %d\n", \
	btree_level_count(tree3));

	btree_free(tree1);
	btree_free(tree2);
	btree_free(tree3);
	return (0);
}
*/