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

int word_count(char *str, char a)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while(str[i])
	{
		while(str[i] == a && str[i])
			i++;
		if (!str[i] && !count)
			return (0);
		while (str[i] != a && str[i])
			i++;
		count++;
	}
	return (count);
}

int    get_word_len(char const *str, char a, int pos)
{
	int i;
	int count;
	int len;

	i = 0;
	count = 0;
	len = 0;
	while(str[i])
	{
		while(str[i] == a && str[i])
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

char **ft_split(char const *s, char c)
{
	char    **str;
	int     i;
	int     j;
	int     k;

	str = malloc(word_count((char *)s, c) + 1);
	i = 0;
	j = 0;
	k = 0;
	while (i < word_count((char *)s, c))
	{
		str[i] = malloc(get_word_len(s, c, i) + 1);
		while (j < get_word_len(s, c, i))
		{
			if (s[k] != c)
				str[i][j++] = s[k++];
			else
				k++;
		}
		str[i][j] = '\0';
		j = 0;
		i++;
	}
	str[i] = NULL;
	return (str);
}