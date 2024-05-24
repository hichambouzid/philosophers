
#include "philo.h"


int main(int ac, char **av)
{
	t_data *data;

	data = fill_struct(ac, av);
	if (data)
	{
		printf("%d\n", data->n_philo);
		printf("%d\n", data->t_die);
		printf("%d\n", data->t_eat);
		printf("%d\n", data->t_sleep);
		printf("%d\n", data->n_repeat);
	}
	else
		printf("error in parsing\n");
}