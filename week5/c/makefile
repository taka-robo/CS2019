CXX = g++
CXXFLAGS = -std=c++11 -Wall
cs3-b:cs4c.o list2.o
	$(CXX) $(CXXFLAGS) -o cs4c cs4c.o list2.o 
cs4c.o:cs4c.cpp
	$(CXX) $(CXXFLAGS) -c cs4c.cpp 
list2.o:list2.cpp
	$(CXX) $(CXXFLAGS) -c list2.cpp  
clean:
	rm -f *.o