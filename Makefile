# Makefile for matrix calculator

CXX      = g++
CXXFLAGS = -g -Wall -Wextra

calculator: calculator.cpp matrix.h
	${CXX} ${CXXFLAGS} -o $@ calculator.cpp matrix.h

clean:
	rm calculator *.o *~ *.gch *.dSYM