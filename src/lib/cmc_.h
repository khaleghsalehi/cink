//
// Created by khalegh on 8/15/22.
//

#ifndef CINK2_CMC__H
#define CINK2_CMC__H

#include "data_strcut.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int64_t count_cache() {
    int64_t count = 0;
    object_ptr = object_head;
    while (object_ptr != NULL) {
        count++;
        object_ptr = object_ptr->next;
    }
    return count;

}

void del(char *key) {
    if (strlen(key) > MAX_KEY_SIZE) {
        syslog(LOG_NOTICE, "big key size -> {%lu}, reject", strlen(key));
        return;
    }
    object_ptr = object_head;
    if (object_ptr == NULL) {
        syslog(LOG_NOTICE, "cache is null or empty");
        return;
    }
    bool is_found = false;
    while (object_ptr != NULL) {
        if (strcmp(object_ptr->key, key) == 0) {
            is_found = true;
        }
        object_ptr = object_ptr->next;
    }
    if (!is_found) {
        syslog(LOG_NOTICE, "key not found or already revoked, return");
        return;
    }
    int i = 0;
    struct object *l_ptr = object_head;
    while (l_ptr->next != NULL) {
        if (strcmp(l_ptr->key, key) == 0) {
            syslog(LOG_NOTICE, "key found at index {%d}, start to delete", i);
            break;
        }
        i++;
        l_ptr = l_ptr->next;
    }
    // lets delete node(i)
    {
        struct object *temp = object_head;
        if (i == 0) {
            syslog(LOG_NOTICE, "key matched at the head of list -> {%d}", i);
            object_head = temp->next; // Advancing the head pointer
            temp->next = NULL;
            free(temp); // Node is deleted
        } else {
            syslog(LOG_NOTICE, "key matched at the index of -> {%d}", i);
            for (int j = 0; j < i - 1; ++j) {
                temp = temp->next;
            }
            struct object *del = temp->next;
            temp->next = temp->next->next;
            del->next = NULL;
            free(del);
        }
    }
}


/**
 *  get (k,v) and persist in cache
 * @param key
 * @param value
 * @param time_stamp
 */
void put(char *key, char *value, long time_stamp) {
    if (strlen(key) > MAX_KEY_SIZE) {
        syslog(LOG_NOTICE, "big key size -> {%lu}, reject", strlen(key));
        return;
    }
    syslog(LOG_NOTICE, "try to add {%s}", key);
    del(key);
    struct object *new_entry = (struct object *) malloc(sizeof(struct object));
    strncpy(new_entry->key, key, MAX_KEY_SIZE);
    strncpy(new_entry->value, value, MAX_VALUE_SIZE);
    new_entry->timestamp = time_stamp;
    new_entry->next = object_head;
    object_head = new_entry;
}


/**
 *  lookup key and return value from cache
 * @param key
 * @return
 */
char *get(char key[MAX_KEY_SIZE]) {
    if (strlen(key) > MAX_KEY_SIZE) {
        syslog(LOG_NOTICE, "big key size -> {%lu}, reject", strlen(key));
        return NULL;
    }
    object_ptr = object_head;
    while (object_ptr != NULL) {
        if (strcmp(object_ptr->key, key) == 0) {
            return object_ptr->value;
        }
        object_ptr = object_ptr->next;
    }
}


#endif //CINK2_CMC__H
