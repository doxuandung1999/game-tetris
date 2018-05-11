
struct khoigach{
    int **arr;
    int hang , cot;
    int iboard , jboard;
};
khoigach *taokhoigach(int id)
{
//    khoigach *pkhoigach = (khoigach*)malloc(sizeof(khoigach));
    khoigach *pkhoigach = new khoigach[100];
    switch (id)
    {
    case 15 :
        pkhoigach->hang = 4 ;
        pkhoigach->cot = 1;
        pkhoigach->iboard = 0;
        pkhoigach->jboard = 5;
        break;
    case 31:
        pkhoigach->hang = 2;
        pkhoigach->cot = 2;
        pkhoigach->iboard = 2;
        pkhoigach->jboard = 5;
        break;
    default:
        pkhoigach->hang = 2;
        pkhoigach->cot = 3;
        pkhoigach->iboard = 2;
        pkhoigach->jboard = 5;
    }
    pkhoigach->arr = new int*[100];
    for(int i=0;i<pkhoigach->hang;i++)
    {
    pkhoigach->arr[i] = new int[100];
    }
    for(int j=0;j<pkhoigach->cot*pkhoigach->hang;j++)
    {
        pkhoigach->arr[j/pkhoigach->cot][j%pkhoigach->cot] = (id>>(pkhoigach->hang*pkhoigach->cot-1-j))&1;// tham khao
    }
    return pkhoigach;
}
void vekhoigach(khoigach *pkhoigach)
{
    for(int i=0;i<pkhoigach->hang;i++)
    {
        for(int j=0;j<pkhoigach->cot;j++)
        {
            if(pkhoigach->arr[i][j]==1&&(pkhoigach->iboard+i)>3)
            {
                textcolor(9);
                gotoxy(rong+pkhoigach->jboard+j+1 , dai+pkhoigach->iboard+i-4+1);
                cout << char(2);
            }
        }
    }
}
void xoakhoigach(khoigach *pkhoigach)
{
    for(int i=0;i<pkhoigach->hang;i++)

        for(int j=0;j<pkhoigach->cot;j++)

            if(pkhoigach->arr[i][j]==1&&(pkhoigach->iboard+i)>3)
            {
                textcolor(0);
                gotoxy(rong+pkhoigach->jboard+j+1,dai+pkhoigach->iboard+i-4+1);
                cout << " ";
            }

}
void huykhoigach(khoigach * pkhoigach)
{
    for(int i=0;i<pkhoigach->hang;i++)
        free(pkhoigach->arr[i]);
        free(pkhoigach->arr);
        free(pkhoigach);
        pkhoigach = NULL;
}
void venext(int id)
{
    khoigach *pnext = taokhoigach(id);
    int ingoai= rong + maxj + 5 ;
    int jngoai = dai;
    for(int i=0;i<pnext->hang;i++)
    {
        for(int j=0;j<pnext->cot;j++)
        {
            if(pnext->arr[i][j]==1)
            {
                textcolor(10);
                gotoxy(ingoai+j , jngoai+i);
                cout << char(2);
            }
        }
    }
    huykhoigach(pnext);

}
void xoanext()
{
    int ingoai = rong + maxj+5;
    int jngoai = dai;
    for(int i=0 ; i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            textcolor(0);
            gotoxy(ingoai+j , jngoai+i) ;
             cout << " ";
        }
    }
}
 //chon ngau nhien 1 vien gsch
int loai()
{
    int x = rand()%7;
    switch(x)
    {
    case 0:
        return 15;
        break;
    case 1:
        return 31;
        break;
    case 2:
        return 51;
        break;
    case 3:
        return 30;
        break;
    case 4:
        return 58;
        break;
    case 5:
        return 57;
        break;
    case 6:
        return 60;
        break;
    }
}

