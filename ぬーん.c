#include <stdio.h> // scanf関数やprintf関数を使うため
#include <stdlib.h> //exit関数を使うため
void main()
{
	char o;
	int x, y, s;
	printf("ope?");
	scanf("%c", &o);	// キーボードからoに演算子を入力する
	printf("x=?");
	scanf("%d", &x);	// キーボードからxに整数を入力する
	printf("y=?");
	scanf("%d", &y);	// キーボードからyに整数を入力する

	if (o == '+') {        // 演算子が+の場合
		s = x + y;
	}
	else if (o == '-') {   // 演算子が-の場合
		s = x - y;
	}
	else if (o == '*') {   // 演算子が*の場合
		s = x * y;
	}
	else if (o == '/') {   // 演算子が/の場合
		s = x / y;
	}
	else if (o == '%') {   // 演算子が上記以外の場合
		s = x % y;
	}
	else {
		printf("演算子が間違っています。");
		exit(0);
	}

	printf("%d %c %d = %d", x, o, y, s);
}