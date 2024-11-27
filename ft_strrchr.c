/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:26:37 by imugica-          #+#    #+#             */
/*   Updated: 2024/11/25 14:28:17 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *string, int c)
{
	int		i;
	char	*a;

	i = ft_strlen(string);
	a = (char *)string;
	while (i--)
	{
		if (string[i] == c)
			return (a + i);
	}
	return (NULL);
}
