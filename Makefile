
CC=clang
CXX=clang++
OBJS=obj/Cosmos.o obj/CosmosQuery.o obj/DataSource/DataSource.o 
OBJS+=obj/Entity/Entity.o obj/Entity/IdentifiedEntity.o 
OBJS+=obj/Service/CosmosQueryService.o obj/Service/DefaultCosmosQueryService.o obj/Service/CosmosQueryServiceFactory.o
MAIN=obj/main.o
TARGET=bin/Cosmos
LIBS=-lmysqlclient
CXXFLAGS=-I/usr/local/include/mysql -Wall -pg -g3 -std=c++14
RM=rm -rf

$(TARGET): clean env bin $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

$(OBJS): obj/%.o: Cosmos/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean env run

run: clean $(TARGET)
	./$(TARGET)

env: 
	mkdir -p obj
	mkdir -p bin
	mkdir -p obj/Entity obj/Service obj/DataSource

clean:
	$(RM) obj/ bin/ugl bin/runTest

