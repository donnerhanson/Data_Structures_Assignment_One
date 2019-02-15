

output: main.o GaussianDist.o StudentInfo.o ProbabilityCalc.o NucleoProb.o StringUtility.o VarianceCalc.o UserInterface.o
	g++ main.o GaussianDist.o StudentInfo.o ProbabilityCalc.o NucleoProb.o StringUtility.o VarianceCalc.o UserInterface.o -o output


main.o: main.cpp
	g++ -c main.cpp

GaussianDist.o: GaussianDist.cpp
	g++ -c GaussianDist.cpp

StudentInfo.o: StudentInfo.cpp
	g++ -c StudentInfo.cpp

ProbabilityCalc.o: ProbabilityCalc.cpp
	g++ -c ProbabilityCalc.cpp

NucleoProb.o: NucleoProb.cpp
	g++ -c NucleoProb.cpp

StringUtility.o: StringUtility.cpp
	g++ -c StringUtility.cpp

VarianceCalc.o: VarianceCalc.cpp
	g++ -c VarianceCalc.cpp

UserInterface.o: UserInterface.cpp
	g++ -c UserInterface.cpp

clean:
	rm *.o output


