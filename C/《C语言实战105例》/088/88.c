#include <graphics.h>
#include <dos.h>
#include <bios.h>
#include <stdio.h>
/*�����Կ�*/
void DetectGraphicadapter()
{
	int gdriver, gmode;
	puts("The information of graphics adapter is :\n");
	detectgraph(&gdriver, &gmode);
	if(gdriver==-2)
	{
	  printf(">>no graphics adapter in the computer\n");
	}
	else
	{
	  printf(">>Driver is %d.\n", gdriver);    /*������Խ��*/
	  printf(">>Mode is %d.\n\n",gmode);
	}
}
/*����Ӳ��*/
void DetectDisk()
{
	struct dfree diskfree;
	struct fatinfo fileinfo;
	puts("The information of the current disk is :\n");
	getdfree(0,&diskfree);
	getfat(0,&fileinfo);
	puts("----------------- disk space ------------------");
	printf(">>The num of avaible clusters is : %d\n",diskfree.df_avail);
	printf(">>The num of all clusters is : %d\n",diskfree.df_total);
	printf(">>The num of bytes of every sector is : %d\n",diskfree.df_bsec);
	printf(">>The num of sectors of every cluster is : %d\n",diskfree.df_sclus);
	puts("----------- file allocation table -------------");
	printf(">>The num of sectors of every cluster is : %d\n",fileinfo.fi_sclus);
	printf(">>The num of bytes of file allocation table is : %d\n",fileinfo.fi_fatid);
	printf(">>The num of clusters is : %d\n",fileinfo.fi_nclus);
	printf(">>The num of ytes of every sector is : %d\n",fileinfo.fi_bysec);
}
int main()
{                    
	/*�����Կ�*/
	DetectGraphicadapter();
	puts("Press any key to detect the disk...");
	getch();
	/*����Ӳ��*/
	DetectDisk();
	getch();
	return 1;
} 



