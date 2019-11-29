CXX = g++
CXXFLAGS = -std=c++11 -Wall
cs3-a2: cs3-a2.o list.o  
	$(CXX) $(CXXFLAGS) -o cs3-a2 cs3-a2.o list.o 
cs3-a2.o:cs3-a2.cpp
	$(CXX) $(CXXFLAGS) -c cs3-a2.cpp 
list.o:list.cpp
	$(CXX) $(CXXFLAGS) -c list.cpp  
clean:
	rm -f *.o