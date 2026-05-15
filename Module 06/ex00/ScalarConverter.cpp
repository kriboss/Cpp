#include "ScalarConverter.hpp"
#include <cstdlib>

static bool isPseudoLiteral(const std::string& s) {
	return s == "nan" || s == "nanf" || s == "+inf" || s == "-inf" || s == "+inff" || s == "-inff";
}

static bool isCharLiteral(const std::string& s) {
	return s.length() == 1 && !std::isdigit(static_cast<unsigned char>(s[0]));
}

static void printChar(double d) {
	std::cout << "char: ";
	if (std::isnan(d) || d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(d)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
}

static void printInt(double d) {
	std::cout << "int: ";
	if (std::isnan(d) || d < static_cast<double>(std::numeric_limits<int>::min()) || d > static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;
}

static void printFloat(double d) {
	std::cout << "float: ";
	float f = static_cast<float>(d);
	if (std::isnan(d))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(d))
		std::cout << (d < 0 ? "-inff" : "+inff") << std::endl;
	else {
		std::cout.setf(std::ios::fixed);
		std::cout.precision(1);
		std::cout << f << "f" << std::endl;
		std::cout.unsetf(std::ios::fixed);
	}
}

static void printDouble(double d) {
	std::cout << "double: ";
	if (std::isnan(d))
		std::cout << "nan" << std::endl;
	else if (std::isinf(d))
		std::cout << (d < 0 ? "-inf" : "+inf") << std::endl;
	else {
		std::cout.setf(std::ios::fixed);
		std::cout.precision(1);
		std::cout << d << std::endl;
		std::cout.unsetf(std::ios::fixed);
	}
}

void ScalarConverter::convert(const std::string &literal)
{
	// Handle single-char literal like 'a'
	if (isCharLiteral(literal)) {
		char c = literal[0];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout.setf(std::ios::fixed);
		std::cout.precision(1);
		std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << std::endl;
		std::cout.unsetf(std::ios::fixed);
		return;
	}

	// Handle pseudo-literals
	if (isPseudoLiteral(literal)) {
		std::string s = literal;
		// normalize f-forms
		if (s == "nanf") s = "nan";
		if (s == "+inff") s = "+inf";
		if (s == "-inff") s = "-inf";
		double d = strtod(s.c_str(), NULL);
		// char
		printChar(d);
		// int
		printInt(d);
		// float
		if (std::isnan(d)) std::cout << "float: nanf" << std::endl;
		else if (std::isinf(d)) std::cout << (d < 0 ? "float: -inff" : "float: +inff") << std::endl;
		else printFloat(d);
		// double
		printDouble(d);
		return;
	}

	// Try parse as double (covers int and float forms too)
	char* endptr = NULL;
	double d = strtod(literal.c_str(), &endptr);
	if (*endptr != '\0' && !(*endptr == 'f' && *(endptr+1) == '\0')) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	// For float literal with trailing 'f', it's still parsed into d
	printChar(d);
	printInt(d);
	printFloat(d);
	printDouble(d);
}