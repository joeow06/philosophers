/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:16:24 by jow               #+#    #+#             */
/*   Updated: 2025/03/30 14:27:34 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		simulation(t_table *table);
static void	*philo_routine(void *data);
static void	eat_routine(t_philo *philo);
static void	sleep_think_routine(t_philo *philo);
static void	*single_philo(t_table *table);

static void	*single_philo(t_table *table)
{
	ft_mutex(&table->philo[0].ph_mtx, LOCK);
	print_status(&table->philo[0], GOT_LEFT_FORK);
	ft_wait(table->time_to_die, table);
	print_status(&table->philo[0], DIED);
	ft_mutex(&table->philo[0].ph_mtx, UNLOCK);
	return (NULL);
}

static void	sleep_think_routine(t_philo *philo)
{
	print_status(philo, SLEEPING);
	ft_wait(philo->table->time_to_sleep, philo->table);
	print_status(philo, THINKING);
}

static void	eat_routine(t_philo *philo)
{
	if (philo->left_fork->fork_id > philo->right_fork->fork_id)
	{
		ft_mutex(&philo->left_fork->fork_mtx, LOCK);
		print_status(philo, GOT_LEFT_FORK);
		ft_mutex(&philo->right_fork->fork_mtx, LOCK);
		print_status(philo, GOT_RIGHT_FORK);
	}
	else
	{
		ft_mutex(&philo->right_fork->fork_mtx, LOCK);
		print_status(philo, GOT_RIGHT_FORK);
		ft_mutex(&philo->left_fork->fork_mtx, LOCK);
		print_status(philo, GOT_LEFT_FORK);
	}
	print_status(philo, EATING);
	set_time(&philo->ph_mtx, &philo->last_meal_time, get_time_in_ms());
	ft_wait(philo->table->time_to_eat, philo->table);
	ft_mutex(&philo->ph_mtx, LOCK);
	philo->meals -= 1;
	ft_mutex(&philo->ph_mtx, UNLOCK);
	ft_mutex(&philo->left_fork->fork_mtx, UNLOCK);
	ft_mutex(&philo->right_fork->fork_mtx, UNLOCK);
}

static void	*philo_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	active_philo(philo->table);
	if (philo->id % 2 == 0)
		ft_wait(philo->table->time_to_sleep, philo->table);
	while (!get_bool(&philo->table->read_mutex, &philo->table->is_exit))
	{
		eat_routine(philo);
		if (philo->meals == 0 || get_bool(&philo->table->read_mutex, \
				&philo->table->is_exit))
			break ;
		sleep_think_routine(philo);
	}
	return (NULL);
}

void	simulation(t_table *table)
{
	int	i;

	table->start_time = get_time_in_ms();
	if (table->philo_count == 1)
		single_philo(table);
	else
	{
		i = 0;
		while (i < table->philo_count)
		{
			set_time(&table->philo[i].ph_mtx, &table->philo[i].last_meal_time, \
					get_time_in_ms());
			ft_thread(&table->philo[i].ph_thread, &philo_routine, \
				&table->philo[i], CREATE);
			i++;
		}
		ft_thread(&table->death_thread, &monitoring, table, CREATE);
		i = 0;
		while (i < table->philo_count)
		{
			ft_thread(&table->philo[i].ph_thread, NULL, NULL, JOIN);
			i++;
		}
		ft_thread(&table->death_thread, NULL, NULL, JOIN);
	}
}
