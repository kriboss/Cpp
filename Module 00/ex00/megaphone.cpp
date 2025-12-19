#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char** argv) {
	std::string res;
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    } 
	else
	{
        for (int i = 1; i < argc; ++i)
		{
            res = argv[i];
            for (size_t j = 0; j < res.length(); ++j)
			{
                std::cout << (char)toupper(res[j]);
            }
        }
        std::cout << std::endl;
    }
    return 0;
}

