TARGET_EXEC := audio_test


# ==== Folders ==== #
BUILD_DIR := ./build
SRC_DIRS := ./src

# ==== LIBRARIES ==== #
FTXUI := ./lib/FTXUI
FTXUI_FLAGS := \
	-L$(FTXUI)/build \
	-l:libftxui-component.a \
	-l:libftxui-dom.a \
	-l:libftxui-screen.a \
	-I$(FTXUI)/include

SFML := ./lib/SFML
SFML_FLAGS := \
	-lsfml-graphics \
	-lsfml-window \
	-lsfml-system

# ==== Files ==== #

SRCS := $(shell find $(SRC_DIRS) -name '*.cpp')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS := \
	$(INC_FLAGS) \
	$(FTXUI_FLAGS) \
	$(SFML_FLAGS) \
	-MMD \
	-MP

# ==== Build targets ==== #


$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS) $(BUILD_DIR)/assets
	@ $(CXX) $(OBJS) -o $@ $(LDFLAGS) $(CPPFLAGS)
	@ echo --linking $(TARGET_EXEC)

$(BUILD_DIR)/%.cpp.o: %.cpp
	@ mkdir -p $(dir $@)
	@ $(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@
	@ echo --compiling: $(notdir $@)

$(BUILD_DIR)/assets:
	@ cp -r assets $(BUILD_DIR)/assets


# ==== Ease of life targets ==== #

.PHONY: help
help:
	@ echo "cmd \"make\" 		builds the project"
	@ echo "cmd \"make help\" 	Shows this list"
	@ echo "cmd \"make run\" 		builds, then runs the project"
	@ echo "cmd \"make clean\" 	cleans the project"
	@ echo "cmd \"make init\" 	To initialise the project, should only be ran after the repo is cloned"

.PHONY: init
init:
	@ git submodule init
	@ git submodule update
	@ mkdir -p include
	@ mkdir -p assets
	@ mkdir -p $(FTXUI)/build
	@ cd $(FTXUI)/build && cmake .. && make
	@ mkdir -p $(SFML)/build
	@ cd $(SFML)/build && cmake .. && make

.PHONY: run
run: $(BUILD_DIR)/$(TARGET_EXEC)
	@ $(BUILD_DIR)/$(TARGET_EXEC)

.PHONY: clean
clean:
	@ rm -r $(BUILD_DIR)
	@ echo cleaning done