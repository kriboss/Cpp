#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat b1("Alice", 2);
        Form f1("FormA", 1, 1);
        std::cout << b1 << std::endl;
        std::cout << f1 << std::endl;
        
        // Use signForm which calls beSigned
        b1.signForm(f1); // Should fail (grade 2 not enough for 1)
        
        b1.incrementGrade(); // Now grade 1
        std::cout << b1 << std::endl;
        b1.signForm(f1); // Should succeed
        
        std::cout << f1 << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Form f2("FormB", 150, 150);
        Bureaucrat b2("Bob", 150);
        b2.signForm(f2); // Succeed
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    // Exception test in Form constructor
    try {
        Form f3("FormC", 0, 100);
    } catch (std::exception& e) {
        std::cerr << "Constructor Exception: " << e.what() << std::endl;
    }

    return 0;
}
