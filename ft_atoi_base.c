/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:51:34 by famendes          #+#    #+#             */
/*   Updated: 2024/06/27 13:51:35 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int isvalid(char c)
{   
    char *str = "0123456789abcdef";
    char *str1 = "0123456789ABCDEF";
    
    while (*str)
    {
        if(*str == c)
            return (1);
        str++;
    }
    while(*str1)
    {
        if(*str1 == c)
            return (1);
        *str1++;
    }
    return 0;
}

int atoi_base(char *str, int base)
{
    int i = 0;
    int sign = 1;
    int result = 0;
    
    while(str[i] < 32)
        i++;
    if (str[i] == '-')
    {
        sign *= -1;
        i++;
    }
    while (isvalid(str[i]))
    {
        result *= base; 
        if (str[i] >= '0' && str[i] <= '9')
            result += str[i] - '0';
        else if (str[i] >= 'A' && str[i] <= 'F')
            result += str[i] - 55;
        else if (str[i] >= 'a' && str[i] <= 'f')
            result += str[i] - 87;
        i++;
    }
    return (result*sign);
}