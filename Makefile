# Define compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++11

# List of object files
OBJ = main.o Farm.o Market.o Inventory.o Crop.o CropAsset.o

# Target executable
farmSim: $(OBJ)
	$(CXX) $(CXXFLAGS) -o farmSim $(OBJ)

# Compile source files into object files
main.o: main.cpp Farm.h Market.h Inventory.h FarmAsset.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Farm.o: Farm.cpp Farm.h Crop.h Inventory.h FarmAsset.h
	$(CXX) $(CXXFLAGS) -c Farm.cpp

Market.o: Market.cpp Market.h Inventory.h FarmAsset.h
	$(CXX) $(CXXFLAGS) -c Market.cpp

Inventory.o: Inventory.cpp Inventory.h FarmAsset.h
	$(CXX) $(CXXFLAGS) -c Inventory.cpp

Crop.o: Crop.cpp Crop.h FarmAsset.h
	$(CXX) $(CXXFLAGS) -c Crop.cpp

CropAsset.o: CropAsset.cpp CropAsset.h FarmAsset.h
	$(CXX) $(CXXFLAGS) -c CropAsset.cpp

# Clean rule to remove compiled files
clean:
	rm -f *.o farmSim
