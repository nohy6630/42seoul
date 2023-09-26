/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:52:16 by yenoh             #+#    #+#             */
/*   Updated: 2023/09/27 08:38:27 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_dup_1(char **av, int *fd)
{
	int	infile;

	infile = open(av[1], O_RDONLY);
	if (infile == -1)
		ft_error("open error");
	if (dup2(infile, STDIN_FILENO) == -1)
		ft_error("dup2 error");
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		ft_error("dup2 error");
	close(infile);
	close(fd[0]);
	close(fd[1]);
}

void	ft_func_1(char **av, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		ft_error("pipe error");
	pid = fork();
	if (pid == -1)
		ft_error("fork error");
	if (pid == 0)
	{
		ft_dup_1(av, fd);
		execute_cmd(av[2], envp);
	}
	if (dup2(fd[0], 0) == -1)
		ft_error("dup2 error");
	close(fd[0]);
	close(fd[1]);
}

void	ft_func_2(char **av, char **envp)
{
	pid_t	pid;
	int		outfile;

	pid = fork();
	if (pid == -1)
		ft_error("fork error");
	if (pid == 0)
	{
		outfile = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (outfile == -1)
			ft_error("open error");
		if (dup2(outfile, 1) == -1)
			ft_error("dup2 error");
		execute_cmd(av[3], envp);
	}
}

int	main(int ac, char **av, char **envp)
{
	int	tmp_fd[2];
	int	status1;
	int	status2;

	tmp_fd[0] = dup(0);
	tmp_fd[1] = dup(1);
	if (ac != 5)
		ft_error("argument error");
	ft_func_1(av, envp);
	ft_func_2(av, envp);
	dup2(tmp_fd[0], 0);
	dup2(tmp_fd[1], 1);
	close(tmp_fd[0]);
	close(tmp_fd[1]);
	wait(&status1);
	wait(&status2);
	if (WEXITSTATUS(status1) == 2 || WEXITSTATUS(status2) == 2)
		return (2);
	return (0);
}
