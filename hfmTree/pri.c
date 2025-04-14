#include <stdio.h>

void pri(const char *filename) {
    FILE *in = fopen(filename, "rb");      // 打开编码文件 CodeFile
    FILE *out = fopen("CodePrin", "w");    // 打开输出文件 CodePrin
    if (!in || !out) {
        perror("File open error");
        return;
    }

    int count = 0;
    int byte;
    while ((byte = fgetc(in)) != EOF) {
        for (int i = 7; i >= 0; --i) {
            char bit = (byte & (1 << i)) ? '1' : '0';
            putchar(bit);         // 显示在终端
            fputc(bit, out);      // 写入 CodePrin
            count++;
            if (count % 50 == 0) {
                putchar('\n');
                fputc('\n', out);
            }
        }
    }

    // 结束时如果最后一行不足50个字符，手动换行
    if (count % 50 != 0) {
        putchar('\n');
        fputc('\n', out);
    }

    fclose(in);
    fclose(out);
}