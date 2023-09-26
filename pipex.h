/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:52:19 by yenoh             #+#    #+#             */
/*   Updated: 2023/09/24 16:53:38 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(const char *s, char c);
char	**ft_split_2(const char *s, char c);
void	ft_error(char *m);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
char	**get_paths(char **envp);
char	*get_cmd_path(char **path, char *cmd);
void	execute_cmd(char *cmd, char **envp);

#endif