/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:42:53 by famendes          #+#    #+#             */
/*   Updated: 2024/06/27 15:09:10 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nl;

	nl = n;
	if (nl == 0)
	{
		write (fd, "0", 1);
		return ;
	}
	if (nl < 0)
	{
		write(fd, "-", 1);
		nl *= -1;
	}
	if (nl > 9)
		ft_putnbr_fd(nl / 10, fd);
	write(fd, &"0123456789"[nl % 10], 1);
}
