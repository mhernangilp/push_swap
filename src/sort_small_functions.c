

#include "../push_swap.h"

static int	get_biggest_num(t_stack *stack)
{
	int	i;

	i = -2147483648;
	while (stack != NULL)
	{
		if (*stack -> value > i)
			i = *stack -> value;
		stack = stack -> next;
	}
	return (i);
}

static int	get_smallest_num(t_stack *stack)
{
	int	i;

	i = 2147483647;
	while (stack != NULL)
	{
		if (*stack -> value < i)
			i = *stack -> value;
		stack = stack -> next;
	}
	return (i);
}
static void	sort_3(t_stack **a)
{
	int	biggest;

	biggest = get_biggest_num(*a);
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

static void	place_stack(t_stack **a, int value)
{
	t_stack	*end;

	if (value < get_smallest_num(*a) || value > get_biggest_num(*a))
		while (*(*a) -> value != get_smallest_num(*a))
			rotate(a, 'a');
	else
	{
		end = *a;
		while (end -> next != NULL)
			end = end -> next;
		while (!(*end -> value < value && value < *(*a) -> value))
		{
			rotate(a, 'a');
			end = *a;
			while (end -> next != NULL)
				end = end -> next;
		}
	}
}

static void	sort_5(t_stack **a, t_stack **b)
{
	push(b, a, 'b');
	push(b, a, 'b');
	sort_3(a);
	place_stack(a, *(*b) -> value);
	push(a, b, 'a');
	place_stack(a, *(*b) -> value);
	push(a, b, 'a');
	while (!is_sorted(*a))
		rotate(a, 'a');
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
