# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -g

# Output file
TARGET = restaurant_simulator

# Object files
OBJFILES = main.o Restaurant.o Ingredient.o Inventory.o Menu.o MenuItem.o Employee.o Person.o Chef.o HeadChef.o Waiter.o Manager.o Customer.o Order.o Table.o

# Rule to link all object files and create the executable
$(TARGET): $(OBJFILES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJFILES)

# Rule to compile each .cpp file into .o files
main.o: main.cpp Restaurant.h Menu.h Inventory.h Employee.h Customer.h Table.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Restaurant.o: Restaurant.cpp Restaurant.h Menu.h Inventory.h
	$(CXX) $(CXXFLAGS) -c Restaurant.cpp

Ingredient.o: Ingredient.cpp Ingredient.h
	$(CXX) $(CXXFLAGS) -c Ingredient.cpp

Inventory.o: Inventory.cpp Inventory.h Ingredient.h
	$(CXX) $(CXXFLAGS) -c Inventory.cpp

Menu.o: Menu.cpp Menu.h
	$(CXX) $(CXXFLAGS) -c Menu.cpp

MenuItem.o: MenuItem.cpp MenuItem.h
	$(CXX) $(CXXFLAGS) -c MenuItem.cpp

Employee.o: Employee.cpp Employee.h Person.h
	$(CXX) $(CXXFLAGS) -c Employee.cpp

Person.o: Person.cpp Person.h
	$(CXX) $(CXXFLAGS) -c Person.cpp

Chef.o: Chef.cpp Chef.h Employee.h
	$(CXX) $(CXXFLAGS) -c Chef.cpp

HeadChef.o: HeadChef.cpp HeadChef.h Chef.h
	$(CXX) $(CXXFLAGS) -c HeadChef.cpp

Waiter.o: Waiter.cpp Waiter.h Employee.h
	$(CXX) $(CXXFLAGS) -c Waiter.cpp

Manager.o: Manager.cpp Manager.h Employee.h
	$(CXX) $(CXXFLAGS) -c Manager.cpp

Customer.o: Customer.cpp Customer.h Order.h
	$(CXX) $(CXXFLAGS) -c Customer.cpp

Order.o: Order.cpp Order.h MenuItem.h
	$(CXX) $(CXXFLAGS) -c Order.cpp

Table.o: Table.cpp Table.h
	$(CXX) $(CXXFLAGS) -c Table.cpp

# Rule to clean up the build
clean:
	rm -f $(OBJFILES) $(TARGET)
