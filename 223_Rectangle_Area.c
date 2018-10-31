/*
* 223. Rectangle Area (Medium)
* https://leetcode.com/problems/rectangle-area/description/
* 
*/

int max(int a, int b)
{
    if ( a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int min(int a, int b)
{
    if ( a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
    int s1 = abs(C-A)*abs(D-B);
    int s2 = abs(G-E)*abs(H-F);
    int lbX = max(A, E);
    int lbY = max(B,F);
    int trX = min(C, G);
    int trY = min(D, H);
    if(C <= E || G <= A || H <= B || D <= F)
    {
        return s1+s2;
    }
    return s1 + s2 - abs(trX - lbX)*abs(trY-lbY);
}
