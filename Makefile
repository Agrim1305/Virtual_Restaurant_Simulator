# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -g

# Executable name
EXEC = restaurant_simulator

# Source files
SRCS = main.cpp Person.cpp Employee.cpp Chef.cpp Waiter.cpp Manager.cpp \
       MenuItem.cpp Menu.cpp Customer.cpp Order.cpp Inventory.cpp Restaurant.cpp Table.cpp

# Object files (automatically generated from the source files)
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(EXEC)

# Rule to link object files and create the executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

# Rule to compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean up object files and the executable
clean:
	rm -f $(OBJS) $(EXEC)

# Debug option
debug: CXXFLAGS += -DDEBUG
debug: $(EXEC)
