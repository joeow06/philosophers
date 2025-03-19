/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:34:18 by jow               #+#    #+#             */
/*   Updated: 2025/03/17 20:55:35 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}

void	ft_mutex(pthread_mutex_t *mutex, t_mutex_type type)
{
	printf("mutex: %p\n", mutex);
	if (type == INIT)
	{
		if (pthread_mutex_init(mutex, NULL) != 0)
			print_error_str("Mutex init failed");
	}
	else if (type == DESTROY)
	{
		if (pthread_mutex_destroy(mutex) != 0)
			print_error_str("Mutex destroy failed");
	}
	else if (type == LOCK)
	{
		if (pthread_mutex_lock(mutex) != 0)
			print_error_str("Mutex lock failed");
	}
	else if (type == UNLOCK)
	{
		if (pthread_mutex_unlock(mutex) != 0)
			print_error_str("Mutex unlock failed");
	}
}
