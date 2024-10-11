#ifndef HEADCHEF_H
#define HEADCHEF_H

#include "Chef.h"
#include <iostream>

// Declaration of the HeadChef class that inherits from the Chef class
class HeadChef : public Chef {
public:
// Constructor for the HeadChef class that initializes the name and ID of the HeadChef
    HeadChef(const std::string& name, int id);
    
// Method to define the specific task a HeadChef performs
    void perform_task() const override;
};

#endif
