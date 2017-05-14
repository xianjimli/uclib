all:
	mkdir build; cd build && cmake ../ && make

doc:
	./bin/extract_doc uclib/array.h tempjs
	./bin/extract_doc uclib/value.h tempjs
	./bin/extract_doc uclib/date_time.h tempjs
	./bin/extract_doc uclib/event.h tempjs
	./bin/extract_doc uclib/str.h tempjs
	jsduck --output docs/ tempjs

clean:
	rm -rf build bin vs2015/* vs2008/*

test:all
	./bin/runTest

