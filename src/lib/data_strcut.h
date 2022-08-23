//
// Created by khalegh on 8/15/22.
//

#ifndef CINK2_DATA_STRCUT_H
#define CINK2_DATA_STRCUT_H

int MAX_KEY_SIZE = 512;
int MAX_VALUE_SIZE = 1024*2;

struct object {
    char key[512];
    char value[1024*2];
    long ttl;
    long ts;
    struct object *next;

};
struct object *object_head=NULL;
struct object *object_ptr=NULL;
struct object *ptr = NULL;
struct object *head = NULL;

#endif //CINK2_DATA_STRCUT_H
