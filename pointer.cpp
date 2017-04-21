#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void nhapN	(int &n)
{
	do
	{
		printf("Nhap vao so phan tu cua mang! ");
		scanf("%d", &n);
		if ( n <= 0 )
			printf("\nNhap sai vui long nhap lai! ");
	} while ( n <= 0 );
}


//nhap mang bang con tro
void nhapmang(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\nNhap a[%d]: ", i);
		scanf("%d", (a+i));
	}

}

//xuat mang bang con tro
void xuatmang(int* a, int n)
{
	for (int i = 0; i < n; i++)
		printf("\t%d", *(a+i));
}

//them 1 phan tu
void them(int*& a, int &n)
{
	int vitrithem, giatrithem;
	printf("\nNhap vi tri can them: ");
	scanf("%d", &vitrithem);
	printf("\nNhap gia tri can them: ");
	scanf("%d", &giatrithem);
	n++;
	a = (int*)realloc(a, n * sizeof(int));
	for (int i = n-1; i > (vitrithem-1); i--)
		a[i] = a[i-1];
	a[vitrithem-1] = giatrithem;

}

// xoa phan tu 
void xoa(int*& a, int &n)
{
	int vitrixoa;
	printf("\nNhap vi tri can xoa: ");
	scanf("%d", &vitrixoa);
	for(int i = (vitrixoa-1); i < n; i++)
	{
		a[i] = a[i+1];
	}
	n--;
	a = (int*)realloc(a, n * sizeof(int));

}

//ham hoan vi 2 vi tri
void hoanvi (int &a, int &b)
{
	int c;
	c = a;
	a = b;
	b = c;
}


//sap xep theo thu tu tang dan
void tangdan (int* a, int n)
{
	for ( int i = 0; i < n; i++ )
		for ( int j = (i+1); j < n; j++ )
			if ( a[i] > a[j])
				hoanvi(a[i], a[j]);
}


int main()
{
	int* a = NULL;
	int n;

	nhapN(n);

	a = (int*)realloc(a, n * sizeof(int));

	nhapmang(a, n);
	printf("\nMang da nhap vao la: \n");
	xuatmang(a, n);

	them(a, n);
	xuatmang(a, n);

	xoa(a, n);
	xuatmang(a, n);

	tangdan(a, n);
	printf("\nSap thep theo thu tu tang dan la: ");
	xuatmang(a, n);

	free(a);

	getchar();
}