/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbikandi <nbikandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:34:04 by nbikandi          #+#    #+#             */
/*   Updated: 2022/07/26 17:17:37 by nbikandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	(void)argc; //Casting argc to quiet the compiler's warnings.
	fd = open(argv[1], O_RDONLY); //Open the file given as an argument al program launch
	line = ""; //Initialize this variable to be able to use it in the following loop
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line); //We're omitting any \n in this printf because get_next_line is supposed to include the \n for each line
	}
	fd = close(fd);
	return (0);
}
/*
int	main(void)
{
	int	file;

	file = open("1.txt", O_RDWR);
	printf("file: %s\n", get_next_line(file));
	printf("file: %s\n", get_next_line(file));
	printf("file: %s\n", get_next_line(file));
}
*/
