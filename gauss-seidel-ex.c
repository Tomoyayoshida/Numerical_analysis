#include<stdio.h>

double get_x1(double x2,double x3)
{
	return((10.0-x2-x3)/5.0);
}

double get_x2(double x1,double x3)
{
	return((12.0-x1-x3)/4.0);
}

double get_x3(double x1,double x2)
{
	return((13.0-2.0*x1-x2)/3.0);
}

double fabs(double x)//絶対値表現を行うための関数
{
	if(x > 0)
		return x;
	else
		return -x;
}

int main()
{
	double a=141,b=141,c=141,x1,x2,x3;//変化前の変数値を代入するための変数を作成(a,b,c)
	int i;

	x1 = x2 = x3 = 1.0;
	for(i=0;i<20;i++,a=x1,b=x2,c=x3)
	{
		x1 = get_x1(x2,x3);
		x2 = get_x2(x1,x3);
		x3 = get_x3(x1,x2);
		printf("[i=%d]:x1 = %.10f :x2 =%.10f :x3 = %.10f\n",i+1,x1,x2,x3);
		if((fabs(a)-fabs(x1)) < 0.00000001 && (fabs(b)-fabs(x2)) < 0.00000001 &&(fabs(c)-fabs(x3)) < 0.00000001)//任意の値で収束するようにif文を設計する
		{
			printf("convergence\n");//収束すると繰り返しが終了する
			break;
		}
	}

	return 0;
}


