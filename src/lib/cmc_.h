//
// Created by khalegh on 8/15/22.
//

#ifndef CINK2_CMC__H
#define CINK2_CMC__H

#include "data_strcut.h"
#include <stdlib.h>
#include <string.h>

/**
 *  get (k,v) and persist in cache
 * @param key
 * @param value
 * @param time_stamp
 */
void put( char *key, char *value, long time_stamp) {
    struct object *new_entry = (struct object *) malloc (sizeof(struct object));
    strncpy(new_entry->key,key,512);
    strncpy(new_entry->value,value,1024*2);
    new_entry->timestamp=time_stamp;
    new_entry->next = object_head;
    object_head = new_entry;
}



/**
 *  lookup key and return value from cache
 * @param key
 * @return
 */
char* get( char key[512]) {
    object_ptr=object_head;
    while(object_ptr!=NULL) {
        if (strcmp(object_ptr->key,key)==0) {
            return object_ptr->value;
        }
        object_ptr=object_ptr->next;
    }
}


#endif //CINK2_CMC__H
