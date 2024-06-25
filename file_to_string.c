#include "./cub3d.h"

char	*file_to_string(char *path)
{
	int		fd;
	char	buff[1024];
	char	*data;
	char	*tmp;
	int		ret;

	fd = x_open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	ret = read(fd, buff, sizeof(buff));
	if (ret < 0)
		return (NULL);
	buff[ret] = '\0';
	data = ft_strjoin(NULL, buff);
	while (ret == 1)
	{
		ret = read(fd, buff, sizeof(buff) - 1);
		buff[ret] = '\0';
		tmp = data;
		data = ft_strjoin(data, buff);
		free(tmp);
	}
	close(fd);
	return (data);
}