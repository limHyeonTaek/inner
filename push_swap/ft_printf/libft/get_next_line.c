/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 20:25:52 by hylim             #+#    #+#             */
/*   Updated: 2024/10/31 14:36:30 by hylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read_buf(int fd, char *tmp)
{
	char	*buf;
	int		re_read;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	re_read = 1;
	while (!gnl_strchr(tmp, '\n') && re_read != 0)
	{
		re_read = read(fd, buf, BUFFER_SIZE);
		if (re_read == -1)
			return (free(buf), NULL);
		buf[re_read] = '\0';
		tmp = gnl_strjoin(tmp, buf);
	}
	return (free(buf), tmp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = ft_read_buf(fd, tmp);
	if (!tmp)
		return (NULL);
	line = ft_dup_upto_nl(tmp);
	tmp = ft_dup_after_nl(tmp);
	if (tmp)
	{
		free(tmp);
		tmp = NULL;
	}
	return (line);
}

/* #include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*line;
	int		i;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	printf("fd = [%d]\n", fd);
	i = 1;
	while (i <= 30)
	{
		line = get_next_line(fd);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
} */