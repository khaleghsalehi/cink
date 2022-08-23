//
// Created by tomcat on 8/15/22.
//

#ifndef CINK2_TTL__H
#define CINK2_TTL__H

#include <syslog.h>
#include <unistd.h>
#include <pthread.h>
#include "cmc_.h"

int msleep(unsigned int tms) {
    return usleep(tms * 1000);
}

void *check_ttl() {
    for (;;) {
        head = object_head;
        ptr = object_head;
        time_t now;
        now = time(NULL);
        while (ptr != NULL) {
            syslog(LOG_NOTICE, "check -> %s", ptr->key);
            if (ptr->ttl != -1) {
                if ((now - ptr->ts) > ptr->ttl) {
                    syslog(LOG_NOTICE, "time %ld to revoke %ld  with diff %ld -> %s ", now, ptr->ts,
                           now - ptr->ts, ptr->key);
                    del(ptr->key);
                    break;
                }
            }
            ptr = ptr->next;
        }
        syslog(LOG_NOTICE, "now -> %ld , inside thread , total list count -> %ld", now, count_cache());
        msleep(500);
    }
    pthread_exit(NULL);
}

#endif //CINK2_TTL__H
