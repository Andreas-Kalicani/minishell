/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 02:45:37 by tienshi           #+#    #+#             */
/*   Updated: 2024/07/03 20:04:52 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/minishell.h"

#include <readline/readline.h>
#include <fcntl.h>

void	redirection(char *command)
{
	/*
	according to my research [n]<word word file descriptor will be redirected to n file descriptor.
	in the case that n is not specified, it goes to 0 for < and 1 for >.
	in the case n is a command, same case as above : considered as 0 for < and 1 for >, difference is, it runs in its own fork
	*/
}

int	parse(char *command)
{
	int		fd;
	char	*buffer;

	if (ft_strnstr(command, "<", ft_strlen(command))
		|| ft_strnstr(command, ">", ft_strlen(command)))
		redirection(command);
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
		if (ft_strlen(input) == 4 && ft_strncmp(input, "stop", 4) == 0)
		{
			free(input);
			break ;
		}
		ft_printf("input: %s\n", input);
		parse(input);
		free(input);
	}
}
