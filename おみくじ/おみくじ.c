#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char result[1000];

char* omikuzi(void);

void main()
{
	char str[1000];
	char name[1000];
	printf("あなたの名前、もしくはニックネームをスペースなしで入力してください。(スペースが入るとそこから後ろは無視されます。)\n入力されたデータはこのプログラムでのみ使用されます。\n");
	scanf("%s", name);
	printf("\n");
	printf("ようこそおいでくださいました%s様。ここでは御神籤(おみくじ)を引くことができます。早速引いてみましょう。Enterキーを押してください\n", name);
	gets_s(str);
	gets_s(str); //scanfの影響か1つめのgets_sが飛ばされるので2つ。
	printf("結果が出ました。%s様の結果は、%sです。ちなみにこのプログラムに凶などのものはありませんご安心を。\nEnterキーを押すと終了します。\n", name, omikuzi());
	gets_s(str);
}

char* omikuzi(void)
{
	int a;
	srand(time(NULL));
	a = rand() % 10 + 1;
	if (a <= 3) {
		strcpy(result, "小吉");
	}
	else if (a <= 6) {
		strcpy(result, "中吉");
	}
	else {
		strcpy(result, "おめでとうございます。大吉");
	}

	return result;
}