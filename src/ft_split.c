/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:03:45 by mhernang          #+#    #+#             */
/*   Updated: 2023/06/28 14:06:37 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_delcount(char const *s, char c)
{
	int	i;
	int	count;

	if (s[0] == 0)
		return (0);
	i = 0;
	count = 0;
	if (s[i] == c)
		count--;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i + 1] == c)
				i++;
			if (s[i + 1])
				count++;
		}
		i++;
	}
	count++;
	return (count);
}

static void	ft_loop(char const *s, char *c, int *csize, char **p)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	while (j < *csize)
	{
		count = 0;
		while (s[i] == *c)
			i++;
		while (s[i] != *c && s[i])
		{
			p[j][count] = s[i];
			i++;
			count++;
		}
		p[j][count] = '\0';
		j++;
	}
}

static void	ft_fillco(char const *s, char c, int csize, char **p)
{
	int	i;
	int	count;
	int	j;

	i = 0;
	j = 0;
	while (j < csize)
	{
		count = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			count++;
			i++;
		}
		p[j] = malloc(count * sizeof(char) + 1);
		j++;
	}
	ft_loop(s, &c, &csize, p);
}

int	ft_split(char const *s, char c, char **values)
{
	int	cosize;

	cosize = ft_delcount(s, c);
	ft_fillco(s, c, cosize, values);
	return (cosize);
}
