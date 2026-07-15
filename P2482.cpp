#include <bits/stdc++.h>
using namespace std;

int n, m;
char js[15];          // 角色：M主猪, Z忠猪, F反猪
char p[15][10005];    // 手牌
int l[15], r[15];     // 手牌左右边界（闭区间）
vector<char> dui;     // 牌堆（尾部为堆顶）
int stre[15];         // 体力值
int fro[15], nex[15]; // 双向链表，用于存活角色遍历
bool zgln[15];        // 是否装备诸葛连弩
bool tiao[15];        // 是否已跳身份（忠/反表明）
bool lei[15];         // 主猪的类反猪标记
char last_card = 'P'; // 牌堆最后一张（初始为桃，避免空堆摸到空字符）

inline char read()
{
    char ch = getchar();
    while (ch < 'A' || ch > 'Z')
        ch = getchar();
    return ch;
}

void init()
{
    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        js[i] = read();
        read(); // 跳过空格
        for (int j = 0; j < 4; ++j)
            p[i][j] = read();
        stre[i] = 4;
        l[i] = 0;
        r[i] = 3;
        fro[i] = (i == 0) ? (n - 1) : (i - 1);
        nex[i] = (i + 1) % n;
    }
    for (int i = 0; i < m; ++i)
        dui.push_back(read());
    reverse(dui.begin(), dui.end()); // 牌堆尾部为堆顶
}

int pd()
{
    bool fp_alive = false;
    for (int i = 0; i < n; ++i)
        if (js[i] == 'F' && stre[i] > 0)
        {
            fp_alive = true;
            break;
        }
    if (stre[0] <= 0)
        return 2; // FP胜
    if (!fp_alive)
        return 1; // MP胜
    return 0;     // 未结束
}

void mp(int now, int cnt)
{
    while (cnt--)
    {
        if (!dui.empty())
        {
            last_card = dui.back();
            dui.pop_back();
        }
        p[now][++r[now]] = last_card;
    }
}

void dealdead(int now, int from)
{
    // 濒死求桃
    if (stre[now] <= 0)
    {
        for (int j = l[now]; j <= r[now]; ++j)
            if (p[now][j] == 'P')
            {
                stre[now]++;
                p[now][j] = 0;
                if (stre[now] > 0)
                    break;
            }
    }
    if (stre[now] <= 0)
    {
        // 死亡处理：从存活链表中移除
        if (now != 0)
        {
            nex[fro[now]] = nex[now];
            fro[nex[now]] = fro[now];
        }
        // 奖惩：仅在游戏未结束时执行
        if (pd() == 0)
        {
            if (js[now] == 'F')
            {
                mp(from, 3);
            }
            else if (js[now] == 'Z' && js[from] == 'M')
            {
                // 主猪弃掉所有手牌和装备
                for (int j = l[from]; j <= r[from]; ++j)
                    p[from][j] = 0;
                l[from] = 0;
                r[from] = -1;
                zgln[from] = false;
            }
        }
        // 死亡猪自己的手牌全部弃置
        for (int j = l[now]; j <= r[now]; ++j)
            p[now][j] = 0;
        l[now] = 0;
        r[now] = -1;
        zgln[now] = false;
    }
}

/* ---------- 无懈可击相关函数 ---------- */
int findJ(int now)
{
    for (int i = l[now]; i <= r[now]; ++i)
        if (p[now][i] == 'J')
            return i;
    return -1;
}
void useJ(int now)
{
    int pos = findJ(now);
    if (pos != -1) p[now][pos] = 0;
}

// 判断 now 是否会对 target 使用无懈可击，isProtect=true 表示献殷勤，false 表示表敌意
bool canUseJ(int now, int target, bool isProtect)
{
    if (isProtect)
    {
        // 献殷勤：不会对未表明身份的猪（包括自己），主猪视为已表明
        if (!(tiao[target] || js[target] == 'M')) return false;
        if (js[now] == 'M')
            return (target == now) || (js[target] == 'Z' && tiao[target]);
        else if (js[now] == 'Z')
            return (target == 0) || (js[target] == 'Z' && tiao[target]);
        else if (js[now] == 'F')
            return (js[target] == 'F' && tiao[target]);
    }
    else
    {
        // 表敌意
        if (js[now] == 'M')
            return (js[target] == 'F' && tiao[target]);
        else if (js[now] == 'Z')
            return (js[target] == 'F' && tiao[target]);
        else if (js[now] == 'F')
            return (target == 0) || (js[target] == 'Z' && tiao[target]);
    }
    return false;
}

