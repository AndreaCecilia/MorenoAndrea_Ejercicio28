img.png: 1.dat c.py
	python c.py	

1.dat: Ej.x
	./Ej.x > 1.dat
Ej.x : c.cpp
	c++ c.cpp -o Ej.x
clean :
	rm -r Ej.x img.png 1.dat