# Variables
CXX = g++                  # The compiler being used
CXXFLAGS = -Wall -g         # Flags for warnings and debugging information
TARGET = restaurant_simulator  # The final executable file name

# Object files to be compiled
OBJFILES = main.o Restaurant.o Ingredient.o Inventory.o Menu.o Employee.o Customer.o

# Rule to build the final executable
$(TARGET): $(OBJFILES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJFILES)

# Rule to compile main.o
main.o: main.cpp Restaurant.h Menu.h Inventory.h Employee.h Customer.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Rule to compile Restaurant.o
Restaurant.o: Restaurant.cpp Restaurant.h Menu.h Inventory.h
	$(CXX) $(CXXFLAGS) -c Restaurant.cpp

# Rule to compile Ingredient.o
Ingredient.o: Ingredient.cpp Ingredient.h
	$(CXX) $(CXXFLAGS) -c Ingredient.cpp

# Rule to compile Inventory.o
Inventory.o: Inventory.cpp Inventory.h Ingredient.h
	$(CXX) $(CXXFLAGS) -c Inventory.cpp

# Rule to compile Menu.o
Menu.o: Menu.cpp Menu.h
	$(CXX) $(CXXFLAGS) -c Menu.cpp

# Rule to compile Employee.o
Employee.o: Employee.cpp Employee.h
	$(CXX) $(CXXFLAGS) -c Employee.cpp

# Rule to compile Customer.o
Customer.o: Customer.cpp Customer.h
	$(CXX) $(CXXFLAGS) -c Customer.cpp

# Clean rule to remove all compiled object files and the final executable
clean:
	rm -f $(OBJFILES) $(TARGET)
