rm -rf tempjs/*
mkdir tempjs

for f in uclib/*.h;
do
    ./bin/extract_doc $f tempjs
	jsduck --output docs/ tempjs
done
