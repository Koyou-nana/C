#include <stdio.h>
#include <string.h>		// 文字列操作関数

void main()
{
	char str1[] = "Koyou";
	char str2[] = "nana";
	char str3[256];
	int n;

	printf("str1 = %s\n", str1);
	printf("str2 = %s\n", str2);

	strcpy(str3, str1);			// str3へstr1をコピーする
	printf("str3 = %s\n", str3);

	strcat(str3, str2);			// str3の末尾にstr2を連結する
	printf("str3 = %s\n", str3);

	printf("文字列を入力：");
	scanf("%s", str3);			// キーボードから入力した文字列をstr3に格納する
	printf("str3 = %s\n", str3);// 以前のstr3の内容は上書きされる

	n = strlen(str3);			// str3の長さを計算する
	printf("str3の長さ = %d\n", n);

	n = strcmp(str1, str3);		// str1とstr3を比較する。
	printf("str1とstr3の比較 = %d\n", n);

}