#include <pthread.h>
#include <stdio.h>
#include "lib/cink.h"


int main(int argc, char *argv[]) {
    pthread_t p_thread;
    int t_id = 1020;

    // here we start cink service.
    init_background_service();


    pthread_create(&p_thread, NULL, check_ttl, (void *) &t_id);


    put_ttl("12345671", "sample test here 0", 10);
    put_ttl("1234ABC2", "sample test here 1 ", 10);
    put_ttl("1234EFG3", "sample test here 2", 8);
    put_ttl("1234EFG4", "sample test here 3", 7);
    put_ttl("1234EFG41", "sample test here 3", 7);
    put_ttl("1234EFG42", "sample test here 3", 7);
    put_ttl("1234EFG43", "sample test here 3", 7);
    put_ttl("1234EFG44", "sample test here 3", 7);
    put_ttl("1234EFG45", "sample test here 3", 7);
    put_ttl("1234EFG46", "sample test here 3", 7);
    put_ttl("1234EFG5", "sample test here 3", 17);
    put_ttl("1234EFG7777", "sample test here 3", 25);
    put("data", "sample test here 3");

    syslog(LOG_NOTICE, "{%ld} key available in list", count_cache());

    syslog(LOG_NOTICE, "%s", get("1234567"));
    syslog(LOG_NOTICE, "%s", get("1234ABC"));

    del("1234567");
    del("1234ABC");

    syslog(LOG_NOTICE, "{%ld} key available in list", count_cache());
    pause();

    return 0;
}