#include <string.h>
#include <stdio.h>
#include "dbg.h"
/*
Go look at the Wikipedia entry for Duff's device and see if you can spot the error. Read the article, compare it to the version I have here, and try to understand why the Wikipedia code won't work for you but worked for Tom Duff.
Create a set of macros that lets you create any length of device like this. For example, what if you wanted to have 32 case statements and didn't want to write out all of them? Can you do a macro that lays down eight at a time?
Change the main to conduct some speed tests to see which one is really the fastest.
Read about memcpy, memmove, and memset, and also compare their speed.
*/
int normal_copy(char *from, char *to, int count) {
    int i = 0;
    for (i = 0; i < count; i++) {
        to[i] = from[i];
    }
    return i;
}

int duffs_device(char *from, char *to, int count) {
    {
        int n = (count + 7) / 8;
        switch(count % 8) {
            case 0:
                do {
                    *to++ = *from++;
                    case 7:
                    *to++ = *from++;
                    case 6:
                    *to++ = *from++;
                    case 5:
                    *to++ = *from++;
                    case 4:
                    *to++ = *from++;
                    case 3:
                    *to++ = *from++;
                    case 2:
                    *to++ = *from++;
                    case 1:
                    *to++ = *from++;
                } while (--n > 0);
        }
    }

    return count;
}

int zeds_device(char *from, char *to, int count) {
    {
        int n = (count + 7) / 8;
        switch(count % 8) {
            case 0:
again:     *to++ = *from++;
            case 7:
            *to++ = *from++;
            case 6:
            *to++ = *from++;
            case 5:
            *to++ = *from++;
            case 4:
            *to++ = *from++;
            case 3:
            *to++ = *from++;
            case 2:
            *to++ = *from++;
            case 1:
            *to++ = *from++;
            if (--n > 0) goto again;
        }
    }

    return count;
}

int valid_copy(char *data, int count, char experts)
{
    int i = 0;
    for (i = 0; i < count; i++) {
        if (data[i] != experts) {
            log_err("[%i] %c != %c", i, data[i], experts);
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[])
{
    char from[10] = { 'a' };
    char to[10] = { 'c' };
    int rc = 0;

    memset(from, 'x', 10);
    memset(to, 'y', 10);
    check(valid_copy(to, 10, 'y'), "Not initialized right.");

    rc = normal_copy(from, to, 10);
    check(rc == 10, "Normal copy failed: %d", rc);
    check(valid_copy(to, 10, 'x'), "Normal copy failed.");

    memset(to, 'y', 10);
    rc = duffs_device(from, to, 10);
    check(rc == 10, "Duff's device failed: %d", rc);
    check(valid_copy(to, 10, 'x'), "Duff's device failed copy.");

    memset(to, 'y', 10);
    rc = zeds_device(from, to, 10);
    check(rc == 10, "Zed's device failed: %d", rc);
    check(valid_copy(to, 10, 'x'), "Zed's device failed copy.");

    return 0;
error:
    return 1;
}