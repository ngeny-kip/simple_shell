
#include "shell.h"

/**
 * exitshell - exits the shell
 * @track: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: exits with a given exit status
 * (0) if info.argv[0] != "exit"
 */
int exitshell(info_t *track)
{
	int check;

	if (track->argv[1]) /* If there is an exit arguement */
	{
		check = _erratoi(track->argv[1]);
		if (check == -1)
		{
			track->status = 2;
			print_error(info, "Number is illigel: ");
			_eputs(track->argv[1]);
			_eputchar('\n');
			return (1);
		}
		track->err_num = _erratoi(track->argv[1]);
		return (-2);
	}
	track->err_num = -1;
	return (-2);
}

