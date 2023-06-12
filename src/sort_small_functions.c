

#include "../push_swap.h"

static void	sort_3(t_stack **a)
{
	int	biggest;

	biggest = get_biggest_num(*a, 0);
	if (*(*a) -> value == biggest)
	{
		if (*(*a) -> next -> value > *(*a) -> next -> next -> value)
		{
			swap(a, 'a');
			reverse(a, 'a');
		}
		else
			rotate(a, 'a');
	}
	else if (*(*a) -> next -> next -> value == biggest)
		swap(a, 'a');
	else
	{
		if (*(*a) -> value < *(*a) -> next -> next -> value)
		{
			swap(a, 'a');
			rotate(a, 'a');
		}
		else
			reverse(a, 'a');
	}
}

static int	get_stack_pos(t_stack **a, int value)
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

static void	place_stack(t_stack **a, int value)
{
	t_stack	*end;

	if (value < get_smallest_num(*a, 0) || value > get_biggest_num(*a, 0))
		while (*(*a) -> value != get_smallest_num(*a, 0))
		{
			if (get_stack_pos(a, value) < stack_len(*a) / 2) 
				rotate(a, 'a');
			else
				reverse(a, 'a');
		}
	else
	{
		end = *a;
		while (end -> next != NULL)
			end = end -> next;
		while (!(*end -> value < value && value < *(*a) -> value))
		{
			if (get_stack_pos(a, value) < stack_len(*a) / 2)
				rotate(a, 'a');
			else
				reverse(a, 'a');
			end = *a;
			while (end -> next != NULL)
				end = end -> next;
		}
	}
}

static int	get_sort_pos(t_stack **a)
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

static void	sort_5(t_stack **a, t_stack **b)
{
	while (stack_len(*a) > 3)
		push(b, a, 'b');
	if (!is_sorted(*a))
		sort_3(a);
	while (stack_len(*b) > 0)
	{
		place_stack(a, *(*b) -> value);
		push(a, b, 'a');
	}
	while (!is_sorted(*a))
	{
		if (get_sort_pos(a) < stack_len(*a) / 2)
			rotate(a, 'a');
		else
			reverse(a, 'a');
	}
}

void	sort_small(t_stack **a, t_stack **b)
{
	if (stack_len(*a) == 2)
		swap(a, 'a');
	else if (stack_len(*a) == 3)
		sort_3(a);
	else
		sort_5(a, b);
}
