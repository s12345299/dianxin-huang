#include<stdio.h>
enum GSHz{
    GPIO_Speed_2MHz,
    GPIO_Speed_10MHz,
    GPIO_Speed_50MHz
};
struct GPIO{
enum GSHz GPIO_Speed;
};
void GPIO_Structurelinit(struct GPIO*GPIO_Initstruct){
    (*GPIO_Initstruct).GPIO_Speed=GPIO_Speed_2MHz;
}

int main()
{
    struct GPIO GPIO1;
    GPIO_Structurelinit(&GPIO1);
    return 0;
}