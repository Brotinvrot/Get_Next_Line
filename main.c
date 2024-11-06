/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:38:52 by drabadan          #+#    #+#             */
/*   Updated: 2024/11/06 11:15:59 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./Libft/src/libft.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	fd = 0;
	line = NULL;
	if (argc != 2)
	{
		write(2, "Usage: ./a.out <filename>\n", 26);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error: could not open file\n", 27);
		return (1);
	}
// Печать циклом вывод всего файла
	while ((line = get_next_line(fd)) != NULL)
	{
		write(1, line, ft_strlen(line));
		free(line);
	}
// Вывод одной линии
	// line = get_next_line(fd);
	// write(1, line, ft_strlen(line));
	// free(line);
	close(fd);
	return (0);
}
