#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char* makestr(int num, char* str);  // 文字列作成
// numはmadestr関数の引数
int strcheck(char* str2, char* str, int len);// 文字列確認(文字)
//str2はstrcheckの引数
int lencheck(char* lenstr, int len, int len2);// 文字列確認(長さ)
//lenstrはlencheckの引数

void main()
{
    char str[1000];     //作成された文字列用配列
    char Anser[1000]; //ユーザーの決めた文字列用配列
    int len, len2;  // lenは作成された文字列の長さ。len2は作成された文字列の長さ-ユーザーが決めた文字列の長さ
    char Enter[700];
    int n;
    printf("文字列あてゲーム\n");
    printf("今から英単語を使っての文字列を作ります。Enterキーを押してください。\n");
    gets(Enter);
    srand(time(NULL));
    n = rand() % 10 + 1;
    makestr(n, str);
    len = strlen(str);
    printf("文字列が作成されました。ゲームを開始しましょう。Enterキーを押してください。\n");
    gets(Enter);
    printf("ゲーム開始、作成された単語を推測し入力してください。\n");
    while (1)
    {
        scanf("%s", Anser);
        printf("%sですね!さて結果は...\n", Anser);
        printf("文字列の長さの違い(余り)...%d\n", lencheck(Anser, len, len2));
        printf("文字列の適合...\n");
        n = strcheck(Anser, str, len);
        if (n == 1){
            printf("おめでとうございます！見事隠された文字列%sを見つけられました!\n", str);
            exit(0);
        } else {
            printf("残念でした!再トライ!!\n");
        }
    }


}

char* makestr(int num, char* str)
{
    if (num == 1){
        strcpy(str, "bike");
    } else if (num == 2){
        strcpy(str, "left");
    } else if (num == 3){
        strcpy(str, "right");
    } else if (num == 4){
        strcpy(str, "win");
    } else if (num == 5){
        strcpy(str, "computer");
    } else if (num == 6){
        strcpy(str, "list");
    } else if (num == 7){
        strcpy(str, "game");
    } else if (num == 8){
        strcpy(str, "shrine");
    } else if (num == 9){
        strcpy(str, "copy");
    } else if (num == 10){
        strcpy(str, "number");
    }

    return(str);
}

int lencheck(char* lenstr, int len, int len2)
{
    int checklen;
    checklen = strlen(lenstr);
    len2 = checklen - len;

    return len2;
}

int strcheck(char* str2, char* str, int len)
// str2=Anser(ユーザーの回答) str=str(正解) len=作成された文字列の長さ
{
    char* p = str;
    // char型ポインタに配列strのアドレスを格納
    int i, j, m;
    int n = 0;
    char b;
    m = strlen(str2);
    // 作成された文字列の長さをmに代入
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