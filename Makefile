all:
	g++ file1.cpp -o output
	g++ file2.cpp -o output2
	g++ file.cpp -o output3
clean:
	rm -f output output2 output3 
