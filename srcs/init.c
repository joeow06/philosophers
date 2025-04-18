/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:26:18 by jow               #+#    #+#             */
/*   Updated: 2025/04/02 00:06:10 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	assign_forks(t_philo *philo, t_fork *forks, int i);
static void	init_forks(t_table *table);
static void	init_philo(t_table *table);
void		init(int ac, char **av, t_table *table);

static void	assign_forks(t_philo *philo, t_fork *forks, int i)
{
	philo->left_fork = &forks[i];
	philo->right_fork = &forks[(i + 1) % philo->table->philo_count];
}

static void	init_forks(t_table *table)
{
	int	i;

	table->forks = malloc(sizeof(t_fork) * table->philo_count);
	if (!table->forks)
		print_error_exit("Malloc failed");
	i = 0;
	while (i < table->philo_count)
	{
		ft_mutex(&table->forks[i].fork_mtx, INIT);
		table->forks[i].fork_id = i;
		i++;
	}
}

static void	init_philo(t_table *table)
{
	int		i;
	t_philo	*philo;

	table->philo = malloc(sizeof(t_philo) * table->philo_count);
	if (!table->philo)
		print_error_exit("Malloc failed");
	i = 0;
	while (i < table->philo_count)
	{
		philo = table->philo + i;
		philo->id = i + 1;
		philo->meals = table->meals;
		philo->table = table;
		ft_mutex(&philo->ph_mtx, INIT);
		assign_forks(philo, table->forks, i);
		i++;
	}
}

void	init(int ac, char **av, t_table *table)
{
	table->philo_count = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		table->meals = ft_atoi(av[5]);
	else
		table->meals = -1;
	table->is_exit = false;
	table->active_philo = 0;
	ft_mutex(&table->read_mutex, INIT);
	ft_mutex(&table->write_mutex, INIT);
	init_forks(table);
	init_philo(table);
}
