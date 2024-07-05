/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 02:45:37 by tienshi           #+#    #+#             */
/*   Updated: 2024/07/05 18:51:44 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/minishell.h"

#include <readline/readline.h>
#include <fcntl.h>

char	*find_path_envp(char **envp)
{
	if (!envp)
	{
		ft_printf("Error envp is empty\n");
		exit (-9999999);
	}
	while (*envp)
	{
		if (ft_strlen(*envp) < 4)
			envp++;
		if (ft_strncmp(*envp, "PATH", 4) == 0)
			return (ft_strtrim(*envp, "PATH="));
		else
			envp++;
	}
	return (NULL);
}

char	*findpath(t_data data, char *cmd)
{
	char	**paths;
	char	*path;
	int		i;

	if (!cmd)
		return (NULL);
	i = 0;
	cmd = ft_strjoin("/", cmd);
	paths = ft_split(data.path, ':');
	while (paths[i])
	{
		path = ft_strjoin(paths[i], cmd);
		if (access(path, X_OK) == 0)
		{
			free(cmd);
			ft_split_free(paths);
			return (path);
		}
		free(path);
		i++;
	}
	free(cmd);
	ft_split_free(paths);
	return (NULL);
}

void	outred(t_data *data)
{
	char	**buffer;
	char	**args;
	int		pid;
	int		fd;

	buffer = ft_split(data->input, '>');
	fd = open(buffer[1], O_RDWR);
	if (fd == -1)
		return ;
	//do some parsing on the buffer[0] for now i assume it's just a command or a number
	if (ft_isint(buffer[0]))
		dup2(ft_atoi(buffer[0]), fd);
	else
	{
		pid = fork();
		if (pid != 0)
			waitpid(pid, NULL, 0);
		else
		{
			args = ft_split(buffer[0], ' ');
			dup2(STDOUT_FILENO, fd);
			close(fd);
			execve(findpath(*data, args[0]), args, NULL);
			perror("Error with execution :");
		}
	}
	dup2(data->fd_out, STDOUT_FILENO);
}

void	inred(t_data *data)
{
	/*
	according to my research [n]<word word file descriptor will be redirected to n file descriptor.
	in the case that n is not specified, it goes to 0 for < and 1 for >.
	in the case n is a command, same case as above : considered as 0 for < and 1 for >, difference is, it runs in its own fork
	*/
	char	**buffer;
	char	**args;
	int		pid;
	int		fd;

	buffer = ft_split(data->input, '<');
	fd = open(buffer[1], O_RDONLY);
	if (fd == -1)
		return ;
	//do some parsing on the buffer[0] for now i assume it's just a command or a number
	if (ft_isint(buffer[0]))
		dup2(fd, ft_atoi(buffer[0]));
	else
	{
		pid = fork();
		if (pid != 0)
		{
			close (fd);
			waitpid(pid, NULL, 0);
		}
		else
		{
			
			int	i = -1;
			
			args = ft_split(buffer[0], ' ');
			dup2(fd, STDIN_FILENO);
			close(fd);
			while (args[++i])
				printf("arg %i : %s\n", i,  args[i]);
			execve(findpath(*data, args[0]), args, NULL);
			perror("Error with execution :");
		}
	}
	dup2(data->fd_in, STDIN_FILENO);
}

int	parse(t_data *data)
{
	if (ft_strnstr(data->input, "<", ft_strlen(data->input)))
		inred(data);
	else if (ft_strnstr(data->input, ">", ft_strlen(data->input)))
		outred(data);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc != 1 || argv[1])//this just uses argc, argv and envp so Werror wont complain
		return (msg(BAD_ARGS));


	data.path = find_path_envp(envp);
	data.fd_in = dup(STDIN_FILENO);
	data.fd_out = dup(STDOUT_FILENO);
	while (1)//for now this is an infinite loop that displays a prompt and reads input (read_line acts as a printf + gnl on stdin)
	//it also checks if the input is "stop" and if it is it breaks the loop
	// after receiving line it will parse it and check for validity
	//it will then do what it has to do
	{
		data.input = readline("Minishell :\n");
		if (ft_strlen(data.input) == 4 && ft_strncmp(data.input, "stop", 4) == 0)
		{
			free(data.input);
			break ;
		}
		ft_printf("input: %s\n", data.input);
		parse(&data);
		free(data.input);
	}
}
