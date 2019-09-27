#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 20
#define M 20
#define W 20
#define Max 1000

struct item
{
    int inum;
    int rang[5];
    int score[5];
};

struct Snode
{
    int snum;
    int score;
    int mscore;
    int wscore;
    struct item itm[M+W];
}Snode_a[N];

void menu()
{
    printf("Welcome to use the Games Management System\n");
    printf("            1.信息输入\n");
    printf("            2.信息统计\n");
    printf("            3.成绩排序\n");
    printf("            4.信息查询\n");
    printf("            0.退出程序\n\n") ;
}

void Operation(int s,int m,int w)
{
    int choose;
    printf("请输入你的选择:");
    scanf("%d",&choose);
    void input(int s,int m,int w);
    void output(int s,int m,int w);
    void sort(int s,int m,int w);
    void find(int s,int m,int w);
    switch(choose)
    {
        case 1:
            input(s,m,w);
            break;
        case 2:
            output(s,m,w);
            break;
        case 3:
            sort(s,m,w);
            break;
        case 4:
            find(s,m,w);
            break;
        case 0:
            printf("感谢使用!\n");
    }
    if(choose>4||choose<0)
    {
        printf("System Not Find!\nPlease Try Again.\n\n");
        menu();
        Operation(s,m,w);
    }
}

void savefile()
{
    FILE*fp;
    int i;
    if((fp=fopen("file.txt","w"))==NULL)
    {
        printf("cannot open the file\n");
        return;
    }
    for(i=0;i<N;i++)
    {
        if(Snode_a[i].snum!='\0')
            if(fwrite(&Snode_a[i],sizeof(struct Snode),1,fp)!=1)
            {
                printf("file write error\n");
                return;
            }
    }
    fclose(fp);
}

void readfile()//读信息
{
    int i;
    FILE *fp;
    if((fp=fopen("file.txt","rb"))==NULL)
    {
        printf("cannot open the file\n");
        return;
    }
    for(i=0;i<N;i++)
    {
        fread(&Snode_a[i],sizeof(struct Snode),1,fp);
    }
    fclose(fp);
}

void input(int s,int m,int w)
{
    int i,j,o;
    for(i=0;i<s;i++)
    {
        printf("学校编号:");
        scanf("%d",&Snode_a[i].snum);
        for(j=0;j<m+w;j++)
        {
            printf("请输入项目编号:");
            scanf("%d",&Snode_a[i].itm[j].inum);
            int k=0;
            if(Snode_a[i].itm[j].inum%2==0)
            {
                Snode_a[i].itm[j].inum=3;//这里有点问题，是否应改再定义一下结构体“Top”
            }
            else if(Snode_a[i].itm[j].inum%2!=0)
            {
                Snode_a[i].itm[j].inum=5;
            }
            printf("请输入获得名次人数:");
            scanf("%d",&k);
                        for(o=0;o<k;o++)
                        {
                            printf("请输入运动员所获名次:");
                            scanf("%d",&Snode_a[i].itm[j].rang[o]);
                        }
            printf("\n\n");
        }
//        printf("\n\n");
    }
//    for(i=0;i<s;i++)
//    {
//        Snode_a[i].score=0;
//        Snode_a[i].mscore=0;
//        Snode_a[i].wscore=0;
//    }
    for(i=0;i<s;i++)
    {
        for(j=0;j<m+w;j++)
        {
            for(o=0;o<4;o++)
            {
                if(Snode_a[i].itm[j].inum==3)
                {
                    switch(Snode_a[i].itm[j].rang[o])
                    {
                        case 0:
                            Snode_a[i].itm[j].score[o]=0;
                            break;
                        case 1:
                            Snode_a[i].itm[j].score[o]=5;
                            break;
                        case 2:
                            Snode_a[i].itm[j].score[o]=3;
                            break;
                        case 3:
                            Snode_a[i].itm[j].score[o]=2;
                            break;
                    }
                }
                else if(Snode_a[i].itm[j].inum==5)
                {
                    switch(Snode_a[i].itm[j].rang[o])
                    {
                        case 0:
                            Snode_a[i].itm[j].score[o]=0;
                            break;
                        case 1:
                            Snode_a[i].itm[j].score[o]=7;
                            break;
                        case 2:
                            Snode_a[i].itm[j].score[o]=5;
                            break;
                        case 3:
                            Snode_a[i].itm[j].score[o]=3;
                            break;
                        case 4:
                            Snode_a[i].itm[j].score[o]=2;
                            break;
                        case 5:
                            Snode_a[i].itm[j].score[o]=1;
                            break;
                    }
                }
                else{
                    printf("您输入的信息有误，或已超出范围。");
                    printf("\n");
                    exit(0);
                }
                Snode_a[i].score+=Snode_a[i].itm[j].score[o];//学校总分
                if(j<=m)
                    Snode_a[i].mscore+=Snode_a[i].itm[j].score[o];//男子团体总分
                else
                    Snode_a[i].wscore+=Snode_a[i].itm[j].score[o];//女子团体总分
            }
        }
    }
    savefile();
    menu();
    Operation(s,m,w);
}

