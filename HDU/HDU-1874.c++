#include <iostream>
#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f
using namespace std;
int M,N,chara[205][205],dis[205],vis[205];
void Dijkstra(int str)
{
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    for (int i=0;i<N;i++)
        dis[i]=chara[str][i];
    dis[str]=0;
    vis[str]=1;
    for (int i=0;i<N;i++)
    {
        int ans=INF,k;
        for (int j=0;j<N;j++)
        {
            if (!vis[j]&&dis[j]<ans)
            {
                ans=dis[j];
                k=j;
            }
        }
        if (ans==INF)
            break;
        vis[k]=1;
        for (int j=0;j<N;j++)
        {
            if (!vis[j]&&dis[j]>dis[k]+chara[k][j])
                dis[j]=dis[k]+chara[k][j];
        }
    }
}
int main()
{
    int a,b,c,stat,en;
    while (~scanf("%d %d",&N,&M))
    {
        memset(chara,0x3f,sizeof(chara));
        for (int i=0;i<M;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            if (c<chara[a][b])
                chara[a][b]=chara[b][a]=c;
        }
        scanf("%d %d",&stat,&en);
        Dijkstra(stat);
        printf("%d\n",dis[en]<INF?dis[en]:-1);
    }
    return 0;
}