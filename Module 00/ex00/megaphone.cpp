#include <iostream>
#include <cctype>

class Megaphone {
	public:
		char **message;
};

char **to_upper(char *argv[])
{
	int i = 0;
	int j = 0;
	char **str;

	str = argv;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			argv[i][j] = std::toupper(argv[i][j]);
			j++;
		}
		i++;
	}
	return str;
}

int	main(int argc, char *argv[])
{
	Megaphone megaphone;
	int i = 1;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return 0;
	}
	megaphone.message = to_upper(argv);
	while (megaphone.message[i])
	{
		std::cout << megaphone.message[i] << " ";
		i++;
	}
	std::cout << std::endl;
	return 0;
}
