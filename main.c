/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:38:52 by drabadan          #+#    #+#             */
/*   Updated: 2024/11/05 09:59:49 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_head.h"

int	find_n(char *line)
{
	int	i;

	i = 0;
	if (line == NULL)
		return (1);
	while (line[i])
	{
		if (line[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

void	get_clean(char **line, char *patteren)
{
	char	*new_line;
	int		i_pat;
	int		i_lin;

	i_pat = ft_strlen(patteren);
	i_lin = ft_strlen(*line);
	if (i_pat == i_lin)
	{
		free(*line);
		*line = NULL;
	}
	else
	{
		new_line = ft_strdup(*line + i_pat);
		free(*line);
		*line = new_line;
	}
}

char	*str_until_char(char *str, char c)
{
	char	*result;
	char	*pos;
	size_t	len;

	pos = ft_strchr(str, c);
	if (!pos)
		return (str);
	pos++;
	len = pos - str;
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	ft_strncpy(result, str, len);
	result[len] = '\0';
	return (result);
}

char	*no_bit_return(char **line, char *bufer)
{
	char	*result;

	result = *line;
	free(bufer);
	return (result);
}

char	*get_next_line(int fd)
{
	char		*bufer;
	int			chek_read;
	char		*tmp;
	char		*line;
	static char	last_read[BUFER_SIZE + 1] = "";
	int			i;

	line = NULL;
	line = ft_strdup(last_read);
	while (find_n(line) != 0)
	{
		bufer = malloc(BUFER_SIZE + 1);
		if (!bufer)
		{
			free(bufer);
			return (NULL);
		}
		chek_read = read(fd, bufer, BUFER_SIZE);
		if (chek_read <= 0)
		{
			free(bufer);
			last_read[0] = '\0';
			if (*line != '\0')
				return (line);
			else
			{
				free(line);
				return (NULL);
			}
		}
		bufer[chek_read] = '\0';
		if(find_n(line) == 0)
		{
			free(bufer);
			free(tmp);
			break ;
		}
		tmp = line;
		line = ft_strjoin(line, bufer);
		free(tmp);
		free(bufer);
	}
	if (find_n(line) == 0)
	{
		tmp = str_until_char(line, '\n');
		get_clean(&line, tmp);	
		i = 0;
		while(line[i])
		{
			last_read[i] = line[i];
			i++;
		}
		last_read[i] = '\0';
		free(line);
		return (tmp);
	}
	else
		return (NULL);
}

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
