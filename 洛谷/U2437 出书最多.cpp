#include <stdio.h>
#include <string.h>
struct book
{
    int num;
    char writer[300];
};
int main()
{
    int m,i,j;
    int xiabiao;//出书最多作者下标 
    int large;//出书最多作者出的书 
    char large2;//出书最多作者名字 
    int flag[26];//统计每个作者名字出现的个数 
    struct book a[999];//结构体，存储编号，作者姓名 
    scanf("%d",&m);
    for(i=0;i<26;i++)//初始化 
    {
        flag[i]=0;
    }
    for(i=0;i<m;i++)//输入编号、作者 
    {
        scanf("%d%s",&a[i].num,&a[i].writer);
    }    
    for(i=0;i<m;i++)//统计每个作家名字出现次数 
    {
        for(j=0;j<strlen(a[i].writer);j++)
        {
            flag[a[i].writer[j]-65]++;
        }
    }
    large=flag[0];    
    for(i=0;i<26;i++)//找出出书最多的作家 
    {
        if(flag[i]>large)//如果发现一个比目前还要大的，更新 
        {
            xiabiao=i;
            large=flag[i];
        }        
    } 
    large2=xiabiao+65;
    printf("%c\n%d\n",large2,large); 
    for(i=0;i<m;i++)
    {
        for(j=0;j<strlen(a[i].writer);j++)
        {
            if(a[i].writer[j]==large2) 
            {
                printf("%d\n",a[i].num);
                break; 
            }            
        }
    }
    return 0;
}
