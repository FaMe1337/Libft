/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:53:03 by famendes          #+#    #+#             */
/*   Updated: 2024/04/18 17:48:54 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char*s, int c)
{
	char	c1;
	int		i;
	int		end;

	c1 = (char) c;
	i = 0;
	end = ft_strlen(s);
	if (!c)
		return ((char *)s + end);
	while (s[i])
	{
		if (s[i] == c1)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
