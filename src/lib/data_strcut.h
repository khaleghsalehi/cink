//
// Created by khalegh on 8/15/22.
//

#ifndef CINK2_DATA_STRCUT_H
#define CINK2_DATA_STRCUT_H

struct object {
    char key[512];
    char value[1024*2];
    long timestamp;
    struct object *next;

};
struct object *object_head=NULL;
struct object *object_ptr=NULL;

#endif //CINK2_DATA_STRCUT_H
