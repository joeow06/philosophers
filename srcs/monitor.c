/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 20:12:02 by jow               #+#    #+#             */
/*   Updated: 2025/03/28 15:10:26 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		*monitoring(void *data);
static bool	is_philo_dead(t_philo *philo);
static bool	all_philo_full(t_table *table);
static bool	wait_active_philo(t_table *table);

static bool	all_philo_full(t_table *table)
{
	bool	value;
	int		i;

	value = true;
	i = 0;
	while (i < table->philo_count)
	{
		ft_mutex(&table->philo[i].ph_mtx, LOCK);
		if (table->philo[i].meals > 0 || table->philo[i].meals < 0)
			value = false;
		ft_mutex(&table->philo[i].ph_mtx, UNLOCK);
		if (value == false)
			break ;
		i++;
	}
	return (value);
}

static bool	is_philo_dead(t_philo *philo)
{
	time_t	last_meal;

	set_bool(&philo->ph_mtx, &philo->table->is_dead, false);
	last_meal = get_time(&philo->ph_mtx, &philo->last_meal_time);
	if (last_meal + philo->table->time_to_die < get_time_in_ms())
		set_bool(&philo->ph_mtx, &philo->table->is_dead, true);
	return (get_bool(&philo->ph_mtx, &philo->table->is_dead));
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
	while (get_bool(&table->read_mutex, &table->is_exit) == false)
	{
		i = 0;
		while (i < table->philo_count && \
			!get_bool(&table->read_mutex, &table->is_exit))
		{
			if (is_philo_dead(table->philo + i) || all_philo_full(table))
			{
				set_bool(&table->read_mutex, &table->is_exit, true);
				if (get_bool(&table->read_mutex, &table->is_dead) == true)
					print_status(table->philo + i, DIED);
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}
