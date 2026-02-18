#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int ft_popen(const char *com, char *const arg[], char flag)
{
	int fd[2];
	pid_t pid;

	if (!com || !arg || (flag != 'r' && flag != 'w'))
		return (-1);
	if (pipe(fd) == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
	{
		close(fd[0]);
		close(fd[1]);
		return (-1);
	}
	if (pid == 0)
	{
		if (flag == 'r')
		{
			if (dup2(fd[1], STDOUT_FILENO) == -1)
				exit(1);
		}else
		{
			if (dup2(fd[1], STDIN_FILENO) == -1)
				exit(1);
		}
		close(fd[0]);
		close(fd[1]);
		execvp(com, arg);
		exit(1);
	}
	else{
		if (flag == 'r')
		{
			close(fd[1]);
			return (fd[0]);
		}
		else
		{
			close(fd[0]);
			return (fd[1]);
		}
	}
}

int main()
{
	int fd;
	char buf[1024];
	ssize_t n;

	fd = ft_popen("ls", (char *const []){"ls", NULL}, 'r');
	while ((n = read(fd, buf, sizeof(buf) - 1)) > 0) {
		buf[n] = '\0';
		write(1, buf, n);
	}
	return 0;
}


// int	main() {
// 	int	fd = ft_popen("ls", (char *const []){"ls", NULL}, 'r');
// 	dup2(fd, 0);
// 	fd = ft_popen("grep", (char *const []){"grep", "c", NULL}, 'r');
// 	char	*line;
// 	while ((line = get_next_line(fd)))
// 		printf("%s", line);
// }