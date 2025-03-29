#include <stdio.h>

#include <stdlib.h>

#include <ctype.h>

#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (j < (int)len && big[j] && little[i])
	{
		if (big[j] == little[i])
			i++;
		else
		{
			j = j - i;
			i = 0;
		}
		j++;
	}
	if (len > 0 && !little[i])
		return ((char *)(big + j - i));
	else
		return (NULL);
}

int	len_checks(char const *s1, char const *s2, int *i, int *j)
{
	if (!s1 || !s2)
		return (0);
	*i = strlen(s1);
	*j = strlen(s2);
	return (1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	if (!len_checks(s1, s2, &i, &j))
		return (NULL);
	k = 0;
	str = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!str)
		return (NULL);
	while (k < i)
	{
		str[k] = s1[k];
		k++;
	}
	k = 0;
	while (k < j)
	{
		str[k + i] = s2[k];
		k++;
	}
	str[i + j] = '\0';
	return (str);
}
char	*find_var(char *var, char **env)
{
	int		i;
	char	*str;

	i = -1;
	while (env[++i])
	{
		str = ft_strnstr(env[i], var, strlen(var));
		if (str)
		{
			if (*(str + strlen(var)) == '=')
				return (str + strlen(var) + 1);
		}
	}
	return (NULL);
}
char	*get_var(char *str, char **env)
{
	int		i;
	char	*var;
	char	*value;

	i = 0;
	while (isalpha(str[++i]))
		;
	if (i == 1)
		return ("$");
	var = malloc(i + 1);
	strlcpy(var, str, i + 1);
	value = find_var(var + 1, env);
	free(var);
	if (value)
		return (value);
	return (" ");
}


int	get_var_len(char *str)
{
	int	i;

	i = 0;
	while (isalpha(str[++i]))
		;
	return (i);
}

char	*get_next_dolar(const char *string, char *var)
{
	char	quotes;
	int		open;

	quotes = ' ';
	open = 0;
	while (*string)
	{
		if ((*string == '\'' || *string == '\"'))
		{
			if (*string == quotes && open)
			{
				quotes = ' ';
				open = !open;
			}
			else if (!open)
			{
				quotes = *string;
				open = !open;
			}
		}
		if (*string == '$' && quotes != '\'' && (string - var) >= 0)
			return ((char *)string);
		string++;
	}
	return (0);
}


char	*replace_var(char *str, char **env)
{
	int		len;
	char	*var;
	char	*replace;
	char	*temp;
	char	*final;

	len = 0;
	var = get_next_dolar(str, str);
	final = str;
	/// while ((var - ft_strchr(final + len, '\'')) < 0)
	while (var)
	{
		replace = get_var(var, env);
		len = (var - final);
		temp = malloc(len + 1 + strlen(replace) + (strlen(final) - (len
						+ get_var_len(var))));
		strlcpy(temp, final, len + 1);
		strlcpy(temp + len, replace, strlen(replace) + 1);
		final = ft_strjoin(temp, final + len + get_var_len(var));
		free(temp);
		var = get_next_dolar(final, final + len + 1);
	}
	return (final);
}
/////////////////////////////////////////////////////
/////////////////
/////////////////////////////////////////////////////
int	quote_comp(char c, char quote)
{
	if (c == ' ')
		return (0);
	if (c == quote)
		return (0);
	return (1);
}

int	is_in_quotes(char const *str, int pos)
{
	int		i;
	int		open;
	char	c;

	i = 0;
	open = 0;
	c = ' ';
	while (str[i] && i != pos)
	{
		if (str[i] == c && open)
		{
			open = !open;
			c = ' ';
		}
		else if (str[i] == '\'' || str[i] == '"')
		{
			if (!open)
			{
				c = str[i];
				open = !open;
			}
		}
		i++;
	}
	return (open * quote_comp(c, str[i]));
}

static int word_count(char const *str, char a)
{
    int i = 0;
    int count = 0;
    int in_word = 0;

    while (str[i])
    {
        if (str[i] != a && !in_word && !is_in_quotes(str, i))
        {
            in_word = 1;
            count++;
        }
        else if (str[i] == a && !is_in_quotes(str, i))
        {
            in_word = 0;
        }
        i++;
    }
    return count;
}

static int	get_word_len(char const *str, char a, int pos)
{
	int	i;
	int	count;
	int	len;

	i = 0;
	count = 0;
	len = 0;
	while (str[i])
	{
		while (str[i] == a && str[i] && !is_in_quotes(str, i))
			i++;
		if (!str[i] && !count)
			return (0);
		while ((str[i] != a || is_in_quotes(str, i)) && str[i])
		{
			if (count == pos)
				len++;
			i++;
		}
		count++;
	}
	return (len);
}

static char *get_word(char *word, const char *s, char c, int *k)
{
    int i;

    i = 0;
    while ((s[*k] == c && s[*k] && !is_in_quotes(s, *k)) || ((s[*k] == '\"' || s[*k] == '\'') && !is_in_quotes(s, *k)))
		(*k)++;
    if (s[*k] == '\"' || s[*k] == '\'')
    {
        if (!is_in_quotes(s, *k))
            (*k)++;
    }
    if (is_in_quotes(s, *k))
    {
        while (is_in_quotes(s, *k)) 
            word[i++] = s[(*k)++];
    } 
    else 
    {
        while (s[*k] != c && s[*k] != '\0')
            word[i++] = s[(*k)++];
    }
    if ((s[*k] == '\'' || s[*k] == '\"') && is_in_quotes(s, *k))
        (*k)++;
    word[i] = '\0';
    return word;
}


static void	free_all(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
}

char	**shell_split(char const *s, char c)
{
	char **str;
	int i;
	int k;

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


int main(int c, char **args, char **env)
{
    char *str = "'re re' \"hello $ $PWD\" HHHH HHH";
    char **split;
    printf("%s\n\n",replace_var(str,env));
    split =shell_split(replace_var(str,env),' ');
    for(int i = 0;split[i] ;)
        printf("line= %s\n",split[i++]);

    return 0;
}
