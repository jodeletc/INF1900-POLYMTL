# Nom de la bibliothèque
LIBNAME = libstatique.a

# Répertoire des headers
INCDIR = .

# Compilateur et options
CC = avr-gcc
CFLAGS = -I$(INCDIR) -c

# Commande 'ar' et options
AR = avr-ar
ARFLAGS = crs

# Liste des fichiers sources et objets
SOURCES = LED.cpp Timer.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(LIBNAME)

$(LIBNAME): $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(LIBNAME)

.PHONY: all clean
