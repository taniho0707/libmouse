files := $(wildcard *.h) $(wildcard *.cpp)

x86: $(files)
	g++ -std=c++11 -fPIC -I../ -shared $(files) -o libmouse_x86.so

arm: $(files)
	arm-none-eabi-g++ -std=c++11 -fPIC -I../ -shared $(files) -o libmouse_arm.so

.PHONY: clean
clean:
	rm *.o
	rm *.so
