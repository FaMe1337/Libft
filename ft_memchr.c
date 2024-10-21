/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:50:47 by famendes          #+#    #+#             */
/*   Updated: 2024/04/22 17:12:03 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void*s, int c, size_t n)
{
	unsigned char	c1;
	unsigned char	*s1;
	size_t			i;

	c1 = c;
	s1 = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (s1[i] == c1)
			return ((void *) &s1[i]);
		i++;
	}
	return (NULL);
}
