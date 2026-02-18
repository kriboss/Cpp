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
	std::ifstream infile(argv[1]);
	if (!infile.is_open())
	{
		std::cerr << "Error: Could not open file " << argv[1] << std::endl;
		return 1;
	}
	std::ofstream outfile((argv[1] + std::string(".replace")).c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Error: Could not create output file." << std::endl;
		infile.close();
		return 1;
	}
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (s1.empty())
	{
		std::cerr << "Error: String to replace is empty." << std::endl;
		infile.close();
		outfile.close();
		return 1;
	}
	std::string line;
	bool first = true;
	while (std::getline(infile, line))
	{
		if (!first)
			outfile << "\n";
		first = false;
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		outfile << line;
	}
	infile.close();
	outfile.close();
	return 0;
}