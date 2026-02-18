#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib> // For srand

int main() {
    std::srand(std::time(NULL));

    Intern someRandomIntern;
    AForm* rrf = NULL;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf) {
        Bureaucrat boss("Boss", 1);
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }

    AForm* scf = someRandomIntern.makeForm("shrubbery creation", "Home");
    if (scf) {
        Bureaucrat boss("Boss", 1);
        boss.signForm(*scf);
        boss.executeForm(*scf);
        delete scf;
    }
    
    AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Criminal");
    if (ppf) {
        Bureaucrat boss("Boss", 1);
        boss.signForm(*ppf);
        boss.executeForm(*ppf);
        delete ppf;
    }

    AForm* unknown = someRandomIntern.makeForm("unknown form", "Target");
    if (unknown) {
        delete unknown;
    } else {
        std::cout << "Unknown form was correctly not created." << std::endl;
    }

    return 0;
}
