CXX = g++
CXXFLAGS = -std=c++11 -Wall

cs4a: cs4a.o   
	$(CXX) $(CXXFLAGS) -o cs4a cs4a.o 
cs4a.o:cs4a.cpp
	$(CXX) $(CXXFLAGS) -c cs4a.cpp 
clean:
	rm -f *.o