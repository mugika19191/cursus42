#ifndef HEADERS_H
# define HEADERS_H

char	*find_var(char *var, char **env);
int		quote_check(char *str);
char	*get_next_dolar(const char *string, char *var);

#endif