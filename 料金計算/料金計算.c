#include <stdio.h>

int price(int* num, int num2, int all);

void main()
{
    int all = 0;
    char Enter[3];
    int a[6] = {0, 0, 0, 0, 0, 0};
    int b[6] = {0, 0, 0, 0, 0, 0};
    int c[4] = {0, 0, 0, 0};
    int i = 0;
    int n;
    printf("入力方法:キーボードで対応する数字を「一つだけ」入力しEnterキーを押してください。ひとつずつ入れてください。\n");
    printf("正しく選択されていないものは後ほどスルーされるので特別な操作は必要ありません\n");
    printf("サイズを入力してください。(上限は5回までです。)選択し終わったら0を入力してください\n");
    printf("1.アイコンサイズ　2.立ち絵　3.大型イラスト\n");
    while (1)
    {
        scanf("%d", &n);
        a[i] = n;
        if (a[i] == 0){
            break;
        }
        i++;
        if (i == 5){
            printf("上限です。Enterキーを押し、次へ進んでください");
            gets(Enter);
            gets(Enter);
            break;
        }
    }
     all = price(a, 1, all);
    // ここまでがサイズ選択
    i = 0;
    printf("オプションを選択してください。(上限は5回までです。)選択し終わったら0を選択してください。\n");
    printf("1.表情差分　2.後出しリテイク\n");
    while (1)
    {
        scanf("%d", &n);
        b[i] = n;
        if (b[i] == 0){
            break;
        }
        i++;
        if (i == 5){
            printf("上限です。Enterキーを押し、次へ進んでください");
            gets(Enter);
            gets(Enter);
            break;
        }
    }
    all = price(b, 2, all);
    // ここまでがオプション料金
    i = 0;
    printf("割引を入力してください。(上限は3回までです。)選択し終わったら0を選択してください。\n");
    printf("1.お得意様割引　2.お祝い割　3.中途割\n");
    while (1)
    {
        scanf("%d", &n);
        c[i] = n;
        if (c[i] == 0){
            break;
        }
        i++;
        if (i == 3){
            printf("上限です。Enterキーを押し、次へ進んでください");
            gets(Enter);
            gets(Enter);
            break;
        }
    }
    price(c, 3, all);
    // ここまでが割引料金
}

int price(int* num, int num2, int all)
{
    int a;
    int ok = 0;
    int i = 0;
    if (num2 == 1)
    {
        while (i < 5)
        {
            a = num[i];
            switch (a)
            {
            case 1:
                all += 2000;
                break;
            case 2:
                all += 3000;
                break;
            case 3:
                all += 5000;
                break;
            case 0:
                ok = 1;
                break;
            default:
                printf("%d番目の入力が誤っています(無視されます)※注意,番号は0から始まります\n", i);
                break;
            }
            if (ok == 1)
                {
                    printf("現在の値段%7d円\n", all);
                    break;
                }
             i++;
        } // 次のif文の最初の}までがサイズの料金計算。
        return all;
    } else if (num2 == 2)
    {
        while (i < 5)
        {
            a = num[i];
            switch (a)
            {
                case 1:
                    all += 1500;
                    break;
                case 2:
                    all += 1500;
                    break;
                case 0:
                    ok = 1;
                    break;
                default:
                    printf("%d番目の入力が誤っています(無視されます)※注意,番号は0から始まります\n", i++);
                    i--;
                    break;
            }
            if (ok == 1)
                {
                    printf("現在の値段%7d円\n", all);
                    break;
                }
             i++;
        }// 次のif文の最初の}までがオプションの料金計算。
        return all;
    } else if (num2 == 3)
    {
        while (i < 5)
        {
            a = num[i];
            switch (a)
            {
                case 1:
                    all /= 2;
                    break;
                case 2:
                    all -= 1500;
                    break;
                case 3:
                    all -= 1500;
                    break;
                case 0:
                    ok = 1;
                    break;
                default:
                    printf("%d番目の入力が誤っています(無視されます)※注意,番号は0から始まります\n", i++);
                    i--;
                    break;
            }
            if (all <= 1500)
            {
                all = 1500;
                ok = 1;
            }
            if (ok == 1)
            {
                printf("最終値段%7d円\n", all);
                break;
            }
            i++;
        }
    } // ここまでが割引計算
    return 0;
}