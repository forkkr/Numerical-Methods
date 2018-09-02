#include<bits/stdc++.h>
using namespace std;

#define N 3	 // Number of unknowns


struct guass
{
	int p , q;
	guass operator +( const guass b)
	{
		int x = p*b.q + b.p*q;
		int y = b.q*q;
		int gcd = __gcd(abs(x) , abs(y));
		x/=gcd;
		y/=gcd;
		return {x , y};
	}
	guass operator -( const guass b)
	{
		int x = p*b.q - b.p*q;
		int y = b.q*q;
		int gcd = __gcd(abs(x) , abs(y));
		x/=gcd;
		y/=gcd;
		return {x , y};
	}
	guass operator *( const guass b)
	{
		int x = p*b.p;
		int y = b.q*q;
		int gcd = __gcd(abs(x) , abs(y));
		x/=gcd;
		y/=gcd;
		return {x , y};
	}
	guass operator /( const guass b)
	{
		int x = p*b.q;
		int y = b.p*q;
		int gcd = __gcd(abs(x) , abs(y));
		x/=gcd;
		y/=gcd;
		return {x , y};
	}
	bool operator ==( const guass b)
	{
		return p==b.p && q==b.q;
	}
	bool operator >( const guass b)
	{
		return abs(p)*abs(b.q) > abs(q)*abs(b.p);
	}
	bool operator <( const guass b)
	{
		return abs(p)*abs(b.q) < abs(q)*abs(b.p);
	}
	
};

void swap_row( guass mat[N][N+1], int i, int j)
{
	for (int k=0; k<=N; k++)
	{
		guass temp = mat[i][k];
		mat[i][k] = mat[j][k];
		mat[j][k] = temp;
	}
}
int forwardElim(guass mat[N][N+1])
{
	for (int k=0; k<N; k++)
	{
		int i_max = k;
		guass v_max = mat[i_max][k];
		for (int i = k+1; i < N; i++)
			if (mat[i][k] > v_max)
				v_max = mat[i][k], i_max = i;
		if (!mat[k][i_max].p)
			return k;
		if (i_max != k)
			swap_row(mat, k, i_max);
		for (int i=k+1; i<N; i++)
		{
			guass f = mat[i][k]/mat[k][k];
			for (int j=k+1; j<=N; j++)
				mat[i][j] = mat[i][j] - mat[k][j]*f;
			mat[i][k] = {0 , 0};
		}
	}
	return -1;
}
void backSub(guass mat[N][N+1])
{
	guass x[N];
	for (int i = N-1; i >= 0; i--)
	{
		x[i] = mat[i][N];
    	for (int j=i+1; j<N; j++)
		{
		    x[i] = x[i] - mat[i][j]*x[j];
		}
		x[i] = x[i]/mat[i][i];
	}

	printf("\nSolution for the system:\n");
	for (int i=0; i<N; i++)
	{
		int ss = 1;
		if(x[i].p < 0&&x[i].q < 0) ss = -1;
		printf("%d/%d\n", ss*x[i].p,ss*x[i].q);
	}
}
void gaussianElimination(guass mat[N][N+1])
{
	int singular_flag = forwardElim(mat);
	if (singular_flag != -1)
	{
		if (mat[singular_flag][N].p)
			printf("Inconsistent System.");
		else
			printf("May have infinitely many "
				"solutions.");
		return;
	}
	backSub(mat);
}

void print(guass mat[N][N+1])
{
	for (int i=0; i<N; i++, printf("\n"))
		for (int j=0; j<=N; j++)
			printf("%d/%d ", mat[i][j].p, mat[i][j].q);
	printf("\n");
}
int main()
{
	guass mat[N][N+1] = {{{3 , 1}, {2 , 1},{-4 , 1}, {3, 1}},
						{{2 , 1}, {3 , 1}, {3 ,1 }, {15 ,1 }},
						{{5 , 1}, {-3 , 1}, { 1 , 1}, {14 , 1}}
						};
	gaussianElimination(mat);
	return 0;
}
