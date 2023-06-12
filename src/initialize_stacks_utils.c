#include "../push_swap.h"

void	set_arr(t_stack *stack, int index)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * *stack -> arr_size);
	i = *stack -> arr_size - 1;
	while (index != 0)
	{
		arr[i] = index % 2;
		index /= 2;
		i--;
	}
	while (i >= 0)
	{
		arr[i] = 0;
		i--;
	}
	stack -> arr = arr;
}

void	set_arr_size(t_stack *stack, int index)
{
	int	*i;

	i = malloc(sizeof(int));
	*i = 1;
	while (index > 1)
	{
		index /= 2;
		(*i)++;
	}
	stack -> arr_size = i;
}
