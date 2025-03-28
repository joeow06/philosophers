/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 01:05:24 by jow               #+#    #+#             */
/*   Updated: 2025/03/24 01:05:35 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philo *philo, t_status status)
{
	ft_mutex(&philo->table->write_mutex, LOCK);
	if (status == GOT_LEFT_FORK || status == GOT_RIGHT_FORK)
		printf(MAGEN "%ld" "\t" CYAN "%d" RESET "  has taken a fork\n", \
			get_time_in_ms() - philo->table->start_time, philo->id);
	else if (status == THINKING)
		printf(MAGEN "%ld" "\t" CYAN "%d" YELLOW "  is thinking\n", \
			get_time_in_ms() - philo->table->start_time, philo->id);
	else if (status == SLEEPING)
		printf(MAGEN "%ld" "\t" CYAN "%d" BLUE "  is sleeping\n", \
			get_time_in_ms() - philo->table->start_time, philo->id);
	else if (status == EATING)
		printf(MAGEN "%ld" "\t" CYAN "%d" GREEN "  is eating\n", \
			get_time_in_ms() - philo->table->start_time, philo->id);
	else if (status == DIED)
		printf(MAGEN "%ld" "\t" CYAN "%d" RED "  died\n", \
			get_time_in_ms() - philo->table->start_time, philo->id);
	ft_mutex(&philo->table->write_mutex, UNLOCK);
}
