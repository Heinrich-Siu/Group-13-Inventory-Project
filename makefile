CC:=g++

controlrecord.o: controlrecord.cpp controlrecord.h readrecord.h searcher.h printer.h
	g++ -c controlrecord.cpp

inventoryStatus.o: inventoryStatus.h inventoryStatus.cpp printer.h controlrecord.h searcher.h
	g++ -c inventoryStatus.cpp

printer.o: printer.cpp printer.h controlrecord.h searcher.h
	g++ -c printer.cpp

readrecord.o: readrecord.cpp readrecord.h
	g++ -c readrecord.cpp

Save_Record_to_file.o: Save_Record_to_file.cpp Save_Record_to_file.h readrecord.h
	g++ -c Save_Record_to_file.cpp

searcher.o: searcher.cpp searcher.h printer.h
	g++ -c searcher.cpp

sort.o: sort.cpp sort.h readrecord.h
	g++ -c sort.cpp

main.o: inventorysys.h readrecord.h searcher.h printer.h controlrecord.h sort.h Save_Record_to_file.h inventoryStatus.h main.cpp
	g++ -c main.cpp

main.out: main.o controlrecord.o inventoryStatus.o printer.o readrecord.o Save_Record_to_file.o searcher.o sort.o
	g++ main.o controlrecord.o inventoryStatus.o printer.o readrecord.o Save_Record_to_file.o searcher.o sort.o -o main.out
