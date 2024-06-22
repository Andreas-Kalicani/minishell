/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:13:10 by stripet           #+#    #+#             */
/*   Updated: 2024/06/22 03:23:23 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/utils_bonus.h"
#include "../header/errors_bonus.h"

static char	*findpath(t_data data, char *cmd)
{
	char	**paths;
	char	*path;
	int		i;

	if (!cmd)
		return (NULL);
	i = 0;
	cmd = ft_strjoin("/", cmd);
	paths = ft_split(data.paths, ':');
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

static void	get_path_and_args(t_data *data, char *cmd)
{
	data->args = ft_split(cmd, ' ');
	data->path = findpath(*data, data->args[0]);
	if (data->path == NULL)
	{
		if (data->args && *(data->args) != cmd)
			free(data->args);
		msg(*data, cmd_err);
	}
}

void	child_proccess(t_data data, char *cmd)
{
	int		fd[2];

	if (pipe(fd) == -1)
		msg(data, pipe_err);
	data.pid = fork();
	if (data.pid == -1)
		msg (data, fork_err);
	if (data.pid == 0)
	{
		get_path_and_args(&data, cmd);
		close (fd[0]);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			msg(data, dup_err);
		execve(data.path, data.args, NULL);
	}
	else
	{
		close (fd[1]);
		if (dup2(fd[0], STDIN_FILENO) == -1)
			msg(data, dup_err);
		waitpid(data.pid, NULL, 0);
	}
}

void	last_cmd(t_data data, char *cmd)
{
	data.pid = fork();
	if (data.pid == -1)
		msg(data, fork_err);
	else if (data.pid == 0)
	{
		get_path_and_args(&data, cmd);
		if (dup2(data.output, STDOUT_FILENO) == -1)
			msg(data, dup_err);
		execve(data.path, data.args, NULL);
	}
	else
	{
		waitpid(data.pid, NULL, 0);
	}
}
