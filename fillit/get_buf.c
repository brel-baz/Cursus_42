/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_buf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 09:31:35 by jreszka           #+#    #+#             */
/*   Updated: 2017/01/12 19:44:38 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

char	*get_buf(char *file_name)
{
	char		*buf;
	int			ret;
	int			fd;

	buf = (char *)malloc(sizeof(char) * 1000);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		write(1, "error\n", 6);
		return (0);
	}
	ret = read(fd, buf, BUF_SIZE);
	if (ret == -1)
	{
		write(1, "error\n", 6);
		return (0);
	}
	buf[ret] = '\0';
	if (close(fd) == -1)
	{
		write(1, "error\n", 6);
		return (0);
	}
	return (buf);
}
