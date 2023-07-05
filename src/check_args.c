/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:34:21 by mhernang          #+#    #+#             */
/*   Updated: 2023/07/05 14:06:11 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_num(char *str)
{
	int			i;
	long int	n;

	i = 0;
	if (is_sign(str[i]) && str[i + 1] != '\0')
		i++;
	while (str[i] && is_digit(str[i]))
		i++;
	if (str[i] != '\0' && !is_digit(str[i]))
		return (0);
	n = ft_atoi(str);
	if (n < -2147483648 || n > 2147483647)
		return (0);
	return (1);
}

static int	is_dup(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[j])
		{
			if (j != i && nbstr_cmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	is_zero(char *str)
{
	int	i;

	i = 0;
	if (is_sign(str[i]))
		i++;
	while (str[i] && str[i] == '0')
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

int	check_args(char **argv)
{
	int	i;
	int	zeros;

	i = -1;
	zeros = 0;
	while (argv[++i] != NULL)
	{
		if (!is_num(argv[i]))
			return (0);
		zeros += is_zero(argv[i]);
	}
	if (zeros > 1 || is_dup(argv))
		return (0);
	return (1);
}
