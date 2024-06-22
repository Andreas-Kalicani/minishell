/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:08:38 by stripet           #+#    #+#             */
/*   Updated: 2024/06/22 03:24:32 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex_bonus.h"
#include "../header/errors_bonus.h"
#include "../header/utils_bonus.h"

static char	*find_path_envp(char **envp)
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

static void	init(int argc, char **argv, char **envp, t_data *data)
{
	data->paths = find_path_envp(envp);
	if (!data->paths)
		msg(*data, path_err);
	data->input = open(argv[1], O_RDONLY);
	if (data->input < 0)
		msg(*data, open_err);
	data->output = open(argv[argc - 1], O_CREAT | O_WRONLY, S_IRWXU);
	if (data->output < 0)
		msg(*data, open_create_err);
	if (dup2(data->input, STDIN_FILENO) == -1)
		msg(*data, dup_err);
}

int	main(int argc, char**argv, char **envp)
{
	t_data	data;
	int		i;

	i = 2;
	ft_bzero(&data, sizeof(t_data));
	if (argc < 5)
		msg(data, badargs_err);
	init(argc, argv, envp, &data);
	while (i < argc - 2)
	{
		child_proccess(data, argv[i]);
		i++;
	}
	last_cmd(data, argv[i]);
	free(data.paths);
}
