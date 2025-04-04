# Philosophers

## 🏛 About the Project
The **Philosophers** project is a classic synchronization problem in concurrency programming. It simulates multiple philosophers sitting around a table, each alternating between thinking, eating, and sleeping. However, each philosopher needs two forks to eat, and there are only a limited number of forks available—introducing challenges like deadlocks and race conditions.

This project is implemented in C using **threads and mutexes** to handle synchronization between philosophers.

## 🛠 Key Concepts
### 🔒 Mutex (Mutual Exclusion)
A **mutex** is a locking mechanism that ensures only one thread can access a shared resource at a time. In this project, mutexes prevent two philosophers from picking up the same fork simultaneously, avoiding data inconsistencies.

### 🧵 Threads
A **thread** is a lightweight process that runs independently but shares resources with other threads. Each philosopher runs as a separate thread, competing for shared resources (forks).

### ⚠️ Data Races
A **data race** occurs when multiple threads access the same resource simultaneously without proper synchronization, leading to unpredictable behavior. For example, if two philosophers try to pick up the same fork at the same time, it could cause inconsistent states.

### ⚡ Deadlocks
A **deadlock** happens when a group of threads gets stuck waiting for resources that are being held by each other. In the **Dining Philosophers** problem, deadlocks can occur if every philosopher picks up their left fork first and waits forever for the right fork.

This project implements a **fork-picking strategy** to prevent deadlocks by enforcing an ordered way of picking up forks.

## 🚀 How to Compile and Run
```bash
make
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```
Example:
```bash
./philo 5 800 200 200
```

