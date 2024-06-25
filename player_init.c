#include "./cub3d.h"

static int	is_player(char c)
{
	if (c != '0' && c != '1' && c != ' ')
		return (true);
	else
		return (false);
}

static int	dir_init(t_player *player, char c)
{
	if (player->dir_x != 0 && player->dir_y != 0)
		return (1);
	if (c == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
	}
	if (c == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
	}
	if (c == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
	}
	if (c == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
	}
	return (0);
}

int	player_init(t_info *info, char **filedata)
{
	size_t	x;
	size_t	y;
	int	ret;
	char	**map;

	map = &filedata[6];
	x = 0;
	y = 0;
	ret = 0;
	while (map[y] != NULL)
	{
		x = 0;
		printf("%c", map[y][x]);
		while (map[y][x] != '\0')
		{
			if (is_player(map[y][x]) == true)
				ret |= dir_init(&(info->player), map[y][x]);
			if (is_player(map[y][x]) == true)
			{
				info->player.pos_x = x;
				info->player.pos_y = y;
				map[y][x] = 'P';
			}
			x++;
		}
		y++;
	}
	return (ret);
}