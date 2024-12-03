/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:35:00 by imugica-          #+#    #+#             */
/*   Updated: 2024/11/30 13:35:00 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	word_count(char *str, char a)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (str[i])
	{
		if (str[i] != a && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (str[i] == a)
		{
			in_word = 0;
		}
		i++;
	}
	return (count);
}

int	get_word_len(char const *str, char a, int pos)
{
	int	i;
	int	count;
	int	len;

	i = 0;
	count = 0;
	len = 0;
	while (str[i])
	{
		while (str[i] == a && str[i])
			i++;
		if (!str[i] && !count)
			return (0);
		while (str[i] != a && str[i])
		{
			if (count == pos)
				len++;
			i++;
		}
		count++;
	}
	return (len);
}

char	*get_word(char *word, char const *s, char c, int *k)
{
	int	i;

	i = 0;
	while (s[*k] == c && s[*k])
		(*k)++;
	while (s[*k] != c && s[*k])
		word[i++] = s[(*k)++];
	word[i] = '\0';
	return (word);
}

void	free_all(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		k;

	if (!s)
		return (NULL);
	str = malloc(sizeof(char *) * (word_count((char *)s, c) + 1));
	if (!str)
		return (NULL);
	i = 0;
	k = 0;
	while (i < word_count((char *)s, c))
	{
		str[i] = malloc(get_word_len(s, c, i) + 1);
		if (!str[i])
		{
			free_all(str, i - 1);
			return (NULL);
		}
		str[i] = get_word(str[i], s, c, &k);
		i++;
	}
	str[i] = NULL;
	return (str);
}
