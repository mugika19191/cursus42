/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <imugica-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:15:02 by imugica-          #+#    #+#             */
/*   Updated: 2024/12/03 13:39:39 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*mylist;

	mylist = malloc(sizeof(struct s_list));
	if (!mylist)
		return (NULL);
	mylist -> next = NULL;
	mylist -> content = content;
	return (mylist);
}
