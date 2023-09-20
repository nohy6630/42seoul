/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:52:12 by yenoh             #+#    #+#             */
/*   Updated: 2023/09/20 22:50:29 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *m)
{
	write(2, m, ft_strlen(m));
	write(2, "\n", 1);
	exit(1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	if (len == 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < len - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	**get_paths(char **envp)
{
	char	*path;

	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	path = *envp + 5;
	return (ft_split(path, ':'));
}

char	*get_cmd_path(char **path, char *cmd)
{
	int		i;
	char	*slash_cmd;
	char	*ret;

	i = 0;
	if (access(cmd, X_OK) != -1)
		return (cmd);
	slash_cmd = ft_strjoin("/", cmd);
	while (path[i])
	{
		ret = ft_strjoin(path[i++], slash_cmd);
		if (access(ret, X_OK) != -1)
		{
			free(slash_cmd);
			return (ret);
		}
		free(ret);
	}
	free(slash_cmd);
	return (NULL);
}

void	execute_cmd(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	**cmd_arg;
	char	*cmd_path;

	i = 0;
	paths = get_paths(envp);
	cmd_arg = ft_split(cmd, ' ');
	cmd_path = get_cmd_path(paths, cmd_arg[0]);
	if (!cmd_path)
	{
		while (paths[i])
			free(paths[i++]);
		free(paths);
		i = 0;
		while (cmd_arg[i])
			free(cmd_arg[i++]);
		free(cmd_arg);
		ft_error("command error");
	}
	if (execve(cmd_path, cmd_arg, envp) == -1)
		ft_error("execve error");
}
