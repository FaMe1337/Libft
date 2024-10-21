/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:58:12 by famendes          #+#    #+#             */
/*   Updated: 2024/10/10 12:07:28 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char*big, const char*little, size_t len)
{
	size_t	i;

	i = 0;
	if (!little || little == big)
		return ((char *)big);
	if (!big && !len)
		return (NULL);
	while (big[i] && i <= len)
	{
		if (ft_strncmp(big + i, little, ft_strlen(little)) == 0)
		{
			if (len - i < ft_strlen(little))
				break ;
			return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
