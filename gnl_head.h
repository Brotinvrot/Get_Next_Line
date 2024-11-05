/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_head.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:40:29 by drabadan          #+#    #+#             */
/*   Updated: 2024/11/05 16:13:48 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_HEAD_H
# define GNL_HEAD_H

# ifndef BUFER_SIZE
#  define BUFER_SIZE 42
# endif

# include "./Libft/src/libft.h"
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*join_and_free(char *line, char *bufer);
char	*str_until_char(char *str, char c);
char	*read_and_update(int fd, char *line, int *bit);
void	get_clean(char **line, char *patteren);
int		find_n(char *line);

#endif
