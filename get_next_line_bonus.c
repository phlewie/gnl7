#include "get_next_line_bonus.h"

static char	*append_to_buffer(char *buffer, char *buf, int n)
{
	char	*tmp;
	buf[n] = '\0';
	tmp = ft_strjoin(buffer, buf);
	if (!tmp)
		return (free(buffer), NULL);
	free(buffer);
	return (tmp);
}

static char	*read_to_buffer(int fd, char *buffer)
{
	char	*read_buf;
	int	read_value;

	if(!(read_buf = malloc(BUFFER_SIZE + 1)))
		return (free(buffer), NULL);
	read_value = 0;
	while (!(ft_strchr(buffer, '\n')))
	{
		read_value = read(fd, read_buf, BUFFER_SIZE);
		if (read_value <= 0)
			break ;
		buffer = append_to_buffer(buffer, read_buf, read_value);
		if (!buffer)
			return (free(read_buf), NULL);
	}
	free(read_buf);
	if (read_value < 0)
		return (free(buffer), NULL);
	return (buffer);
}

static char	*extract_line(char *buffer)
{
	char	*newline;
	char	*line;
	size_t	len;

	if (!buffer || buffer[0] == '\0')
		return (NULL);
	newline = ft_strchr(buffer, '\n');
	if (!newline)
		len = ft_strlen(buffer);
	else
		len = newline - buffer + 1;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	line = ft_memcpy(line, buffer, len);
	line[len] = '\0';
	return (line);
}

static char	*update_buffer(char *buffer)
{
	char	*new_buffer;
	char	*newline;
	size_t	len;

	newline = ft_strchr(buffer, '\n');
	if (!newline || *(newline + 1) == '\0')
		return (free(buffer), NULL);
	len = ft_strlen(newline + 1);
	new_buffer = malloc(len + 1);
	if (!new_buffer)
		return (free(buffer), NULL);
	ft_memcpy(new_buffer, newline + 1, len);
	new_buffer[len] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = read_to_buffer(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = extract_line(buffer[fd]);
	if(!line)
		return (free(buffer[fd]), buffer[fd] = NULL, NULL);
	buffer[fd] = update_buffer(buffer[fd]);
	return (line);
}	
