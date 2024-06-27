#include "cub3d.h"

void	err_terminate(char *errmsg)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(errmsg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

// static void	map_letter_validate_util(t_vars vars, char c, int *pfg)
// {
// 	if (!(c == '1' || c == '0' || c == 'P'
// 			|| c == '\n'))
// 		terminate_program(vars, "Error\nMap contains invalid letter", 22);
// 	if (c == 'P')
// 		(*pfg)++;
// }

// void	map_letter_validate(t_vars vars)
// {
// 	int		x;
// 	int		y;
// 	int		pfg;
// 	char	c;

// 	x = 0;
// 	y = 0;
// 	pfg = 0;
// 	while (vars.map_info.map[y])
// 	{
// 		x = 0;
// 		while (vars.map_info.map[y][x])
// 		{
// 			c = vars.map_info.map[y][x];
// 			map_letter_validate_util(vars, c, &pfg);
// 			x++;
// 		}
// 		y++;
// 	}
// 	if (pfg != 1)
// 		terminate_program(vars, "Error\nMap must has only one Player", 22);
// }

//the third arg of ft_strncmp for the purpose of validating hidden file
int	file_name_validate(char *arg)
{
	char	*ptr;

	if (ft_strlen(arg) < 5)
		return (1);
	ptr = ft_strrchr(arg, '.');
	if (ft_strncmp(ptr, ".cub\0", 5))
		return (1);
	return (0);
}

int	validate(t_info info)
{
	// if (info.floor_rgb == NULL)
	// 	err_terminate("Floor_RGB\n");
	// if (info.ceiling_rgb == NULL)
	// 	err_terminate("Ceiling_RGB\b");
	// if (map_validate(info.map) == false)
	// 	err_terminate("Player\n");
	//map_letter_validate();
}
