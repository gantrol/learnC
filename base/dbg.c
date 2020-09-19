// #define NDEBUG
#include "dbg.h"
#include <stdlib.h>
#include <stdio.h>
void test_debug() {
    debug("I'am QQQ with black hair.");
    debug("I'am %d years old.", 23);
}

void test_log_err() {
    log_err("我觉得某个地方出了问题。");
    log_err("%s中有%d两个问题。", "test_log_err", 2);
}

void test_log_warn() {
    log_warn("你可以忽略这些警告");
    log_warn("能不能把这个文件给我%s.", "/etc/passwd");
}

void test_log_info() {
    log_info("例子很无聊，dummy。");
    log_info("再无聊%f次。", 6.89f);
}

int test_check(char *file_name) {
    FILE *input;
    char *block;

    block = malloc(100);
    check_mem(block);

    input = fopen(file_name, "r");
    check(input, "Failed to open %s", file_name);

    free(block);
    fclose(input);
    return 0;

error:
    if (block) free(block);
    if (input) fclose(input);
    return -1;
}

int test_sentinel(int code) {
    char *temp = malloc(100);
    check_mem(temp);

    switch(code) {
        case 1:
            log_info("sentinel成功分支");
            break;
        default:
            sentinel("sentinel失败分支");
    }

    free(temp);
    return 0;

error:
    if (temp) free(temp);
    return -1;
}

int test_check_mem()
{
    char *test = NULL;
    check_mem(test);

    free(test);
    return 1;

error:
    return -1;
}

int test_check_debug()
{
    int i = 0;
    check_debug(i != 0, "怎么是0？");

    return 0;
error:
    return -1;
}

int main(int argc, char *argv[]) {
    check(argc == 2, "Need an argument.");
    test_debug();
    test_log_err();
    test_log_warn();
    test_log_info();

    check(test_check("dbg.c") == 0, "Failed to deal with dbg.c");
    check(test_check(argv[1]) == -1, "有文件%s，请输入不存在的文件名", argv[1]);
    check(test_sentinel(1) == 0, "test_sentinel failed.");
    check(test_sentinel(100) == -1, "test_sentinel failed.");
    check(test_check_mem() == -1, "test_check_mem failed.");
    check(test_check_debug() == -1, "test_check_debug failed.");
    return 0;

error:
    return 1;
}