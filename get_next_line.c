/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:01:07 by famendes          #+#    #+#             */
/*   Updated: 2024/06/27 13:58:04 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	chrnline(char *s)
{
	while (*s != '\0' && *s != '\n')
		s++;
	if (*s == '\n')
		return (1);
	return (0);
}

static int	ft_strlen1(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		return (++i);
	return (i);
}

static void	ft_clean_buf(char *buf)
{
	int	i;
	int	l;
	int	j;

	i = ft_strlen1(buf) - 1;
	j = 0;
	l = 0;
	while (buf[l])
		l++;
	buf[i++] = '\0';
	while (i < l)
		buf[j++] = buf[i++];
	buf[j] = '\0';
}

static char	*ft_strjoin1(char *s1, char *s2)
{
	char	*s_res;
	int		i;
	int		j;

	j = 0;
	i = 0;
	s_res = malloc((ft_strlen1(s1) + ft_strlen1(s2) + 1));
	if (!s_res)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			s_res[i] = s1[i];
			i++;
		}
	}
	while (i < ft_strlen1(s1) + ft_strlen1(s2))
		s_res[i++] = s2[j++];
	s_res[i] = '\0';
	if (s1)
		free(s1);
	ft_clean_buf(s2);
	return (s_res);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*result;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	result = NULL;
	i = 1;
	while (i > 0)
	{
		if (!*buf)
		{
			i = read(fd, buf, BUFFER_SIZE);
			if (i == -1 || i == 0)
				return (result);
			buf[i] = '\0';
		}
		result = ft_strjoin1(result, buf);
		if (chrnline(result))
			break ;
	}
	return (result);
}
