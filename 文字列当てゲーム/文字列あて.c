#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void makestr(int num);  // 文字列作成
// numはmadestr関数の引数
int strcheck(char* str2);// 文字列確認(文字)
//str2はstrcheckの引数
int lencheck(char* lenstr);// 文字列確認(長さ)
//lenstrはlencheckの引数
char str[1000];     //作成された文字列用配列
char Anser[1000]; //ユーザーの決めた文字列用配列
int len, len2;  // lenは作成された文字列の長さ。len2は作成された文字列の長さ-ユーザーが決めた文字列の長さ

void main()
{
    char Enter[700];
    int n;
    printf("文字列あてゲーム\n");
    printf("今から英単語を使っての文字列を作ります。Enterキーを押してください。\n");
    gets(Enter);
    srand(time(NULL));
    n = rand() % 10 + 1;
    makestr(n);
    printf("文字列が作成されました。ゲームを開始しましょう。Enterキーを押してください。\n");
    gets(Enter);
    printf("ゲーム開始、作成された単語を推測し入力してください。\n");
    while (1)
    {
        scanf("%s", Anser);
        printf("%sですね!さて結果は...\n", Anser);
        printf("文字列の長さの違い(余り)...%d\n", lencheck(Anser));
        printf("文字列の適合...\n");
        n = strcheck(Anser);
        if (n == 1){
            printf("おめでとうございます！見事隠された文字列%sを見つけられました!\n", str);
            exit(0);
        } else {
            printf("残念でした!再トライ!!\n");
        }
    }


}

void makestr(int num)
{
    if (num == 1){
        strcpy(str, "bike");
        len = 4;
    } else if (num == 2){
        strcpy(str, "left");
        len = 4;
    } else if (num == 3){
        strcpy(str, "right");
        len = 5;
    } else if (num == 4){
        strcpy(str, "win");
        len = 3;
    } else if (num == 5){
        strcpy(str, "computer");
        len = 8;
    } else if (num == 6){
        strcpy(str, "list");
        len = 4;
    } else if (num == 7){
        strcpy(str, "japan");
        len = 5;
    } else if (num == 8){
        strcpy(str, "shrine");
        len = 6;
    } else if (num == 9){
        strcpy(str, "copy");
        len = 4;
    } else if (num == 10){
        strcpy(str, "number");
        len = 6;
    }
}

int lencheck(char* lenstr)
{
    int checklen;
    checklen = strlen(lenstr);
    len2 = checklen - len;

    return len2;
}

int strcheck(char* str2)
{
    char* p = str;
    int i, j, m;
    int n = 0;
    char b;
    m = strlen(str2);
    for (i = 1; i <= m; i++){
        j = i - 1;
        b = str2[j];
        printf("隠された文字列の中から%cを探します\n", b);
        while (1)
        {
            p = strchr(p, b);
            if(!p)
            break;
            printf("%d文字目で発見しました。\n", p-str+1);
            n++;
            p++;
        }
        if (n == 0){
            printf("1つも見つかりませんでした\n\n");
        } else if (n == len){
            return 1;
        } else {
            printf("全部で%d個見つかりました\n\n", n);
        }
        p = str;
    }
    return 0;
}