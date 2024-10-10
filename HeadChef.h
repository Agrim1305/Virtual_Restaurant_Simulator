#ifndef HEADCHEF_H
#define HEADCHEF_H

#include "Chef.h"
#include <iostream>

class HeadChef : public Chef {
public:
    HeadChef(const std::string& name, int id);
    void perform_task() const override;
};

#endif
