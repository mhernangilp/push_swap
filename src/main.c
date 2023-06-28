/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:14:17 by mhernang          #+#    #+#             */
/*   Updated: 2023/06/28 16:50:20 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static char	**assign_values(char **argv, int *argc)
{
	char	**values;
	int		count;
	int		i;
	int		filled;

	i = 0;
	count = 0;
	while (++i < *argc)
		count += ft_delcount(argv[i], ' ');
	values = malloc((count + 1) * sizeof(char *));
	values[count] = NULL;
	filled = 0;
	i = 0;
	while (++i < *argc)
		filled += ft_split(argv[i], ' ', values + filled);
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
	if (!check_args(values))
	{
		write(1, "Error\n", 6);
		exit_program(NULL, NULL);
	}
	initialize_stacks(&a, &b, values);
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
