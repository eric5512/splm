COMMANDS = src/commands/init.cpp src/commands/add.cpp src/commands/collect.cpp src/commands/iterate.cpp src/commands/remove.cpp src/commands/revert.cpp src/commands/revise.cpp

INCLUDES = src/help.cpp src/serializer.cpp src/data_types/parts.cpp src/parser_helper.cpp src/command_builder.cpp src/file_helper.cpp $(COMMANDS)

OFLAGS = -Wall -Wextra

all: src/main.cpp
	g++ -std=c++11 src/main.cpp -o bin/main.exe $(INCLUDES) $(OFLAGS)