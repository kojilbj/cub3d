#include "cub3d.h"

void	err_terminate(char *errmsg)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(errmsg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	map_validate(t_node **map)
{
	int	x;
	int	y;
	int	fg;

	x = 0;
	y = 0;
	fg = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x].type != '\0')
		{
			if (map[y][x].type == 'P')
			{
				if (fg == 1)
					return (false);
				fg = 1;
			}
			x++;
		}
		y++;
	}
	return (fg);
}
/*
static void	map_letter_validate_util(t_vars vars, char c, int *pfg)
{
	if (!(c == '1' || c == '0' || c == 'P'
			|| c == '\n'))
		terminate_program(vars, "Error\nMap contains invalid letter", 22);
	if (c == 'P')
		(*pfg)++;
}

void	map_letter_validate(t_vars vars)
{
	int		x;
	int		y;
	int		pfg;
	char	c;

	x = 0;
	y = 0;
	pfg = 0;
	while (vars.map_info.map[y])
	{
		x = 0;
		while (vars.map_info.map[y][x])
		{
			c = vars.map_info.map[y][x];
			map_letter_validate_util(vars, c, &pfg);
			x++;
		}
		y++;
	}
	if (pfg != 1)
		terminate_program(vars, "Error\nMap must has only one Player", 22);
}
*/
int	validate(t_info info)
{
	if (info.tex_no == NULL)
		err_terminate("North texture");
	if (info.tex_so == NULL)
		err_terminate("South texture");
	if (info.tex_we == NULL)
		err_terminate("West texture");
	if (info.tex_ea == NULL)
		err_terminate("East texture");
	if (info.floor_rgb == NULL)
		err_terminate("Floor_RGB");
	if (info.ceiling_rgb == NULL)
		err_terminate("Ceiling_RGB");
	if (map_validate(info.map) == false)
		err_terminate("Player");
	//map_letter_validate();
}
