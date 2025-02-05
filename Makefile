all: hw4-11 hw4-14 hw4-16 lab4-2 lab4-3 lab4-4 lab4-6 test_hw4-11 test_hw4-14 test_hw4-16 test_lab4-2 test_lab4-3 test_lab4-4 test_lab4-6

CXX = clang++
CXXFLAGS = -std=c++14 -Wall -Werror

hw4-11: hw4-11.cpp
	$(CXX) $(CXXFLAGS) hw4-11.cpp -o hw4-11

hw4-14: hw4-14.cpp
	$(CXX) $(CXXFLAGS) hw4-14.cpp -o hw4-14	

hw4-16: hw4-16.cpp
	$(CXX) $(CXXFLAGS) hw4-16.cpp -o hw4-16	

lab4-2: lab4-2.cpp
	$(CXX) $(CXXFLAGS) lab4-2.cpp -o lab4-2	

lab4-3: lab4-3.cpp
	$(CXX) $(CXXFLAGS) lab4-3.cpp -o lab4-3	

lab4-4: lab4-4.cpp
	$(CXX) $(CXXFLAGS) lab4-4.cpp -o lab4-4	

lab4-6: lab4-6.cpp
	$(CXX) $(CXXFLAGS) lab4-6.cpp -o lab4-6	
	
test_hw4-11: ./test_files/test_hw4-11.cpp
	$(CXX) $(CXXFLAGS) ./test_files/test_hw4-11.cpp -o ./test_files/test_hw4-11

test_hw4-14: ./test_files/test_hw4-14.cpp
	$(CXX) $(CXXFLAGS) ./test_files/test_hw4-14.cpp -o ./test_files/test_hw4-14

test_hw4-16: ./test_files/test_hw4-16.cpp
	$(CXX) $(CXXFLAGS) ./test_files/test_hw4-16.cpp -o ./test_files/test_hw4-16

test_lab4-2: ./test_files/test_lab4-2.cpp
	$(CXX) $(CXXFLAGS) ./test_files/test_lab4-2.cpp -o ./test_files/test_lab4-2

test_lab4-3: ./test_files/test_lab4-3.cpp
	$(CXX) $(CXXFLAGS) ./test_files/test_lab4-3.cpp -o ./test_files/test_lab4-3

test_lab4-4: ./test_files/test_lab4-4.cpp
	$(CXX) $(CXXFLAGS) ./test_files/test_lab4-4.cpp -o ./test_files/test_lab4-4

test_lab4-6: ./test_files/test_lab4-6.cpp
	$(CXX) $(CXXFLAGS) ./test_files/test_lab4-6.cpp -o ./test_files/test_lab4-6

clean:
	rm -f hw4-11 hw4-14 hw4-16 lab4-2 lab4-3 lab4-4 lab4-6 ./test_files/test_hw4-11 ./test_files/test_hw4-14 ./test_files/test_hw4-16 ./test_files/test_lab4-2 ./test_files/test_lab4-3 ./test_files/test_lab4-4 ./test_files/test_lab4-6
