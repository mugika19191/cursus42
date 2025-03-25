#include "headers.h"

int	quote_check(char *str)
{
	int		i;
	int		open;
	char	quotes;

	open = 0;
	quotes = ' ';
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			if (quotes == str[i] || quotes == ' ')
			{
				open = !open;
				quotes = str[i];
			}
		}
		i++;
	}
	return (open);
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
			if (!open)
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
