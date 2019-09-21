#include <stdio.h>
#include <assert.h>

struct A
{
    int R;
    int G;
    int B;
};
typedef struct A Pixle;

static Pixle pic[1920][1080];

static int char2int(char c)
{
    return c<='9'?c-'0':c-'A'+10;
}

static int OneColor2int(char a, char b)
{
    return char2int(a)*16+char2int(b);
}

static void FillPixle(Pixle* p, char* line)
{
    if(line[2]=='\0')
    {
        int c = OneColor2int(line[1],line[1]);
        p->R = c;
        p->G = c;
        p->B = c;
    }
    else if(line[4]=='\0')
    {
        p->R = OneColor2int(line[1],line[1]);
        p->G = OneColor2int(line[2],line[2]);
        p->B = OneColor2int(line[3],line[3]);
    }
    else if(line[7] == '\0')
    {
        p->R = OneColor2int(line[1],line[2]);
        p->G = OneColor2int(line[3],line[4]);
        p->B = OneColor2int(line[5],line[6]);
    }
    else
        assert(0);
}

static void PAdd(Pixle* a, Pixle b)
{
    a->R+=b.R;
    a->G+=b.G;
    a->B+=b.B;
}

static void PAve(Pixle* a,int num)
{
    a->R/=num;
    a->G/=num;
    a->B/=num;
}

static int PEql(Pixle a, Pixle b)
{
    return a.R == b.R && a.G == b.G && a.B == b.B;
}

static void OneColorPrintIntern(int c)
{
    printf("\\x%x",c+'0');
}

static void OneColorPrint(int c)
{
    int t = c /100;
    if(t!=0)
        OneColorPrintIntern(t);
    t= c%100/10;
    if(t!=0)
        OneColorPrintIntern(t);
    t= c%10;
    if(t!=0)
        OneColorPrintIntern(t);
}

int main()
{
    int m,n,p,q;
    scanf("%d %d %d %d",&m,&n,&p,&q);
    getchar();
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
        {
            char line[8];
            gets(line);
            FillPixle(&pic[i][j],line);
        }

    for(int r=0; r<m; r+=q) // yao fan guo lai
    {
        Pixle pipre = {0};
        for(int c=0; c<n; c+=p) // one block
        {
            Pixle pi = {0};
            for(int i=c; i<c+p; i++)
                for(int j=r; j<r+q; j++)
                    PAdd(&pi,pic[i][j]);
            PAve(&pi,p*q);

            if(!PEql(pi,pipre))
            {
                //printf("\\x1B\\x5B\\x34\\x38\\x3B\\x32\\x3B\\x%X\\x3B\\x%X\\x3B\\x%X\x6D");
                printf("\\x1B\\x5B\\x34\\x38\\x3B\\x32\\x3B");
                OneColorPrint(pi.R);
                printf("\\x3B");
                OneColorPrint(pi.G);
                printf("\\x3B");
                OneColorPrint(pi.B);
                printf("\\x6D");
            }

            printf("\\x20"); // space

            pipre = pi;
        }
        printf("\\x1B\\x5B\\x30\\x6D\\x0A");
    }
}