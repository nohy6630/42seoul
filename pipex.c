/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:52:16 by yenoh             #+#    #+#             */
/*   Updated: 2023/09/14 23:19:44 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_dup_1(char **av, int *fd)
{
	int	fd_in;

	fd_in = open(av[1], O_RDONLY);
	if (fd_in == -1)
		ft_error("open error");
	if (dup2(fd_in, 0) == -1)//fd_in을 표준입력에 복사
		ft_error("dup2 error");
	if (dup2(fd[1], 1) == -1)//fd[1]을 표준출력에 복사
		ft_error("dup2 error");
	close(fd_in);
	close(fd[0]);
	close(fd[1]);
}

static void	ft_child_1(char **av, char **envp)
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
        //여기까지읽었음
		execute(av[2], envp);
	}
	if (dup2(fd[0], STDIN_FILENO) == -1)
		perror_exit("dup2 error");
	close(fd[0]);
	close(fd[1]);
}

static void	child_process_2(char **av, char **envp)
{
	pid_t	pid;
	int		outfile;

	pid = fork();
	if (pid == -1)
		perror_exit("fork error");
	if (pid == 0)
	{
		outfile = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (outfile == -1)
			perror_exit("outfile error");
		if (dup2(outfile, STDOUT_FILENO) == -1)
			perror_exit("dup2 error");
		execute(av[3], envp);
	}
}

int	main(int ac, char **av, char **envp)
{
	int		i;
	int		fd_in;
	int		fd_out;

	fd_in = dup(0);
	fd_out = dup(1);
	if (ac != 5)
		ft_error("argument error");
	i = -1;
	while (++i < 2)
	{
		if (i == 0)
			ft_child_1(av, envp);
		else if (i == 1)
			child_process_2(av, envp);
	}
	dup2(fd_in, 0);
	dup2(fd_out, 1);
	close(fd_in);
	close(fd_out);
	i = -1;
	while (++i < 2)
		wait(NULL);
}