void output(int s,int m,int w)
{
    readfile();
    int i;
    for(i=0;i<s;i++)
    {
        printf("学校编号:%d    学校总分:%d    男子团体总分:%d    女子团体总分:%d\n",Snode_a[i].snum,Snode_a[i].score,Snode_a[i].mscore,Snode_a[i].wscore);
    }
    printf("\n");
    menu();
    Operation(s,m,w);
}

void sort(int s,int m,int w)
{
    readfile();
    int i,j,k;
    int c2;
    int kg=1;
    int median;
    int new_a[N];
    while(kg==1)
    {
        printf("1.学校总分排名\n");
        printf("2.男子团体排名\n");
        printf("3.女子团体排名\n");
        printf("\n\n");
        printf("请选择一种排名方式:");
        scanf("%d",&c2);
        switch(c2)
        {
            case 1:
                for(i=0;i<s;i++)
                {
                    new_a[i]=Snode_a[i].score;
                }
                for(i=0;i<s;i++)
                {
                    for(j=1;j<s;j++)
                    {
                        if(new_a[j]<new_a[j-1])
                        {
                            median=new_a[j];
                            new_a[j]=new_a[j-1];
                            new_a[j-1]=median;
                        }
                    }
                }
                for(i=0;i<s;i++)
                {
                    printf("学校编号:%d    学校总分:%d\n",Snode_a[i].snum,new_a[i]);
                }
                break;
            case 2:
                for(i=0;i<s;i++)
                {
                    new_a[i]=Snode_a[i].mscore;
                }
                for(i=0;i<s;i++)
                {
                    for(j=1;j<s;j++)
                    {
                        median=new_a[i];
                        new_a[j]=new_a[j-1];
                        new_a[j-1]=median;
                    }
                }
                for(i=0;i<s;i++)
                {
                    printf("学校编号:%d     男子团体总分:%d\n",Snode_a[i].snum,new_a[i]);
                }
                break;
            case 3:
                for(i=0;i<s;i++)
                {
                    new_a[i]=Snode_a[i].wscore;
                }
                for(i=0;i<s;i++){
                    for(j=1;j<s;j++)
                    {
                        median=new_a[j];
                        new_a[j]=new_a[j-1];
                        new_a[j-1]=median;
                    }
                }
                for(i=0;i<s;i++)
                {
                    printf("学校编号:%d     女子团体总分:%d\n",Snode_a[i].snum,new_a[i]);
                }
                break;
            default:
                printf("输入错误，请重新输入。\n");
        }
        printf("1:返回排名菜单。     2:退出排名系统\n");
        scanf("%d",&kg);
        printf("\n");
    }
    while(kg==1)
        printf("\n");
    if(kg!=1)
    {
        menu();
        Operation(s,m,w);
    }
}

void find(s,m,w)
{
    readfile();
    int c1;
    int i,j,k,h,q=1;
    printf("Welcome to use the score inquiry system\n");
    printf("\n\n");
    do
    {
        k=-1;
        h=-1;
        printf("请输入学校编号:");
        scanf("%d",&c1);
        for(i=0;i<s;i++)
        {
            if(Snode_a[i].snum==c1)
                k=i;
        }
        if(k==-1)
            printf("该学校没有参加这次运动会\n");
        else{
            printf("请输入要查询的项目编号:");
            scanf("%d",&c1);
            for(j=0;j<m+w;j++)
            {
                if(Snode_a[k].itm[j].inum==c1)
                {
                    h=j;
                }
            }
            if(h==-1)
            {
                printf("这次运动会并为举行该项目。\n");
            }
            else
            {
                printf("该项目取前%d名，该学校的成绩如下:\n",Snode_a[k].itm[j].inum);
                for(i=0;i<5;i++)
                {
                    if(Snode_a[k].itm[h].rang[i]!=0)
                    {
                        printf("名次:%d\n",Snode_a[k].itm[h].rang[i]);
                    }
                }
                
            }
        }
        printf("1.返回主菜单。     2.继续查找。");
        scanf("%d",&q);
        printf("\n");
    }while(q==2);
    while(q==2)
        printf("\n");
    if(q==1)
    {
        menu();
        Operation(s,m,w);
    }
}

int main()
{
    int s,m,w;
    printf("请输入学校个数:");
    scanf("%d",&s);
    printf("\n");
    printf("请输入男子项目个数:");
    scanf("%d",&m);
    printf("\n");
    printf("请输入女子项目个数:");
    scanf("%d",&w);
    printf("\n");
    menu();
    Operation(s,m,w);
    return 0;
}

