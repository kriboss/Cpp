#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <string to replace> <replacement string>" << std::endl;
		return 1;
	}
	std::ifstream inputFile(argv[1]);
	if (!inputFile.is_open())
	{
		std::cerr << "Error: Could not open file " << argv[1] << std::endl;
		return 1;
	}
	std::ofstream outputfile((argv[1] + std::string(".replace")).c_str());
	if (!outputfile.is_open())
	{
		std::cerr << "Error: Could not create output file." << std::endl;
		return 1;
	}
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::string line;
	while (std::getline(inputFile, line))
	{
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		outputfile << line << std::endl;
	}
	inputFile.close();
	outputfile.close();
	return 0;
}