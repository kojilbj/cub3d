#include "./cub3d.h"

void	free_all(void **data)
{
	size_t	i;

	if (data == NULL)
		return ;
	i = 0;
	while (data[i] != NULL)
	{
		free(data[i]);
		i++;
	}
}
