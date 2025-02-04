/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <imugica-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:21:26 by imugica-          #+#    #+#             */
/*   Updated: 2025/02/04 18:22:36 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
# include <fcntl.h>

int	all_checks(char **args)
{
	if (access(args[4], R_OK) != -1)
		return (0);
	return (1);
		
}

int	check_infile(char *filename)
{
	int 	fd;
	
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);//return error;
	return (1);
}

int	check_outfie(char *filename)
{
	int 	fd;
	
	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd < 0)
		return (0);//return error;
	return (1);
}

int	main(int count, char **args, char **env)
{
	pid_t	pid;
	
	if (count != 5)
		return (0);
	if (check_infile(args[1]))
		return (0);
	if (check_otfile(args[4]))
		return (0);
	pid = fork();
	if (pid < 0)
		return (0);
	if (pid == 0)
		child();
	return (1);
}
