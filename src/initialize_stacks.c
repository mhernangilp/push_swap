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

void	initialize_stacks(t_stack **a, t_stack **b, char **argv, int argc)
{
	int		i;
	t_stack		*temp_node;

	*b = NULL;
	i = argc - 1;
	temp_node = new_node(argv[i]);
	temp_node -> next = NULL;
	*a = temp_node;
	while (--i > 0)
	{
		temp_node = new_node(argv[i]);
		temp_node -> next = *a;
		*a = temp_node;
	}
}
