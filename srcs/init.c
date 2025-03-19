/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:26:18 by jow               #+#    #+#             */
/*   Updated: 2025/03/19 15:53:02 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	assign_forks(t_philo *philo, int i)
{
	philo->left_fork = i;
	if (i == philo->table->philo_count - 1)
		philo->right_fork = 0;
	else
		philo->right_fork = i + 1;
}

void init_philo(t_table *table)
{
	int	i;
	t_philo	*philo;

	table->philo = malloc(sizeof(t_philo) * table->philo_count);
	if (!table->philo)
		print_error_str("Malloc failed");
	i = 0;
	while (i < table->philo_count)
	{
		philo = table->philo + i;
		philo->id = i + 1;
		philo->meals = 0;
		philo->table = table;
		ft_mutex(&philo->ph_mtx, INIT);
		//assign_forks(philo, i);
		i++;
	}
	printf("Done\n");
}

void init(int ac, char **av, t_table *table)
{
	table->philo_count = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		table->meals = ft_atoi(av[5]);
	else
		table->meals = -1;
	init_philo(table);
	//init_forks;
}
