#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <hiredis/hiredis.h>

int main(int argc, char **argv)
{
    const char *hostname = (argc > 1) ? argv[1] : "redis";
    unsigned int is_unix = 0;
    int port = 6379;
    if (argc > 2)
    {
        if (*argv[2] == 'u' || *argv[2] == 'U')
        {
            is_unix = 1;
            /* in this case, host is the path to the unix socket */
            printf("Will connect to unix socket @%s\n", hostname);
        }
        else
        {
            port = atoi(argv[2]);
        }
    }

    struct timeval timeout = {1, 500000}; // 1.5 seconds
    redisContext *c;

    if (is_unix)
    {
        c = redisConnectUnixWithTimeout(hostname, timeout);
    }
    else
    {
        c = redisConnectWithTimeout(hostname, port, timeout);
    }

    if (c == NULL || c->err) {
        if (c) {
            printf("Connection error: %s\n", c->errstr);
            redisFree(c);
        } else {
            printf("Connection error: can't allocate redis context\n");
        }
        return EXIT_FAILURE;
    }


    /* PING server */
    auto reply = redisCommand(c,"PING");
    printf("PING: %s\n", static_cast<redisReply *>(reply)->str);
    freeReplyObject(reply);

    /* Disconnects and frees the context */
    redisFree(c);

    return EXIT_SUCCESS;
}