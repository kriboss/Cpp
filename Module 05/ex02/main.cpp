#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    std::srand(std::time(NULL));

    Bureaucrat boss("Boss", 1);
    Bureaucrat intern("Intern", 145);

    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robot("Target");
    PresidentialPardonForm pardon("Criminal");

    std::cout << "--- Shrubbery ---" << std::endl;
    intern.signForm(shrub);
    intern.executeForm(shrub);
    boss.executeForm(shrub); // Should succeed already signed

    std::cout << "--- Robotomy ---" << std::endl;
    boss.signForm(robot);
    boss.executeForm(robot);
    
    std::cout << "--- Pardon ---" << std::endl;
    boss.signForm(pardon);
    boss.executeForm(pardon);

    return 0;
}