// 询问链：当前牌的使用者 user，目标 target，isProtect 表示当前牌是保护(true)还是攻击(false)
// 返回 true 表示当前牌被无懈可击抵消
bool askWJ(int user, int target, bool isProtect)
{
    if (pd() != 0) return false;
    int cur = user;
    do
    {
        if (stre[cur] <= 0) { cur = nex[cur]; continue; }
        if (findJ(cur) == -1) { cur = nex[cur]; continue; }

        bool willProtect;
        int jTarget;
        if (!isProtect)          // 当前牌是攻击（锦囊），出J是保护
        {
            willProtect = true;
            jTarget = target;
        }
        else                     // 当前牌是保护（J），出J是攻击
        {
            willProtect = false;
            jTarget = user;
        }

        if (canUseJ(cur, jTarget, willProtect))
        {
            useJ(cur);           // 弃置最左的J

            // 跳身份处理
            if (willProtect)     // 献殷勤
            {
                if (js[cur] == 'Z' && (jTarget == 0 || (js[jTarget] == 'Z' && tiao[jTarget])))
                    tiao[cur] = true, lei[cur] = false;
                else if (js[cur] == 'F' && (js[jTarget] == 'F' && tiao[jTarget]))
                    tiao[cur] = true, lei[cur] = false;
                // 主猪献殷勤不需跳身份
            }
            else                 // 表敌意
            {
                if (js[cur] == 'Z' && js[jTarget] == 'F' && tiao[jTarget])
                    tiao[cur] = true, lei[cur] = false;
                else if (js[cur] == 'F' && (jTarget == 0 || (js[jTarget] == 'Z' && tiao[jTarget])))
                    tiao[cur] = true, lei[cur] = false;
                // 主猪表敌意给已跳反猪，若目标有类反标记则清除
                if (js[cur] == 'M' && js[jTarget] == 'F' && tiao[jTarget])
                    lei[jTarget] = false;
            }

            // 递归：询问是否有人无懈可击这张J
            if (!askWJ(cur, jTarget, willProtect)) // 这张J没有被抵消 → 成功抵消当前牌
                return true;
            // 否则J被抵消，继续循环询问下一个猪
        }
        cur = nex[cur];
    } while (cur != user);
    return false;
}

/* ---------- 锦囊结算 ---------- */
void NW(int now, char KD) // 南蛮/万箭
{
    int cur = nex[now];
    while (cur != now)
    {
        if (stre[cur] <= 0) { cur = nex[cur]; continue; }

        // 无懈可击抵消此次范围伤害
        if (askWJ(now, cur, false))
        {
            cur = nex[cur];
            continue;
        }

        bool kou = true;
        for (int j = l[cur]; j <= r[cur]; ++j)
            if (p[cur][j] == KD)
            {
                p[cur][j] = 0;
                kou = false;
                break;
            }
        if (kou)
        {
            stre[cur]--;
            if (cur == 0 && !tiao[now])
                lei[now] = 1;
            dealdead(cur, now);
            if (pd()) return;
        }
        cur = nex[cur];
    }
}

void do_K(int now, int obj)
{
    // 跳身份
    if (js[now] == 'Z' && js[obj] == 'F' && tiao[obj])
        tiao[now] = true, lei[now] = false;
    if (js[now] == 'F' && (js[obj] == 'M' || (js[obj] == 'Z' && tiao[obj])))
        tiao[now] = true, lei[now] = false;

    bool kou = true;
    for (int i = l[obj]; i <= r[obj]; ++i)
        if (p[obj][i] == 'D')
        {
            p[obj][i] = 0;
            kou = false;
            break;
        }
    if (kou)
    {
        stre[obj]--;
        dealdead(obj, now);
    }
}

bool haveK(int now)
{
    for (int i = l[now]; i <= r[now]; ++i)
        if (p[now][i] == 'K')
        {
            p[now][i] = 0;
            return true;
        }
    return false;
}

