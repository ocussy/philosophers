# philosophers

arguments :
- number_of_philosophers : nombre de philosophes et de fork
	est ce que je dois accepter tout ce qui passe dans atoi ou seulement des int sans lettres ??
- time_to_die (ms) : temps avant que le philosophe meurt s'il ne mange pas
- time_to_eat : temps qu'il prend pour manger
- time_to_sleep : temps pour dormir 
- number_of_times_each_philosopher_must_eat : (optionnel), nombre de fois
 ou un chaque philosophe doit manger avant que la simulation finisse

fonctions autorisees :
memset, printf, malloc, free, write,
usleep, gettimeofday, pthread_create,
pthread_detach, pthread_join, pthread_mutex_init,
pthread_mutex_destroy, pthread_mutex_lock,
pthread_mutex_unlock

chaque philosophe a un nombre de 1 jusqua number_of_philosophers
chaque philosophe a un fork de 1 jusqua number_of_philosophers
le philosoohe 1 est assit a cote de number_of_philosophes
sinon le n est entre n+1 et n-1

◦ timestamp_in_ms X has taken a fork
◦ timestamp_in_ms X is eating
◦ timestamp_in_ms X is sleeping
◦ timestamp_in_ms X is thinking
◦ timestamp_in_ms X died
X = nombre du philosophe
timestamp_in_ms = timestamp en millisecondes

les messages ne doivent pas se melanger
(chaque enfant doit wait la fin des autres)

les messages de morts ne doivent pas prendre plus de 10ms

les philosophes doivent le moins possible mourir

chaque philosophe doit etre un "thread"
il faut proteger les etats de fork avec un mutex 

pthread_create : creer un thread
	arguments :
	- thread : thread a creer
	- attr : attributs du thread -> pour qu'il tourne sur un systeme temps reel
	- start_routine : fonction a executer par le thread
	- arg : argument de la fonction
0 si success

pthread_join : permet d'attendre les differents threads crees
	arguments :
	- thread : thread a attendre
	- return_status : status du thread
0 si success


mutex : systeme de verrou donnant une garantie sur la viabilite des donnees manipulees par les threads
un mutex est soit verouille ou deverouille

pthread_mutex_init : initialise un mutex

pthread_mutex_destroy : detruit un mutex

pthread_mutex_lock :
	arguments :
	- mutex : adresse d'un mutex

pthread_mutex_unlock pareil

toucher liberer les verrous avant la fin d'un thread

p_thread_detach ??