// 台形法

#include <stdio.h>

#define X_MIN 0.0		// 積分範囲の最小
#define X_MAX 100.0		// 積分範囲の最大
#define DIV_NUM 120		// 積分範囲の分割数

float function(float x)
{
	float result;
	result = x;			// 一次直線
	return result;
}

int main()
{
	double	integral;	// 積分結果
	double h;			// 積分範囲をn個に分割したときの値
	double x, dA;		
	int i;

	printf("積分範囲 = [%f, %f]  分割数 = %d\n", X_MIN, X_MAX, DIV_NUM);

	h = (X_MAX - X_MIN) / DIV_NUM;	// 分割幅
	integral = 0.0;					// 積分結果の変数を初期化
	x = X_MIN;						// 積分範囲の変数の初期化

	for (i = 0; i < DIV_NUM; i++)
	{
		// 微小範囲の面積Δ A
		dA = (function(x) + function(x + h)) * h / 2.0;
		integral += dA;		// Σ
		x += h;
	}

	printf("積分結果 = %lf\n", integral);
	printf("解析的に求めた結果 (底辺 100, 高さ 100の直角三角形) = %lf\n",
		(X_MAX - X_MIN) * function(X_MAX) / 2.0);

	return 0;
}