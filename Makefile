# Set project directory one level above of Makefile directory.
# $(CURDIR) is a GNU make variable containing the path to the current working directory
PROJDIR := $(realpath $(CURDIR))

SOURCEDIR := $(PROJDIR)/src
INCLUDEDIR := $(PROJDIR)/include
BUILDDIR := $(PROJDIR)/obj

COMPILERFLAGS := -g -Wall
LINKERFLAGS := -lsfml-graphics -lsfml-window -lsfml-system

# Name of the final executable
TARGET = main

# Create the list of directories
DIRS = Behaviors Controller Model View Utility
SOURCEDIRS = $(foreach dir, $(DIRS), $(addprefix $(SOURCEDIR)/, $(dir)))
TARGETDIRS = $(foreach dir, $(DIRS), $(addprefix $(BUILDDIR)/, $(dir)))

# Generate the GCC includes parameters by adding -I before each source folder
INCLUDES = $(foreach dir, $(DIRS), $(addprefix -I$(INCLUDEDIR)/, $(dir)))

# Add this list to VPATH, the place make will look for the source files
VPATH = $(SOURCEDIRS)

# Create a list of *.cpp sources in DIRS
SOURCES = $(foreach dir,$(SOURCEDIRS),$(wildcard $(dir)/*.cpp))

# Define objects for all sources
OBJS := $(subst $(SOURCEDIR),$(BUILDDIR),$(SOURCES:.cpp=.o))

# Name the compiler
CC = g++

# OS specific part
ifeq ($(OS),Windows_NT)
    RM = del /F /Q 
    RMDIR = -RMDIR /S /Q
    MKDIR = -mkdir
    ERRIGNORE = 2>NUL || true
    SEP=\\
else
    RM = rm -rf 
    RMDIR = rm -rf 
    MKDIR = mkdir -p
    ERRIGNORE = 2>/dev/null
    SEP=/
endif

# Remove space after separator
PSEP = $(strip $(SEP))

# Define the function that will generate each rule
define generateRules
$(1)/%.o: %.cpp
	@echo Building $$@
	@$(CC) $(COMPILERFLAGS) $(LINKERFLAGS) -c $$(INCLUDES) -o $$(subst /,$$(PSEP),$$@) $$(subst /,$$(PSEP),$$<)
endef

.PHONY: all clean directories

all: directories $(TARGET)

$(TARGET): $(OBJS)
	echo Linking $@
	@$(CC) $(COMPILERFLAGS) $(LINKERFLAGS) $(OBJS) -o $(TARGET)

# Generate rules 
$(foreach targetdir, $(TARGETDIRS), $(eval $(call generateRules, $(targetdir))))

directories:
	@$(MKDIR) $(subst /,$(PSEP),$(TARGETDIRS)) $(ERRIGNORE)

# Remove all objects, dependencies and executable files generated during the build
clean:
	@$(RMDIR) $(subst /,$(PSEP),$(TARGETDIRS)) $(ERRIGNORE)
	@$(RM) $(TARGET) $(ERRIGNORE)
	@echo Cleaning done!

# Run executable
run:
	@./main