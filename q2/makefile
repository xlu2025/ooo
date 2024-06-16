XX = g++
CXXFLAGS = -std=c++11 -Wall

# Target executable
TARGET = reservation_system

# Source files
SRCS = main.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Rule to link object files into target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Phony target to clean the workspace
clean:
	rm -f $(OBJS) $(TARGET)
