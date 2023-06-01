

#include "../push_swap.h"

t_stack	*new_node(int *value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	list -> value = value;
	list -> next = NULL;
	return(node);
}
