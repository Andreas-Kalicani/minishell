/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 02:45:37 by tienshi           #+#    #+#             */
/*   Updated: 2024/06/26 06:18:57 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/minishell.h"

#include <readline/readline.h>
#include <fcntl.h>

int	parse(char *command)
{
	int		fd;
	int		p[2];
	char	*buffer;

	//shell doesnt care a bunch about white spaces
	pipe(p);
	if (ft_strnstr(command, "<", ft_strlen(command)))//very basic code, finds < in command line and redirects fds
	{
		buffer = ft_strnstr(command, "<", ft_strlen(command)) + 2;//hard coded to have one < one whitespace
		ft_printf("Received strig :%s\n", buffer);
		fd = open(buffer, O_RDONLY);
		printf("my fd is %i\n", fd);
		if (fd < 0)
			return (msg(BAD_OPEN));
		ft_printf("i reached this\n");
		dup2(p[0], fd),
		dup2(p[1], STDIN_FILENO);
		ft_printf("I shouldnt see this\n");
	}
	else if (ft_strnstr(command, ">", ft_strlen(command)))//exactly the same idea
	{
		fd = open(ft_strnstr(command, ">", ft_strlen(command)), O_WRONLY);
		if (fd < 0)
			return (msg(BAD_OPEN));
		dup2(fd, STDOUT_FILENO);
		ft_printf("reached end of > snippet");
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char	*input;

	if (argc != 1 || argv[1])//this just uses argc and argv so Werror wont complain
		return (msg(BAD_ARGS));

	(void)envp;

	while (1)//for now this is an infinite loop that displays a prompt and reads input (read_line acts as a printf + gnl on stdin)
	//it also checks if the input is "stop" and if it is it breaks the loop
	// after receiving line it will parse it and check for validity
	//it will then do what it has to do
	{
		input = readline("Minishell :\n");
		if (ft_strncmp(input, "stop", ft_strlen(input)) == 0)
		{
			free(input);
			break ;
		}
		ft_printf("input: %s\n", input);
		parse(input);
		free(input);
	}
}
