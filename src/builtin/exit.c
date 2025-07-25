/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:06:06 by rheringe          #+#    #+#             */
/*   Updated: 2025/07/16 14:46:18 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static bool	is_numeric(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (false);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (false);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	b_exit(t_data *data, char **argv)
{
	long	exit_code;

	exit_code = 0;
	ft_printf("exit\n");
	if (argv[1] && !is_numeric(argv[1]))
	{
		ft_printf_fd(2, "exit: %s: numeric argument required\n", argv[1]);
		exit_code = 2;
	}
	else if (argv[1] && argv[2])
	{
		ft_putendl_fd("exit: too many arguments", 2);
		exit_code = 1;
	}
	else if (argv[1])
		exit_code = ft_atol(argv[1]) % 256;
	shutdown_program(data);
	exit(exit_code);
}
