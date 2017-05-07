all:
	mkdir build; cd build && cmake ../ && make

doc:
	doxygen

clean:
	rm -rf build bin vs2015/* vs2008/*

test:all
	./bin/runTest

