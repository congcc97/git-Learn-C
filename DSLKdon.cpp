#include<stdio.h>
#include<string.h>
typedef struct sinhvien
{
	char ma[11];
	char ten[41];
	float dtb;
}sv;
//-----------------------------------------------------------
typedef struct node
{
	sv info;
	struct node*next;
}node;
//-----------------------------------------------------------

//void nhap1sv(sv &x)
//{
//	printf("\nnhap ma so:");
//	fflush(stdin);
//	gets(x.ma);
//	printf("\nnhap ten:");
//	fflush(stdin);
//	gets(x.ten);
//	printf("\nnhap diem:");
//	scanf("%f",&x.dtb);
//}

//-----------------------------------------------------------
void xuat1sv(sv a)
{
	printf("%-15s%-30s%-15.2f\n", a.ma, a.ten, a.dtb);
}

//-----------------------------------------------------------
void khoitao(node* &phead)
{
	phead=NULL;
}
//-----------------------------------------------------------
node* taonut(sv x)
{
	node*p=new node;
	p->info=x;
	p->next=NULL	;
	return p;
}

//-----------------------------------------------------------
void themcuoi(node* &phead,sv x)
{
	node*t=taonut(x);
	if(phead==NULL)
		phead=t;
	else
	{
		node*p;
		for(p=phead;p->next!=NULL;p=p->next);
		p->next=t;
	}
}

//-----------------------------------------------------------
//void nhapdssv(node* &phead)
//{
//	int n;
//	printf("nhap so luong sinh vien:");
//	scanf("%d",&n);
//	for(int i=0;i<n;i++)
//	{
//		printf("\n");
//		printf("\nsinh vien thu:%d",i+1);
//		sv x;
//		themcuoi(phead,x);
//	}
//}

//-----------------------------------------------------------
void xuatdssv(node*phead)
{
	printf("%-15s%-30s%-15s\n", "MSSV", "HOTEN", "DIEM");
	for(node*p=phead;p!=NULL;p=p->next)
	xuat1sv(p->info);
}

//-----------------------------------------------------------
void xuatdiem(node*phead)
{
	if(phead==NULL) return;
	for(node*p=phead;p!=NULL;p=p->next)
	{
		if(p->info.dtb>=5)
		xuat1sv(p->info);
	}
}


//-----------------------------------------------------------
void readFile(char fileName[], node* &phead)
{
	int n;
	sv a;

	FILE *f = fopen(fileName, "rt");
	if (f != NULL)
	{
		fscanf(f, "%d\n", &n);
		for(int i=1; i<n; i++)
		{
			fscanf(f, "%s\n", &a.ma); a.ma[strlen(a.ma)-1]='\0';
			fgets(a.ten, 40, f); a.ten[strlen(a.ten)-1]='\0';
			fscanf(f, "%f\n", &a.dtb);
			themcuoi(phead, a);
		}
	}
	fclose(f);
}
//--------------------------------------------------------------
void swap(sv &a,sv &b)
{
	sv T;
	T=a;
	a=b;
	b=T;
}
//-----------------------------------------------------------
void InterchangeSort_Tang_diem(node* phead)
{
	for(node* p=phead;p->next!=NULL;p=p->next)
	{
		for(node* q=p->next;q!=NULL;q=q->next)
			if(p->info.dtb > q->info.dtb)
				swap(p->info,q->info);
	}
}
//-----------------------------------------------------------
node* Search(node* phead,char x[])
{
	node* p=phead;
	while(p!=NULL)
	{
		if(strcmp(p->info.ma, x)==0) return p;
		p=p->next;
	}
	return NULL;
}

//int menu(int chon)
//{
//	int chon;
//	printf("\n 0")
//}
//-----------------------------------------------------------
int main()
{
	char maCanTim[11];
	node* phead;

	khoitao(phead);
//	nhapdssv(phead);
	readFile("DSSV.txt", phead);
	printf("------danh sach sinh vien vua nhap-------\n");
	xuatdssv(phead);
	printf("\n");
	printf("\n+++++++++++++++DSSV co DTB >5: ++++++++++++++++++\n");
	xuatdiem(phead);

	printf("\n\n=======danh sach sinh vien tang theo diem=======\n");
	InterchangeSort_Tang_diem(phead);
	xuatdssv(phead);

	printf("\nNhap MSSV can tim: ");
	fflush(stdin);	fgets(maCanTim, 11, stdin);
	if (Search(phead, maCanTim) == NULL)
		printf("\nKhong TIm thay ");
	else
	{
		printf("\nThong Tin sinh vien can tim la: \n");
		xuat1sv(Search(phead, maCanTim)->info);
	}
	return 0;
}
