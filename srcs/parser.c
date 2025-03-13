/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:14:32 by jow               #+#    #+#             */
/*   Updated: 2025/02/05 11:32:49 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parser(int ac, char **av, t_table *table);
void	parse_args(int ac, char **av, t_table *table);
int		check_number(char *str);
int		check_valid_args(int ac, char **av);

void	parser(int ac, char **av, t_table *table)
{
	if (!check_valid_args(ac, av))
		print_error_str("Invalid arguments");
	parse_args(ac, av, table);
}

void	parse_args(int ac, char **av, t_table *table)
{
	if (!table)
		print_error_str("Malloc failed");
	table->philo_count = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		table->meals = ft_atoi(av[5]);
	else
		table->meals = -1;
}

int	check_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	check_valid_args(int ac, char **av)
{
	if (ft_atoi(av[1]) < 1 || ft_atoi(av[1]) > 200 || check_number(av[1]))
		return (0);
	if (ft_atoi(av[2]) < 0 || check_number(av[2]))
		return (0);
	if (ft_atoi(av[3]) < 0 || check_number(av[3]))
		return (0);
	if (ft_atoi(av[4]) < 0 || check_number(av[4]))
		return (0);
	if (ac == 6 && (ft_atoi(av[5]) < 1 || check_number(av[5])))
		return (0);
	return (1);
}
