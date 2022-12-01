#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int n;

char comresult[1000];

char result[1000];

char* zixyannkenn(void);

char* zixyannkenn2(int num, int num2);

void main()
{
    int player;
    printf("じゃんけんの手を選択してください。\n1:グー 2:チョキ 3:パー：");
    scanf("%d", &player);
    if (player < 1 || player > 3){
        printf("間違った選択です。");
        exit(1);
    }
    printf("相手の手は%sです。%sです。", zixyannkenn(), zixyannkenn2(player, n));
}

char* zixyannkenn(void)
{
    srand(time(NULL));
    n = rand() % 3 + 1;
    if (n == 1){
        strcpy(comresult, "グー");
    } else if (n == 2){
        strcpy(comresult, "チョキ");
    } else if (n == 3){
        strcpy(comresult, "パー");
    } else {
        strcpy(comresult, "error");
    }

    return comresult;
}

char* zixyannkenn2(int num, int num2)
{
    int gameresult;

    gameresult = (num2 - num + 3) % 3;

    if (gameresult == 0){
        strcpy(result, "あいこ");
    } else if (gameresult == 1){
        strcpy(result, "あなたの負け");
    }else if (gameresult == 2){
        strcpy(result, "あなたの勝ち");
    } else {
        strcpy(result, "{error:gameresult}申し訳ございません。問題が発生しました。");
    }

    return result;
}