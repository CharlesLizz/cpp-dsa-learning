/*
常见数据类型：

基本类型：字符型、整型、浮点类型、布尔类型

枚举：enum
空类型：void

派生类型：
指针（*）
数组（[]）
结构体（struct）
共用体（union）
函数
*/


#include <stdio.h>
#include <stdbool.h>


int main() {

    /*
    ==============================
    字符、字符串以及 ASCII
    ==============================

    printf() —— 输出
    %c —— char —— 字符
    %d —— decimal —— 十进制整数
    %s —— string —— 字符串
    %f —— float —— 浮点数
    %p —— pointer —— 指针/地址

    scanf() —— 输入
    getchar() —— 读取一个字符
    putchar() —— 输出一个字符

    文件操作：
    fopen()
    fclose()
    fread()
    fwrite()
    fprintf()
    fscanf()
    */

    //printf("Hello C\n");

    /*
    printf()
    引用自 stdio.h
    */

    //printf("%c\n", 'A');
    //printf("%c\n", 65);


    /*
    ==============================
    常见数据类型
    ==============================
    */

    // 字符
    signed char ch = 'A';       // 有符号 char：负数、0、正数
    // signed 可以省略
    unsigned char ch2 = 'B';    // 无符号 char：0、正数


    // 整型
    short sh = 10;
    int i = 10;
    long la = 100;
    long long lla = 100000;


    // 浮点
    float f = 12.5;
    double d = 12.5;
    long double ld = 12.5;


    // 布尔
    _Bool flg = true;

    if (flg) {
        printf("this is true!\n");
    }
    else {
        printf("false!\n");
    }


    return 0;
}


/*
总结：

1. 字符和字符串不是一回事

'A'     → 字符
"ABC"   → 字符串


2. 字符串的结束标志为 \0

例如：

"ABC"

实际存储形式可以理解为：

'A' 'B' 'C' '\0'


3. ASCII

'A' = 65
'a' = 97
'0' = 48

A-Z 大写字母与对应的小写字母 ASCII
编码相差 32。

0-31 为 ASCII 中的控制字符，
其中很多字符是不可打印的。
*/