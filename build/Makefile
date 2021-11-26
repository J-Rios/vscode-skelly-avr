
# Specify project name and default compilers
PRJ = fw_app

# Project root WorkSpace
WORKSPACE = ..

# Specify target Microcontroller
DEVICE = atmega328p

# Specify MCU CPU Frequency
F_CPU = 16000000

# Low, High and Extended Fuses Values
LFU = 0xFF
HFU = 0xDE
EFU = 0x05

# Avrdude Programmer
PROGRAMMER = usbasp

# Specify default compilers and tools
CC      = avr-gcc
CXX     = avr-g++
AVRDUDE = avrdude -c $(PROGRAMMER) -p $(DEVICE)
OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump
SIZE    = avr-size --format=avr --mcu=$(DEVICE)

#Setup libs directories to be included
LIBS = -I$(WORKSPACE)/inc
LIBS += -L$(WORKSPACE)/lib

# Setup compilation flags
CFLAGS = -Os -Wall -fstack-usage -mmcu=$(DEVICE) -DF_CPU=$(F_CPU) -g $(LIBS)
CXXFLAGS = -Os -Wall -fstack-usage -mmcu=$(DEVICE) -DF_CPU=$(F_CPU) -g $(LIBS)

# Compile instruction
COMPILE = $(CXX) $(CXXFLAGS)

###############################################################################

# Specify Build and Binary Release directories
BUILDDIR = $(WORKSPACE)/build
BINDIR = $(WORKSPACE)/bin

# Get actual date and setup output binary directory name
#DATE = $(shell date '+%Y_%m_%d_%H_%M_%S')
DATE = $(shell date '+%Y_%m_%d')
RELEASEDIR = $(WORKSPACE)/bin/$(DATE)

# Specify Sources files (Automatic search in specific directories)
SRCS  = $(shell find $(WORKSPACE)/src -type f -name *.c)
SRCS  += $(shell find $(WORKSPACE)/src -type f -name *.cpp)
SRCS  += $(shell find $(WORKSPACE)/lib -type f -name *.c)
SRCS  += $(shell find $(WORKSPACE)/lib -type f -name *.cpp)

# Specify Headers files (Automatic search in specific directories)
HEADS = $(shell find $(WORKSPACE)/inc -type f -name *.h)
HEADS += $(shell find $(WORKSPACE)/inc -type f -name *.hpp)
HEADS += $(shell find $(WORKSPACE)/lib -type f -name *.h)
HEADS += $(shell find $(WORKSPACE)/lib -type f -name *.hpp)

# Get objects files from sources and output object
_OBJS = $(SRCS:.c=.o)
OBJS = $(_OBJS:.cpp=.o)
BUILDOBJS = $(BUILDDIR)/$(shell basename $(OBJS))

###############################################################################

# Target: make all (build project generating output directory)
all: $(PRJ).hex
	rm -f ${RELEASEDIR}/*
	mkdir -p ${RELEASEDIR}
	mv $(PRJ).elf $(RELEASEDIR)
	mv $(PRJ).hex $(RELEASEDIR)

# Target: make clean (remove all previously builds)
clean:
	rm -f $(BUILDDIR)/*.o
	rm -f $(BUILDDIR)/*.su
	rm -f $(BUILDDIR)/$(PRJ).elf
	rm -f $(BUILDDIR)/$(PRJ).hex

# Target: make rebuild (clean previously builds and build again)
rebuild: clean all

# Flash program to MCU
flash: all
	$(AVRDUDE) -U flash:w:$(PRJ).hex:i

# Write fuses to MCU
fuse:
	$(AVRDUDE) -U lfuse:w:$(LFU):m -U hfuse:w:$(HFU):m -U efuse:w:$(EFU):m

# Target: check (custom target to check build variables)
check:
	@echo "HEADERS:"
	@echo "  $(HEADS)"
	@echo "SRCS:"
	@echo "  $(SRCS)"
	@echo "OBJS:"
	@echo "  $(BUILDOBJS)"
	@echo "BINDIR:"
	@echo "  $(BINDIR)"

###############################################################################

# Target for generate HEX file from .elf file
$(PRJ).hex: $(PRJ).elf
	rm -f $(PRJ).hex
	$(OBJCOPY) -j .text -j .data -O ihex $(PRJ).elf $(PRJ).hex
	$(SIZE) $(PRJ).elf

# Target for generate ELF file linking all .o files
$(PRJ).elf: $(OBJS)
	$(CC) $(CFLAGS) -o $(PRJ).elf $(BUILDOBJS)

# Target for generate object file of each .c file
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Target for generate object file of each .cpp file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<
