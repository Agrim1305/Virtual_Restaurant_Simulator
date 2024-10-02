#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include "MenuItem.h"

class Order {
private:
    std::vector<MenuItem> items;
public:
    void addItem(const MenuItem& item);
    float calculateTotal() const;
};

#endif
