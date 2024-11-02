/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_head.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:40:29 by drabadan          #+#    #+#             */
/*   Updated: 2024/11/02 19:38:20 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_HEAD_H
# define GNL_HEAD_H

# ifndef BUFER_SIZE
#  define BUFER_SIZE 1
# endif

# include "./Libft/src/libft.h"
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);

#endif
