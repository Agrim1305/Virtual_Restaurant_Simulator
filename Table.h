#ifndef TABLE_H
#define TABLE_H

// Declaration of the Table clas
class Table {
private:
    int table_number; // The unique number assigned to the table
    bool occupied;    // Indicates whether the table is currently occupied or not

public:
// Constructor to initialize the table with a specific table number and set its initial state to unoccupied
    Table(int table_number);

    int get_table_number() const;
    bool is_occupied() const;
    void occupy();
    void vacate();
};

#endif
