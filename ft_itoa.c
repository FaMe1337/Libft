/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:27:32 by famendes          #+#    #+#             */
/*   Updated: 2024/06/27 15:06:43 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	long	nl;
	char	*str;

	nl = n;
	len = ft_len(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nl == 0)
		str[0] = '0';
	if (nl < 0)
	{
		str[0] = '-';
		nl *= -1;
	}
	while (nl)
	{
		str[--len] = (nl % 10) + 48;
		nl /= 10;
	}
	return (str);
}
