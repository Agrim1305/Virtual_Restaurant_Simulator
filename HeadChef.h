#ifndef HEADCHEF_H
#define HEADCHEF_H

#include "Chef.h"

class HeadChef : public Chef {
public:
    HeadChef(const std::string& name, int id);

    // Override perform_task for HeadChef
    void perform_task() const override;

    // Additional responsibility for HeadChef
    void plan_menu() const;
};

#endif
