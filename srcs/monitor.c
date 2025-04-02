/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 20:12:02 by jow               #+#    #+#             */
/*   Updated: 2025/04/02 14:30:23 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		*monitoring(void *data);
static bool	is_philo_dead(t_philo *philo);
static bool	all_philo_full(t_table *table);
static bool	wait_active_philo(t_table *table);

static bool	all_philo_full(t_table *table)
{
	int		i;

	i = 0;
	while (i < table->philo_count)
	{
		ft_mutex(&table->philo[i].ph_mtx, LOCK);
		if (table->philo[i].meals != 0)
		{
			ft_mutex(&table->philo[i].ph_mtx, UNLOCK);
			return (false);
		}
		ft_mutex(&table->philo[i].ph_mtx, UNLOCK);
		i++;
	}
	return (true);
}

/*
Let's say the philo last meal time was 0ms, and time to die is 100ms,
if current time is 50ms, philo is not dead cuz 0 + 100 < 50 is false
if current time is 150ms, philo is dead cuz 0 + 100 < 150 is true
*/
static bool	is_philo_dead(t_philo *philo)
{
	time_t	last_meal;

	last_meal = get_time(&philo->ph_mtx, &philo->last_meal_time);
	ft_mutex(&philo->ph_mtx, LOCK);
	if (last_meal + philo->table->time_to_die < get_time_in_ms() && \
		philo->meals != 0)
	{
		set_bool(&philo->table->read_mutex, &philo->table->is_dead, true);
		print_status(philo, DIED);
	}
	else
		set_bool(&philo->table->read_mutex, &philo->table->is_dead, false);
	ft_mutex(&philo->ph_mtx, UNLOCK);
	return (get_bool(&philo->table->read_mutex, &philo->table->is_dead));
}

static bool	wait_active_philo(t_table *table)
{
	bool	value;

	value = false;
	ft_mutex(&table->write_mutex, LOCK);
	if (table->active_philo == table->philo_count)
		value = true;
	ft_mutex(&table->write_mutex, UNLOCK);
	return (value);
}

void	*monitoring(void *data)
{
	int		i;
	t_table	*table;

	table = (t_table *)data;
	while (wait_active_philo(table) == false)
		usleep(100);
	while (!get_bool(&table->read_mutex, &table->is_exit))
	{
		i = 0;
		while (i < table->philo_count && \
			!get_bool(&table->read_mutex, &table->is_exit))
		{
			if (is_philo_dead(table->philo + i) || all_philo_full(table))
			{
				set_bool(&table->read_mutex, &table->is_exit, true);
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}
