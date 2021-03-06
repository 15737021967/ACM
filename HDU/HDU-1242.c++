#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
char dt[200][200];
int m,n,xl,xt,yl,yt;
int xy[4][2]={1,0,0,-1,0,1,-1,0},temp[200][200];
struct cmp
{
    int i,j,pre;
    friend bool operator < (cmp a,cmp b)
    {
        return a.pre>b.pre;
    }
};
priority_queue<cmp>it;
int DFS(int x,int y)
{
    memset(temp,0,sizeof(temp));
    cmp e,o;
    e.i=xl;
    e.j=yl;
    e.pre=0;
    it.push(e);
    temp[e.i][e.j]=1;
    while (!it.empty())
    {
        e=it.top();
        it.pop();
        if (dt[e.i][e.j]=='r')
        {
            return e.pre;
        }
        for (int t=0;t<4;t++)
        {
            o=e;
            o.i+=xy[t][0];
            o.j+=xy[t][1];
            if (dt[o.i][o.j]=='#'||o.i>=m||o.j>=n||o.i<0||o.j<0||temp[o.i][o.j]==1)
                continue;
            o.pre++;
            if (dt[o.i][o.j]=='x')
                o.pre++;
            temp[o.i][o.j]=1;
            it.push(o);
        }
    }
    return 0;
}
int main()
{
    while (scanf("%d %d",&m,&n)!=EOF)
    {
        temp[200][200]={0};
        for (int k=0;k<m;k++)
        {
            getchar();
            for (int l=0;l<n;l++)
            {
                scanf("%c",&dt[k][l]);
                if (dt[k][l]=='a')
                {
                    xl=k;
                    yl=l;
                }
            }
        }
        int num=DFS(xl,yl);
        if (num)
            printf("%d\n",num);
        else
            printf("Poor ANGEL has to stay in the prison all his life.\n");
    }
    return 0;
}