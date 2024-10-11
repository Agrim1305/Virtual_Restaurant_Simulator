#include "HeadChef.h"

//HeadChef class, initializes the HeadChef's name and ID
HeadChef::HeadChef(const std::string& name, int id) : Chef(name, id) {}

// Outputs the HeadChef's name and indicates that they are managing the kitchen
void HeadChef::perform_task() const {
    std::cout << "Head Chef " << name << " is managing the kitchen.\n";
}