void do_F(int now, int obj)
{
    // 跳身份
    if (js[now] == 'Z' && js[obj] == 'F' && tiao[obj])
        tiao[now] = true, lei[now] = false;
    if (js[now] == 'F' && (js[obj] == 'M' || (js[obj] == 'Z' && tiao[obj])))
        tiao[now] = true, lei[now] = false;

    // 无懈可击抵消决斗
    if (askWJ(now, obj, false))
        return; // 决斗无效

    bool turn = false; // false=obj先出杀
    while (true)
    {
        int cur = turn ? now : obj;
        int opp = turn ? obj : now;
        if (js[cur] == 'Z' && js[opp] == 'M')
            break;
        if (haveK(cur))
            turn = !turn;
        else
            break;
    }
    if (turn)
    {
        stre[now]--;
        dealdead(now, obj);
    }
    else
    {
        stre[obj]--;
        dealdead(obj, now);
    }
}

void cp(int now)
{
    bool usedK = false;
    int F_target = -1;
    while (pd() == 0 && stre[now] > 0)
    {
        int pos = -1;
        for (int i = l[now]; i <= r[now]; ++i)
        {
            if (p[now][i] == 0) continue;
            char c = p[now][i];
            if (c == 'P' && stre[now] < 4)
            {
                pos = i; break;
            }
            if (c == 'Z')
            {
                pos = i; break;
            }
            if (c == 'N' || c == 'W')
            {
                pos = i; break;
            }
            if (c == 'K')
            {
                int obj = nex[now];
                if (stre[obj] > 0)
                {
                    bool ok = false;
                    if (js[now] == 'M')
                        ok = (js[obj] == 'F' && tiao[obj]) || (!tiao[obj] && lei[obj]);
                    else if (js[now] == 'Z')
                        ok = (js[obj] == 'F' && tiao[obj]);
                    else if (js[now] == 'F')
                        ok = (obj == 0) || (js[obj] == 'Z' && tiao[obj]);
                    if (ok && (!usedK || zgln[now]))
                    {
                        pos = i; break;
                    }
                }
            }
            if (c == 'F')
            {
                int obj = -1;
                if (js[now] == 'M')
                {
                    for (int j = nex[now]; j != now; j = nex[j])
                    {
                        if (stre[j] <= 0) continue;
                        if ((js[j] == 'F' && tiao[j]) || (!tiao[j] && lei[j]))
                        { obj = j; break; }
                    }
                }
                else if (js[now] == 'Z')
                {
                    for (int j = nex[now]; j != now; j = nex[j])
                    {
                        if (stre[j] <= 0) continue;
                        if (js[j] == 'F' && tiao[j])
                        { obj = j; break; }
                    }
                }
                else if (js[now] == 'F')
                {
                    if (stre[0] > 0) obj = 0;
                    else
                    {
                        for (int j = nex[now]; j != now; j = nex[j])
                        {
                            if (stre[j] <= 0) continue;
                            if (js[j] == 'M' || (js[j] == 'Z' && tiao[j]))
                            { obj = j; break; }
                        }
                    }
                }
                if (obj != -1)
                {
                    pos = i;
                    F_target = obj;   // 保存目标
                    break;
                }
            }
            // 跳过 J（无懈可击不能主动使用）
        }
        if (pos == -1) break;

        char card = p[now][pos];
        p[now][pos] = 0;

        if (card == 'P')
        {
            stre[now]++;
        }
        else if (card == 'Z')
        {
            zgln[now] = true;
        }
        else if (card == 'N')
        {
            NW(now, 'K');
            if (pd()) break;
        }
        else if (card == 'W')
        {
            NW(now, 'D');
            if (pd()) break;
        }
        else if (card == 'K')
        {
            do_K(now, nex[now]);
            usedK = true;
            if (pd()) break;
        }
        else if (card == 'F')
        {
            if (F_target != -1 && stre[F_target] > 0)
            {
                do_F(now, F_target);
                if (pd()) break;
            }
            F_target = -1;
        }
    }
}

int main()
{
    init();
    for (int i = 0; pd() == 0; i = nex[i])
    {
        if (stre[i] <= 0) continue;
        mp(i, 2);
        cp(i);
    }
    printf("%s\n", pd() == 1 ? "MP" : "FP");
    for (int i = 0; i < n; ++i)
    {
        if (stre[i] <= 0)
            printf("DEAD\n");
        else
        {
            bool first = true;
            for (int j = l[i]; j <= r[i]; ++j)
                if (p[i][j] != 0)
                {
                    if (!first) printf(" ");
                    printf("%c", p[i][j]);
                    first = false;
                }
            printf("\n");
        }
    }
    return 0;
}