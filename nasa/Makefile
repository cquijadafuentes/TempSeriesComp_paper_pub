CPP=g++

PREFLAGS=-std=c++11 -g -O0 -DNDEBUG -I ~/include -L ~/lib

POSFLAGS=-lsdsl -ldivsufsort -ldivsufsort64

BINS=TRQC_load_trqc \
		TRQC_nasa_build_from_bin \
		TRQC_nasa_to_bin \
		TRQC_print_getSerie \
		TRQC_time_accessQuery \
		TRQC_time_getSerieQuery \
		TRQC_time_windowQuery

OBJECTS=TempRaster_QuadComp.o

%.o: %.cpp
	$(CPP) $(PREFLAGS) -c $< -o $@ $(POSFLAGS)

all: bin

bin: $(OBJECTS) $(BINS)

TRQC_load_trqc:
	$(CPP) $(PREFLAGS) -o $@ $@.cpp $(OBJECTS) $(POSFLAGS)

TRQC_nasa_build_from_bin:
	$(CPP) $(PREFLAGS) -o $@ $@.cpp $(OBJECTS) $(POSFLAGS)

TRQC_nasa_to_bin:
	$(CPP) -o $@ $@.cpp

TRQC_print_getSerie:
	$(CPP) $(PREFLAGS) -o $@ $@.cpp $(OBJECTS) $(POSFLAGS)

TRQC_time_accessQuery:
	$(CPP) $(PREFLAGS) -o $@ $@.cpp $(OBJECTS) $(POSFLAGS)

TRQC_time_getSerieQuery:
	$(CPP) $(PREFLAGS) -o $@ $@.cpp $(OBJECTS) $(POSFLAGS)

TRQC_time_windowQuery:
	$(CPP) $(PREFLAGS) -o $@ $@.cpp $(OBJECTS) $(POSFLAGS)

clean:
	rm -f $(BINS) $(OBJECTS)

compile: clean all
