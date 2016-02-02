//
//  objSerializer.h
//  objSerialize
//
//  Created by ChoYoungDae on 12/24/15.
//  Copyright © 2015 ChoYoungDae. All rights reserved.
//

#ifndef objSerializer_h
#define objSerializer_h

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <emscripten.h>
#endif /* objSerializer_h */


//EM_ASM_ARGS({ my_js_fn($0, $1); }, i, max);
void onLoadCallback(void * arg, char * file);
void onErrorCallback(void * arg, int status);
void onProgressCallback(void * arg, int status);
int readMeshFromUrl(char * url, char * fileName, int idx);
void readMesh(char * filePath, int idx);
int readVector2Array16bit (float ** arr, FILE * fp, int arrLength);
int readVector3Array16bit (float ** arr, FILE * fp, int arrLength);
int readVector3ArrayBytes (float ** arr, FILE * fp, int arrLength);
int readVector4ArrayBytes (float ** arr, FILE * fp, int arrLength);