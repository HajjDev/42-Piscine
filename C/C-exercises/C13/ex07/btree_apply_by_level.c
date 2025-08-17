/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 13:43:31 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/17 16:02:08 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

/* ************************************************************************** */
/* Functions created in ex06 - Find the height of the tree */

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
/* Functions made in this exercise. */

int	g_level = 0;

void	btree_apply_at_level(t_btree *root, int depth, \
void (*applyf)(void *item, int current_level, int is_first_elem), int *is_first)
{
	if (root == 0)
		return ;
	if (depth == 0)
	{
		(*applyf)(root->item, g_level, *is_first);
		(*is_first) = 0;
	}
	else
	{
		btree_apply_at_level(root->left, depth - 1, applyf, is_first);
		btree_apply_at_level(root->right, depth - 1, applyf, is_first);
	}
	return ;
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void \
*item, int current_level, int is_first_elem))
{
	int	height;
	int	is_first;

	height = btree_level_count(root);
	while (g_level < height)
	{
		is_first = 1;
		btree_apply_at_level(root, g_level, applyf, &is_first);
		g_level++;
	}
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
   / \    / \
  8  19  27  40

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
              /    \
            7        15
          /  \      /   \
        3     9   14     18
       / \      \       / \
      1   4      10    17  20
*/

/*
#include <stdio.h>

void	print_node(void *data, int current_level, int is_first_elem)
{
	printf("Node value: %d\nLevel: %d\nIs First: %d\n\n", \
		*(int *)data, current_level, is_first_elem);
}


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

void	btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (root == 0)
		return ;
	btree_apply_infix(root->left, applyf);
	(*applyf)(root->item);
	btree_apply_infix(root->right, applyf);
	return ;
}

t_btree *create_tree1(void)
{
	t_btree *n21 = btree_create_node(make_int(21));
	t_btree *n13 = btree_create_node(make_int(13));
	t_btree *n34 = btree_create_node(make_int(34));
	t_btree *n8 = btree_create_node(make_int(8));
	t_btree *n19 = btree_create_node(make_int(19));
	t_btree *n27 = btree_create_node(make_int(27));
	t_btree *n40 = btree_create_node(make_int(40));

	n21->left = n13;
	n21->right = n34;
	n13->left = n8;
	n13->right = n19;
	n34->left = n27;
	n34->right = n40;

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
	t_btree *n7 = btree_create_node(make_int(7));
	t_btree *n15 = btree_create_node(make_int(15));
	t_btree *n3 = btree_create_node(make_int(3));
	t_btree *n9 = btree_create_node(make_int(9));
	t_btree *n14 = btree_create_node(make_int(14));
	t_btree *n18 = btree_create_node(make_int(18));
	t_btree *n1 = btree_create_node(make_int(1));
	t_btree *n4 = btree_create_node(make_int(4));
	t_btree *n10 = btree_create_node(make_int(10));
	t_btree *n17 = btree_create_node(make_int(17));
	t_btree *n20 = btree_create_node(make_int(20));

	n12->left = n7;
	n12->right = n15;
	n7->left = n3;
	n7->right = n9;
	n3->left = n1;
	n3->right = n4;
	n9->right = n10;
	n15->left = n14;
	n15->right = n18;
	n18->left = n17;
	n18->right = n20;

	return (n12);
}

int	main(void)
{
	t_btree	*tree1 = create_tree1();
	t_btree	*tree2 = create_tree2();
	t_btree	*tree3 = create_tree3();

	printf("Here is the result of applying the funct print_node on Tree 1:\n\n");
	btree_apply_by_level(tree1, &print_node);
	return (0);
}
*/