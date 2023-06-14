/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:43:14 by mhernang          #+#    #+#             */
/*   Updated: 2023/06/14 17:07:26 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_big(t_stack **a, t_stack **b)
{
	int	i;
	int	j;

	j = *(*a)-> arr_size;
	while (--j >= 0)
	{
		i = 0;
		while (i < stack_len(*a))
		{
			if ((*a)-> arr[j] == 0)
				push(b, a, 'b');
			else
			{
				rotate(a, 'a');
				i++;
			}
		}
		while (stack_len(*b) != 0)
			push(a, b, 'a');
	}
}
