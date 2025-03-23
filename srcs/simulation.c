/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:16:24 by jow               #+#    #+#             */
/*   Updated: 2025/03/24 00:08:51 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*philo_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->table->philo_count == 1)
		single_philo(philo);
	if (philo->id % 2 == 0)
		
}

void	simulation(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_count)
	{
		ft_mutex(&table->philo[i].ph_mtx, LOCK);
		table->philo[i].last_meal_time = get_time_in_ms();
		ft_mutex(&table->philo[i].ph_mtx, UNLOCK);
		ft_thread(&table->philo[i].ph_thread, &philo_routine, &table->philo[i], CREATE);
		i++;
	}
	ft_thread(&table->dead_thread, &monitor_death, table, CREATE);
	table->start_time = get_time_in_ms();
	set_bool

}
