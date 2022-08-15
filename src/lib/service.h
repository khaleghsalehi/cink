//
// Created by khalegh on 8/15/22.
//

#ifndef CINK2_SERVICE_H
#define CINK2_SERVICE_H

#include <sys/types.h>
#include <unistd.h>
#include <syslog.h>
#include <stdlib.h>
#include <sys/stat.h>

static int init_background_service() {
    pid_t process_id = 0;
    pid_t sid = 0;
    process_id = fork();
    if (process_id < 0) {
        syslog(LOG_ERR, "fork failed!");
        exit(1);
    }
    if (process_id > 0) {
        syslog(LOG_NOTICE, "child process uuid ->  %d", process_id);
        exit(0);
    }
    umask(0);
    sid = setsid();
    if (sid < 0) {
        exit(1);
    }
    chdir("/");
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    syslog(LOG_NOTICE, "start cink service.");
    return 0;
}

#endif //CINK2_SERVICE_H
