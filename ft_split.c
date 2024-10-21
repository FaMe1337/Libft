/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:34:34 by famendes          #+#    #+#             */
/*   Updated: 2024/10/14 17:42:26 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	safe_malloc(char **words_v, int position, size_t buffer)
{
	int	i;

	i = 0;
	words_v[position] = malloc(buffer);
	if (!words_v[position])
	{
		while (i < position)
			free(words_v[i++]);
		free(words_v);
		return (1);
	}
	return (0);
}

static int	fill(char **words_v, char const *s, char delimeter)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s && *s == delimeter)
			s++;
		while (*s && *s != delimeter)
		{
			len++;
			s++;
		}
		if (len)
		{
			if (safe_malloc(words_v, i, len + 1))
				return (1);
			ft_strlcpy(words_v[i], s - len, len + 1);
		}
		i++;
	}
	return (0);
}

static size_t	count_words(char const *s1, char delimeter)
{
	int		x;
	size_t	i;
	size_t	count;

	i = 0;
	x = 0;
	count = 0;
	while (s1[i])
	{
		if (s1[i] != delimeter && x == 0)
		{
			x = 1;
			count++;
		}
		else if (s1[i] == delimeter)
			x = 0;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**words_v;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	words_v = (char **)malloc(sizeof(char *) * (words + 1));
	if (!words_v)
		return (NULL);
	words_v[words] = NULL;
	if (fill(words_v, s, c))
		return (NULL);
	return (words_v);
}
