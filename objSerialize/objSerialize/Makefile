FLAGS = -s EXPORTED_FUNCTIONS="['_readMeshFromUrl','_readMesh']" -o /Users/yd/Desktop/ObjSerializer/DataController.js -s DEMANGLE_SUPPORT=1 -s ALLOW_MEMORY_GROWTH=1 -O3 -s AGGRESSIVE_VARIABLE_ELIMINATION=1 -s PRECISE_F32=1 --pre-js ../module.js

DataController: objSerializer.c
	emcc objSerializer.c $(FLAGS)
