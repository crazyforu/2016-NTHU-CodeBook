inline int read()
{
    int x=0; bool f=0; char c=getchar();
    while(ch<'0'||'9'<ch)f|=ch=='-',ch=getchar();
    while('0'<=ch&&ch<='9')x=x*10-'0'+ch,ch=getchar();
    return f?-x:x;
}
inline int read()
{//��J���i�H�]�t : ; < > = ? 
    int x=0; bool f=0; char c=getchar();
    while((c>>4)&3!=3)f|=ch=='-',c=getchar();
    while((c>>4)&3==3)x=x*10-'0'+c,c=getchar();
    return f?-x:x;
}


