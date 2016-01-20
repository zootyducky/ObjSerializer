//
//  main.c
//  objSerialize
//
//  Created by ChoYoungDae on 12/24/15.
//  Copyright © 2015 ChoYoungDae. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "objSerializer.h"

#define ydDataPath "/Users/yd/Desktop/ObjSerializer/objSerialize/objSerialize/objData/yd.data"
#define sampleDataPath "/Users/yd/Desktop/ObjSerializer/objSerialize/objSerialize/objData/SerializedMesh.data"
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    float ** a = readMesh(ydDataPath);
    
    printf("%f\n",a[0][0]);
    return 0;
}


