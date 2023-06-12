
#include "../push_swap.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	negative;

	negative = 1;
	res = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return (res * negative);
}

void	exit_program(t_stack **a, t_stack **b)
{
	t_stack	*aux;

	if (a)
		while (stack_len(*a) != 0)
		{
			aux = *a;
			*a = aux -> next;
			free(aux -> value);
			free(aux -> index);
			free(aux -> arr);
			free(aux -> arr_size);
		}
	if (b)
		while (stack_len(*b) != 0)
		{
			aux = *b;
			*b = aux -> next;
			free(aux -> value);
			free(aux -> index);
			free(aux -> arr);
			free(aux -> arr_size);
		}
	exit(0);
}

int	get_sort_pos(t_stack **a)
{
	t_stack	*aux;
	int	pos;

	aux = *a;
	pos = 0;
	while (*aux -> value != get_smallest_num(*a, 0))
	{
		aux = aux -> next;
		pos++;
	}
	return (pos);
}

int	get_stack_pos(t_stack **a, int value)
{
	t_stack	*aux;
	t_stack	*ant;
	int	pos;

	pos = 0;
	aux = *a;
	if (value < get_smallest_num(*a, 0) || value > get_biggest_num(*a, 0))
		while (*aux -> value != get_smallest_num(*a, 0) && aux != NULL)
		{
			aux = aux -> next;
			pos++;
		}
	else
	{
		ant = *a;
		while (ant -> next != NULL)
			ant = ant -> next;
		while (!(*ant -> value < value && value < *aux -> value))
		{
			ant = aux;
			aux = aux -> next;
			pos++;
		}
	}
	return (pos);
}
