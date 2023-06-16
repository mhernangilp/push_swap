/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:14:17 by mhernang          #+#    #+#             */
/*   Updated: 2023/06/14 17:00:11 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static char	**assign_values(char **argv, int *argc)
{
	char	**values;

	if (*argc > 2)
		values = argv;
	else
		values = ft_split(argv[1], ' ', argc);
	return (values);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**values;

	if (argc < 2)
		exit_program(NULL, NULL);
	values = assign_values(argv, &argc);
	if (!check_args(values, argc))
	{
		write(1, "Error\n", 6);
		exit_program(NULL, NULL);
	}
	initialize_stacks(&a, &b, values, argc);
	if (!is_sorted(a))
	{
		if (stack_len(a) < 6)
			sort_small(&a, &b);
		else
			sort_big(&a, &b);
	}
	exit_program(&a, &b);
	return (0);
}
