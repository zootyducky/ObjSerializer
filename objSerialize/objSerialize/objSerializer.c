//
//  objSerializer.c
//  objSerialize
//
//  Created by ChoYoungDae on 12/24/15.
//  Copyright © 2015 ChoYoungDae. All rights reserved.
//

#include "objSerializer.h"


float ** readMesh(char * filePath){
    printf("filePath : %s\n",filePath);
    int i = 0;
    FILE * fp;
    uint16_t vertCount;
    uint16_t triCount;
    uint8_t format;

    
    float ** result = (float **)malloc(sizeof(float*)*5);
    float * verts;
    float * normals;
    float * tangents;
    float * uvs;
    float * tris;
    

    fp = fopen(filePath, "rb");
    if (fp){
        fread(&vertCount, sizeof(uint16_t), 1, fp);
        fread(&triCount, sizeof(uint16_t), 1, fp);
        fread(&format, sizeof(uint8_t), 1, fp);
        printf("vertCount = %u\n",vertCount);
        printf("triCount = %u\n",triCount);
        printf("format = %d\n",format);
        
        if(vertCount < 0 || vertCount > 65535){
            printf("Invalid vertex count in the mesh data!\n");
            return -1;
        }
        if(triCount < 0 || vertCount > 65535){
            printf("Invalid triangle count in the mesh data!\n");
            return -1;
        }
        if(format < 1 || (format&1) == 0 || format > 15){
            printf("Invalid vertex format in the mesh data!\n");
            return -1;
        }
        
        
        //var mesh = new Mesh(); //emscripten으로 Three.js obj만드는부분
        
        verts = malloc(sizeof(float)*vertCount*3);
        result[0] = verts;
        readVector3Array16bit(&verts, fp, vertCount);

        //mesh.vertices = verts
        
        if(format & 2){ //have normals
            normals = malloc(sizeof(float)*vertCount*3);
            result[1] = normals;
            readVector3ArrayBytes(&normals, fp, vertCount);
        }
        
        if(format & 4){ //have tangents
            tangents  = malloc((sizeof(float)*vertCount*4));
            result[2] = tangents;
            readVector4ArrayBytes(&tangents, fp, vertCount);
        }
        
        if(format & 8){ // have uvs
            uvs = malloc(sizeof(float)*vertCount*2);
            result[3] = uvs;
            readVector2Array16bit(&uvs, fp, vertCount);
        }

        //triangle indices
        tris = malloc(sizeof(int)*triCount*3);
        result[4] = tris;
        for( i = 0 ; i < triCount ; i++){
            fread(&(tris[i*3+0]), sizeof(uint16_t), 3, fp);
        }

        
        
        fclose(fp);
    }
    else{
        printf("Can't read the file!\n");
        return -1;
    }
    return result;
}

int readVector2Array16bit (float ** arr, FILE * fp, int arrLength){
    if(fp  == NULL){
        return -1;
    }
    float bminX, bmaxX;
    float bminY,bmaxY;
    
    uint16_t is[2];
    float xx, yy;
    int i = 0;
    
    fread(&bminX, sizeof(float), 1, fp);
    fread(&bmaxX, sizeof(float), 1, fp);
    fread(&bminY, sizeof(float), 1, fp);
    fread(&bmaxY, sizeof(float), 1, fp);
    
    for( ; i < arrLength ; i++){
        fread(is, sizeof(uint16_t), 3, fp);
        xx = is[0] / 65535.0 * (bmaxX -bminX) + bminX;
        yy = is[1] / 65535.0 * (bmaxY -bminY) + bminY;

        (*arr)[i*2 + 0] = xx;
        (*arr)[i*2 + 1] = yy;
    }
    
    
    
    return 0;
}


int readVector3Array16bit (float ** arr, FILE * fp, int arrLength){
    if(fp  == NULL){
        return -1;
    }
    float bminX, bmaxX;
    float bminY,bmaxY;
    float bminZ,bmaxZ;
    
    uint16_t is[3];
    float xx, yy, zz;
    int i = 0;
    
    fread(&bminX, sizeof(float), 1, fp);
    fread(&bmaxX, sizeof(float), 1, fp);
    fread(&bminY, sizeof(float), 1, fp);
    fread(&bmaxY, sizeof(float), 1, fp);
    fread(&bminZ, sizeof(float), 1, fp);
    fread(&bmaxZ, sizeof(float), 1, fp);
    
    for( ; i < arrLength ; i++){
        fread(is, sizeof(uint16_t), 3, fp);
        xx = is[0] / 65535.0 * (bmaxX -bminX) + bminX;
        yy = is[1] / 65535.0 * (bmaxY -bminY) + bminY;
        zz = is[2] / 65535.0 * (bmaxZ -bminZ) + bminZ;
        
        (*arr)[i*3 + 0] = xx;
        (*arr)[i*3 + 1] = yy;
        (*arr)[i*3 + 2] = zz;
    }
    
    return 0;
}


int readVector3ArrayBytes (float ** arr, FILE * fp, int arrLength){
    if(fp == NULL){
        return -1;
    }
    int is[3];
    float xx, yy, zz;
    for(int i = 0 ; i < arrLength ; i++){
        fread(is, sizeof(uint32_t), 3, fp);
        xx = (is[0] - 128.0) / 127.0;
        yy = (is[1] - 128.0) / 127.0;
        zz = (is[2] - 128.0) / 127.0;
        
        (*arr)[i*3 + 0] = xx;
        (*arr)[i*3 + 1] = yy;
        (*arr)[i*3 + 2] = zz;
    }
    return 0;
}

int readVector4ArrayBytes (float ** arr, FILE * fp, int arrLength){
    if(fp == NULL){
        return -1;
    }
    int is[4];
    float xx, yy, zz, ww;
    for(int i = 0 ; i < arrLength ; i++){
        fread(is, sizeof(uint32_t), 3, fp);
        xx = (is[0] - 128.0) / 127.0;
        yy = (is[1] - 128.0) / 127.0;
        zz = (is[2] - 128.0) / 127.0;
        ww = (is[3] - 128.0) / 127.0;
        
        (*arr)[i*3 + 0] = xx;
        (*arr)[i*3 + 1] = yy;
        (*arr)[i*3 + 2] = zz;
        (*arr)[i*3 + 3] = ww;
    }
    return 0;
}
