/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multi_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:25:31 by mbudkevi          #+#    #+#             */
/*   Updated: 2025/05/30 15:31:26 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_array(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
	return (0);
}

static int	is_delim(char c, char *delim)
{
	while (*delim)
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}

static int	ft_count_words(char const *str, char *delim)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (is_delim(str[i], delim))
			i++;
		else
		{
			count++;
			while (str[i] && !is_delim(str[i], delim))
				i++;
		}
	}
	return (count);
}

static char	*ft_putword(char const *s, int start, int len)
{
	char	*word;
	int		j;

	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (j < len)
	{
		word[j] = s[start + j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

static char	**ft_split_words(char const *s, char *delim, char **s2, int num_words)
{
	int	i;
	int	word;
	int	start;
	int	word_len;

	i = 0;
	word = 0;
	while (word < num_words)
	{
		while (s[i] && is_delim(s[i], delim))
			i++;
		start = i;
		while (s[i] && !is_delim(s[i], delim))
			i++;
		word_len = i - start;
		s2[word] = ft_putword(s, start, word_len);
		if (!s2[word])
			return (free_array(s2, word));
		word++;
	}
	s2[word] = 0;
	return (s2);
}

char	**ft_multi_split(char const *s, char *delim)
{
	char	**s2;
	int		num_words;

	if (!s || !delim)
		return (NULL);
	num_words = ft_count_words(s, delim);
	s2 = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!s2)
		return (NULL);
	s2 = ft_split_words(s, delim, s2, num_words);
	return (s2);
}