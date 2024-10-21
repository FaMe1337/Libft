/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:21:44 by famendes          #+#    #+#             */
/*   Updated: 2024/04/15 16:15:37 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	c1;
	int		i;

	c1 = (char)c;
	i = ft_strlen(s);
	if (!c)
		return ((char *)&s[i]);
	while (i >= 0)
	{
		if (s[i] == c1)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
