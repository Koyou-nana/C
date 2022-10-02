#include <stdio.h>	// scanf関数やprintf関数を使うため
#include <stdlib.h>	// exit関数を使うため
void main()
{
	char o;	// 文字型(チャー,キャラ)の変数oを宣言
	int x, y, s;	// 整数型(イント)のx,y,sを宣言
	printf("ope?");
	scanf("%c", &o);	// printf関数で質問し、その答えをscanf関数でそれぞれの変数に代入する。7～12行目まで同じ。
	printf("x=?");
	scanf("%d", &x);
	printf("y=?");
	scanf("%d", &y);

	if (o == '+') {		// if文を使って指定された演算子を確認し、それに応じた計算をし、変数sに代入する。。14～28行目まで
		s = x + y;
	}
	else if (o == '-') {
		s = x - y;
	}
	else if (o == '*') {
		s = x * y;
	}
	else if (o == '/') {
		s = x / y;
	}
	else if (o == '%') {	// %は割り算した余りを出す。
		s = x % y;
	}
	else {		// 演算子が間違っている場合の処理。演算子が間違っています。と出力し終了する。
		printf("演算子が間違っています。");
		exit(0);
	}
	printf("%d %c %d = %d", x, o, y, s);	//計算結果を出力する。
}