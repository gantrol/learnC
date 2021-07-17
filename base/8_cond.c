#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[]) {
    /**
     * 处理命令行命令，有如下情况：
     * 1. 只有一个参数，即文件本身，那么提示用法
     * 2. 两个参数，第一个参数为-v或者-version，则显示版本信息
     * 3. 两个参数的其他情况，或者三个或四个参数，则输出参数的值
     * 4. 其他情况提示用法
     */
    char *argv1 = argv[1];
    if (argc == 2 && (strcmp(argv1, "-v") == 0 || strcmp(argv1, "-version") == 0)) {
        printf("Version 1.0\n");
    } else if (argc >= 2 && argc <= 4) {
        int i;
        for (i = 1; i < argc; i++) {
            printf("%s ", argv[i]);
        }
    } else {
        printf("Usage: %s [-v|-version|arg1] ([arg2] [arg3] [arg4])\n", argv[0]);
    }
}