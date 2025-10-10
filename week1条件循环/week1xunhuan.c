#include <stdio.h>

int main()
 {
    int num;
    printf("请输入 -1, 0 或 1：\r\n");
    printf("-1为退出程序\n");
    printf(" 0为输出 helloworld\r\n");
    printf(" 1为输出 HELLOWORLD\r\n");
    while (1) {
        printf("请输入数字: ");
        scanf("%d", &num);

        if (num == -1) {
            printf("程序退出\r\n");
            break;
        }
        else if (num == 0) {
            printf("helloworld\r\n");
        }
        else if (num == 1) {
            printf("HELLOWORLD\r\n");
        }
        else {
            printf("输入无效！请只输入 -1, 0 或 1\r\n");
        }
    }
    
    return 0;
}