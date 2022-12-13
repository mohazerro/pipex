/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:11:04 by mgamil            #+#    #+#             */
/*   Updated: 2022/12/14 00:02:11 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_printstruct(t_args *args, int ac)
{
	int		i;
	int		j;
	char	**cmd;

	i = -1;
	ft_printf("env=");
	while (args->env[++i])
		ft_printf("%g%s%0:", args->env[i]);
	ft_printf("\n");
	ft_printf("infile=%y\t\t%i%0\t[%i]\n", args->infile, 1);
	i = -1;
	while (args->cmds[++i])
	{
		cmd = ft_split(args->cmds[i], ' ');
		j = 0;
		ft_printf("cmd[%i]=%m\t\t%s%0\t[%i]\n", i, cmd[0], i + 2);
		while (cmd[++j])
			ft_printf("flags[%i]=%m\t%s%0\t\n", j, cmd[j]);
		ft_freetab((void **)cmd);
	}
	ft_printf("outfile=%y\t%i%0\t[%i]\n", args->outfile, ac -1);
	ft_printf("nbcmds=\t\t%r%i%0\n", args->nbcmds);
}
