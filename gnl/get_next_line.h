/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:59:56 by brel-baz          #+#    #+#             */
/*   Updated: 2017/03/01 16:42:48 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include "libft/libft.h"

# define BUFF_SIZE 42

int					get_next_line(const int fd, char **line);

typedef struct		s_line
{
	int				fd;
	char			*tmp;
	struct s_line	*next;
}					t_line;

#endif
