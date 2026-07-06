#include <cstdio>
#include <cstring>
#define maxl 1000
int n, a[maxl], l;
char m[maxl], dm[maxl];
void plus()
{
    for (int i = 0; i < l; i++)
        dm[l - i - 1] = m[i];
    l++;
    for (int i = 0; i < l; i++)
    {
        m[i] += dm[i];
        if (m[i] >= n)
            m[i + 1]++, m[i] -= n;
    }
    while (!m[l - 1])
        --l;
    return;
}
bool hw()
{
    for (int i = 0; i < l; i++)
        if (m[i] != m[l - 1 - i])
            return 0;
    return 1;
}
int main()
{
    scanf("%d%s", &n, m);
    l = strlen(m);
    for (int i = 0; i < l; i++)
        if (m[i] >= '0' && m[i] <= '9')
            m[i] -= '0';
        else
            m[i] = m[i] - 'A' + 10;
    int step = 0;
    while (!hw())
    {
        step++;
        if (step > 30)
            break;
        plus();
    }
    if (step <= 30)
        printf("STEP=%d\n", step);
    else
        puts("Impossible!");
    return 0;
}
