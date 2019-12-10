CXX = g++
CXXFLAGS = -std=c++11 -Wall
cs3-b:cs3-b.o list2.o
	$(CXX) $(CXXFLAGS) -o cs3-b cs3-b.o list2.o 
cs3-b.o:cs3-b.cpp
	$(CXX) $(CXXFLAGS) -c cs3-b.cpp 
cs3-a1: cs3-a1.o stack_queue.o  
	$(CXX) $(CXXFLAGS) -o cs3-a1 cs3-a1.o stack_queue.o 
cs3-a1.o:cs3-a1.cpp
	$(CXX) $(CXXFLAGS) -c cs3-a1.cpp 
stack_queue.o:stack_queue.cpp
	$(CXX) $(CXXFLAGS) -c stack_queue.cpp  
cs3-a2: cs3-a2.o list.o  
	$(CXX) $(CXXFLAGS) -o cs3-a2 cs3-a2.o list.o 
cs3-a2.o:cs3-a2.cpp
	$(CXX) $(CXXFLAGS) -c cs3-a2.cpp 
list.o:list2.cpp
	$(CXX) $(CXXFLAGS) -c list2.cpp  
clean:
	rm -f *.o