#include <unistd.h>
#include <stdlib.h>

int	ft_popen(const char *file, char *const argv[], char type)
{
	if (!file || !argv || (type != 'r' && type != 'w'))
		return -1;

	int fd[2];

	pipe(fd);
	if (type == 'r')
	{
		if (fork() == 0)
		{
			dup2(fd[1], STDOUT_FILENO);
			close(fd[0]);
			close(fd[1]);
			execvp(file, argv);
			exit (-1);
		}
		close(fd[1]);
		return (fd[0]);
	}
	if (type == 'w')
	{
		if (fork() == 0)
		{
			dup2(fd[0], STDIN_FILENO);
			close(fd[0]);
			close(fd[1]);
			execvp(file, argv);
			exit (-1);
		}
		close(fd[0]);
		return (fd[1]);
	}
	return -1;
}

int main()
{
	char *const argv[] = {"ls", NULL, NULL};
	int fd = ft_popen("ls", argv, 'r');
	if (fd == -1)
		return 1;

	char buffer[1024];
	ssize_t bytesRead;
	while ((bytesRead = read(fd, buffer, sizeof(buffer) - 1)) > 0)
	{
		buffer[bytesRead] = '\0';
		write(STDOUT_FILENO, buffer, bytesRead);
	}
	close(fd);
	return 0;
}
