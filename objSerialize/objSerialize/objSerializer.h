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

void successLoadMeshFromUrl(char * file);
void fail(char * file);
int readMeshFromUrl(char * url, char * fileName);
void readMesh(char * filePath);
int readVector2Array16bit (float ** arr, FILE * fp, int arrLength);
int readVector3Array16bit (float ** arr, FILE * fp, int arrLength);
int readVector3ArrayBytes (float ** arr, FILE * fp, int arrLength);
int readVector4ArrayBytes (float ** arr, FILE * fp, int arrLength);