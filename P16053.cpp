#include <iostream>
using namespace std;
int main()
{
    int n;
    char word[15];
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int now = (i % 2) ? 1 : 6, half = i + 1 >> 1;
        while (!(half % 26))
            now++, half /= 26;
        word[now] += 1, word[now] %= 26;
        for (int i = 1; i <= 10; ++i)
            cout << char(word[i] + 'a');
        puts("");
    }
    return 0;
}
