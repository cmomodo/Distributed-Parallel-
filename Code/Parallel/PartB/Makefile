CXX = g++
CXXFLAGS = -std=c++11 -fopenmp

TARGET = partB

$(TARGET): partB.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -f $(TARGET)
