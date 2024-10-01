#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include "MenuItem.h"

class Order {
private:
    std::vector<MenuItem> items;

public:
    void add_item(const MenuItem& item);
    void display_order() const;
};

#endif
