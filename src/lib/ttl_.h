//
// Created by tomcat on 8/15/22.
//

#ifndef CINK2_TTL__H
#define CINK2_TTL__H

#include <syslog.h>
#include <unistd.h>
#include <pthread.h>

void *check_ttl(void *data) {
    while (1 == 1) {
        syslog(LOG_NOTICE, "not implemented.");
        sleep(1);
    }
    pthread_exit(NULL);
}

#endif //CINK2_TTL__H
