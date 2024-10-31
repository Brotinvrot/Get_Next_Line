/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:38:52 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/30 21:18:07 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_head.h"

#ifndef BUFER_SIZE
# define BUFER_SIZE 10
#endif

int	find_n(char *line)
{
	int	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (0);// 0 значит совподение найдено
		i++;
	}
	return (1);// 1 значит совподения не найдено
}

char	*get_next_line(int fd)
{
	char	*bufer;
	int	chek_read;

	if (BUFER_SIZE < 1 || fd < 0)
		return (NULL);
	bufer = malloc(BUFER_SIZE + 1);
	if (!bufer)
		return (NULL);
	chek_read =	read(fd, bufer, BUFER_SIZE);
	if (chek_read <= 0)
	{
		free(bufer);
		return (NULL);
	}
	bufer[chek_read] = '\0';
	if (find_n(bufer) == 1)
		printf("НЕ НАШЁЛ\n");
	else
		printf("НАШЁЛ\n");
	return (bufer);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc != 2)
	{
		write (2, "Usage: ./a.out <filename>\n", 26);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error: could not open file\n", 27);
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		write (1, line, strlen(line));
		write (1, "\n", 1);
		free(line);
	}
	close (fd);
	return (0);
}
