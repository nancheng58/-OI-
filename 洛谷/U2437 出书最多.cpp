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
    int xiabiao;//������������±� 
    int large;//����������߳����� 
    char large2;//��������������� 
    int flag[26];//ͳ��ÿ���������ֳ��ֵĸ��� 
    struct book a[999];//�ṹ�壬�洢��ţ��������� 
    scanf("%d",&m);
    for(i=0;i<26;i++)//��ʼ�� 
    {
        flag[i]=0;
    }
    for(i=0;i<m;i++)//�����š����� 
    {
        scanf("%d%s",&a[i].num,&a[i].writer);
    }    
    for(i=0;i<m;i++)//ͳ��ÿ���������ֳ��ִ��� 
    {
        for(j=0;j<strlen(a[i].writer);j++)
        {
            flag[a[i].writer[j]-65]++;
        }
    }
    large=flag[0];    
    for(i=0;i<26;i++)//�ҳ������������� 
    {
        if(flag[i]>large)//�������һ����Ŀǰ��Ҫ��ģ����� 
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
