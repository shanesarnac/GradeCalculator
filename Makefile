gradecalculator: GradeCalculator.cpp Subject.cpp Category.cpp
	g++ -Wall -g Category.cpp Subject.cpp GradeCalculator.cpp -lm -o GradeCalculator

clean: 
	rm *.o
