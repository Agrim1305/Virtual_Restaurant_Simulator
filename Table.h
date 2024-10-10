#ifndef TABLE_H
#define TABLE_H

class Table {
private:
    int table_number;
    bool occupied;

public:
    Table(int table_number);

    int get_table_number() const;
    bool is_occupied() const;
    void occupy();
    void vacate();
};

#endif
