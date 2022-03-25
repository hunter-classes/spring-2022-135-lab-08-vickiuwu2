main: main.o imageio.o funcs.o
	g++ -o main main.o imageio.o funcs.o

sample: sample.o imageio.o
	g++ -o sample sample.o imageio.o

sample.o: sample.cpp imageio.h

funcs.o: funcs.cpp imageio.h

main.o: main.cpp funcs.h imageio.h

imageio.o: imageio.cpp imageio.h

clean:
	rm -f main sample main.o sample.o imageio.o funcs.o