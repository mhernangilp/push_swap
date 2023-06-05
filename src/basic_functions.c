

#include "../push_swap.h"

t_stack	*new_node(char *value)
{
	t_stack	*node;
	int	*temp_value;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	temp_value = malloc(sizeof(int));
	if (!temp_value)
		return  (NULL);
	*temp_value = ft_atoi(value);
	node -> value = temp_value;
	node -> next = NULL;
	return(node);
}
