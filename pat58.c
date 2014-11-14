#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

int main()
{
    int ag, as, ak, bg, bs, bk, cg, cs, ck;
    char ch1, ch2;
    scanf("%d%c%d%c%d", &ag, &ch1, &as, &ch2, &ak);
    scanf("%c%d%c%d%c%d", &ch1, &bg, &ch2, &bs, &ch1, &bk);

    ck = (ak + bk) % 29;
    cs = (as + bs + (ak + bk) / 29) % 17;
    cg = (ag + bg + (as + bs) / 17);

    printf("%d.%d.%d\n", cg, cs, ck);
    return 0;
}

