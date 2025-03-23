/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:24:05 by jow               #+#    #+#             */
/*   Updated: 2025/03/24 00:24:56 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_table	t_table;

typedef enum e_thread_type
{
	INIT,
	JOIN,
	DETACH
}	t_thread_type;

typedef enum e_mutex_type
{
	INIT,
	DESTROY,
	LOCK,
	UNLOCK,
	JOIN,
	CREATE,
	DETACH
}	t_mtx_type;

typedef struct s_fork
{
	int				fork_id;
	pthread_mutex_t	fork_mtx;
}					t_fork;

typedef struct s_philo
{
	int				id;
	int				meals;
	time_t			last_meal_time;
	t_fork			*left_fork;
	t_fork			*right_fork;
	pthread_mutex_t	ph_mtx;
	pthread_t		ph_thread;
	t_table			*table;
}					t_philo;

typedef struct s_table
{
	int				philo_count;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	time_t			start_time;
	time_t			end_time;
	int				meals;
	bool			is_exit;
	pthread_t		dead_thread;
	pthread_mutex_t	read_mutex;
	pthread_mutex_t	write_mutex;
	t_fork			*forks;
	t_philo			*philo;
}					t_table;

/* PARSER_C */
int		check_number(char *str);
int		check_valid_args(int ac, char **av);
void	parse_args(int ac, char **av, t_table *table);
void	parser(int ac, char **av, t_table *table);

/*	UTILS_C */
int		ft_atoi(const char *str);
time_t	get_time_in_ms(void);

/*	PTHREAD_UTILS_C*/
void	ft_mutex(pthread_mutex_t *mutex, t_mtx_type type);

/*	ERROR_C */
void	print_error_exit(char *str);

/*	INIT_C */
void	init(int ac, char **av, t_table *table);

/*	SIMULATION_C */
void	simulation(t_table *table);

/*	SET_GET_C */
void	set_bool(pthread_mutex_t *mutex, bool *value, bool new_value);
bool	get_bool(pthread_mutex_t *mutex, bool *value);
void	set_long(pthread_mutex_t *mutex, long *value, long new_value);
long	get_long(pthread_mutex_t *mutex, long *value);

#endif
