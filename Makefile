CPPFLAGS = -O3
GCC = g++

all: scrub normal

scrub: scrub.cpp
	$(GCC) $(CPPFLAGS) scrub.cpp -o scrub

normal: normal.cpp
	$(GCC) $(CPPFLAGS) normal.cpp -o normal

clean:
	rm scrub
	rm -f *.o

#*******************************************************************************
#
# ... (C) 2015, Andrew Sheppard, all rights reserved.
#
#*******************************************************************************
