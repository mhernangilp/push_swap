/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 20:03:04 by mhernang          #+#    #+#             */
/*   Updated: 2023/05/31 20:33:10 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	new_index(t_stack *stack, int value)
{
	int	*index;

	if (stack != NULL)
	{
		index = malloc(sizeof(int));
		if (!index)
			return ;
		*index = value;
		stack -> index = index;
	}
}

static void	assign_smallest(t_stack **aux, t_stack **smallest,
			int *smallest_num)
{
	if (*(*aux) -> value <= *smallest_num && (*aux) -> index == NULL)
	{
		*smallest_num = *(*aux) -> value;
		*smallest = *aux;
	}
	(*aux) = (*aux) -> next;
}

static void	convert_index_to_bin(t_stack **a)
{
	t_stack	*aux;

	aux = *a;
	while (aux != NULL)
	{
		set_arr_size(aux, get_biggest_num(*a, 1));
		set_arr(aux, *aux -> index);
		aux = aux -> next;
	}
}

static void	initialize_index(t_stack **a)
{
	int		i;
	int		finished;
	int		smallest_num;
	t_stack	*aux;
	t_stack	*smallest;

	i = 0;
	finished = 0;
	while (!finished)
	{
		smallest_num = 2147483647;
		smallest = NULL;
		aux = *a;
		while (aux != NULL)
			assign_smallest(&aux, &smallest, &smallest_num);
		if (smallest == NULL)
			finished = 1;
		new_index(smallest, i++);
	}
	convert_index_to_bin(a);
}

void	initialize_stacks(t_stack **a, t_stack **b, char **argv, int argc)
{
	int		i;
	t_stack	*temp_node;

	*b = NULL;
	i = argc - 1;
	temp_node = new_node(argv[i]);
	temp_node -> next = NULL;
	*a = temp_node;
	while (--i > 0)
	{
		temp_node = new_node(argv[i]);
		temp_node -> next = *a;
		temp_node -> index = NULL;
		temp_node -> arr = NULL;
		temp_node -> arr_size = NULL;
		*a = temp_node;
	}
	initialize_index(a);
}
