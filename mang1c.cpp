#include "stdio.h"
#include "math.h"

#define MAX 100

//nhap so phan tu trong mang 0<n<=10
void nhapN	(int &n)
{
	do
	{
		printf("Nhap vao so phan tu cua mang! ");
		scanf("%d", &n);
		if ( n < 0 || n > 10 )
			printf("\nNhap sai vui long nhap lai! ");
	} while ( n < 0 || n > 10 );

}

//ham nhap mang
void nhapmang (int a[], int n)
{
	for ( int i = 0; i <n; i++)
	{
		printf("\nNhap phan a[%d]: ", i);
		scanf("%d", &a[i]);
	}
}

//ham xuat mang
void xuatmang (int a[], int n)
{
	for ( int i = 0; i <n; i++)
		printf("%5d", a[i]);

}

//tim cac phan tu chia het cho 3 trong mang
void chiahet3 (int a[], int n)
{
	for (int i = 0; i < n; i++)
		if ( a[i] % 3 == 0 )
			printf("\t%d", a[i]);
}

//ham kiem tra so nguyen to
int ktnt (int x)
{
	if ( x < 0 )	return 0;
	if ( x == 1 )	return 0;
	if ( x == 2 )	return 1;
	if ( x % 2 == 0 )	return 0;
	for ( int i = 2; i < ( x / 2 ); i++)
		if ( x % i == 0 )
			return 0;
	return 1;

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
void tangdan (int a[], int n)
{
	for ( int i = 0; i < n; i++ )
		for ( int j = (i+1); j < n; j++ )
			if ( a[i] > a[j])
				hoanvi(a[i], a[j]);
}

//xuat cac so nguyen to ra man hinh
void xuatnguyento (int a[], int n)
{
	for (int i = 0; i < n; i++)
		if ( ktnt(a[i]) == 1 )
			printf("\t%d", a[i]);
}

//them vao vi tri do nguoi dung nhap tu ban phim
void them (int a[], int &n)
{
	n++;
	int vitri, giatri;

	do
	{
		printf("\nNhap vi tri can them! ");
		scanf("%d", &vitri);
		printf("\nNhap gia tri can them! ");
		scanf("%d", &giatri);
		if (vitri <= 0)
			printf("\nVui long nhap lai vi tri ! ");
	} while (vitri <= 0);

	for (int i = (n-1); i >= (vitri-1); i--)
		a[i+1] = a[i];
	a[vitri-1] = giatri;

}

//xoa phan tu tai vi tri k do nguoi dung nhap tu ban phim
void xoa (int a[], int &n)
{
	int vitri;
	do
	{
		printf("\nNhap vi tri phan tu muon xoa !");
		scanf("%d", &vitri);
		if ( vitri <=0 )
			printf("\nKhong co vi tri nay. Vui long nhap lai !");
	} while ( vitri <=0 );

	for (int i = (vitri-1); i < n; i++)
		a[i] = a[i+1];
	n--;
}

int main()
{
	int a[MAX], n;
	nhapN(n);
	nhapmang(a, n);
	printf("\nCac phan tu trong mang la: \n");
	xuatmang(a, n);

	printf("\nCac phan tu chia het cho 3 trong mang la: \n");
	chiahet3(a, n);

	printf("\nCac so nguyen to la: \n");
	xuatnguyento(a, n);

	tangdan(a, n);
	printf("\nMang sap xep theo thu tu tang la: \n");
	xuatmang(a, n);

	them(a, n);
	xuatmang(a, n);

	xoa(a, n);
	xuatmang(a, n);


	return 0;
}