/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:34:18 by jow               #+#    #+#             */
/*   Updated: 2025/03/21 17:21:43 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int			ft_atoi(const char *str);
void		ft_mutex(pthread_mutex_t *mutex, t_mutex_type type);
time_t		get_time_in_ms(void);


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
	if (type == INIT)
	{
		if (pthread_mutex_init(mutex, NULL) != 0)
			print_error_exit("Mutex init failed");
	}
	else if (type == DESTROY)
	{
		if (pthread_mutex_destroy(mutex) != 0)
			print_error_exit("Mutex destroy failed");
	}
	else if (type == LOCK)
	{
		if (pthread_mutex_lock(mutex) != 0)
			print_error_exit("Mutex lock failed");
	}
	else if (type == UNLOCK)
	{
		if (pthread_mutex_unlock(mutex) != 0)
			print_error_exit("Mutex unlock failed");
	}
}

time_t	get_time_in_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
