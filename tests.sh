make
make clean

echo "\na philo should die\n"
./philo 1 500 200 100
echo "----------------------------------"

echo "a philo should die\n"
./philo 4 310 200 100
echo "----------------------------------"

echo "a philo should die\n"
./philo 4 200 205 200
echo "----------------------------------"

echo "no philo should die\n"
./philo 5 800 200 200 7
echo "----------------------------------"

echo "no philo should die\n"
./philo 4 410 200 200 10

echo "The philosopher should not eat and should die."
./philo 1 800 200 200
echo "--------------------------------"

echo "No philosopher should die."
./philo 4 410 200 200 5
echo "--------------------------------"

echo "No philosopher should die."
./philo 5 800 200 200 5
