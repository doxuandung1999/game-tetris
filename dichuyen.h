
int thuocbang(int i , int j) // ham kiem tra xem khoi gach co thuoc bang hay ko.
{
    return (i>=0&&i<maxi&&j>=0&&j<maxj);
}
int phai(int i, int j)
{
    if(j<maxj-1&&thuocbang(i,j)&&board[i][j+1]==0) return 1;
    return 0;
}
int trai(int i , int j)
{
    if(j>0&&thuocbang(i,j)&&board[i][j-1]==0) return 1;
    return 0;
}
int xuong(int i , int j)
{
    if(i<maxi-1&&thuocbang(i,j)&&board[i+1][j]==0) return 1;
    return 0;
}
// ham di chyen ca khoi gach.
void sangtrai(khoigach *pkhoigach)
{
    for(int i=0;i<pkhoigach->hang;i++)

        for(int j=0;j<pkhoigach->cot;j++)

            if(pkhoigach->arr[i][j]==1)
            {
                if(trai(pkhoigach->iboard+i,pkhoigach->jboard+j)==0||pkhoigach->iboard <=3) return;
            }


    pkhoigach->jboard-=1;
}
void sangphai(khoigach *pkhoigach)
{
    for(int i=0;i<pkhoigach->hang;i++)

        for(int j=0;j<pkhoigach->cot;j++)

            if(pkhoigach->arr[i][j]==1)
            {
                if(phai(pkhoigach->iboard+i,pkhoigach->jboard+j)==0||pkhoigach->iboard<=3) return;
            }


    pkhoigach->jboard+=1;
}
int xuongduoi(khoigach *pkhoigach)
{
    for(int i=0;i<pkhoigach->hang;i++)

        for(int j=0;j<pkhoigach->cot;j++)

            if(pkhoigach->arr[i][j]==1)
            {
                if(xuong(pkhoigach->iboard+i,pkhoigach->jboard+j)==0) return 0;
            }


    pkhoigach->iboard+=1;
    return 1;
}
void gangiatri(khoigach *pkhoigach)
{
    for(int i=0;i<pkhoigach->hang;i++)

        for(int j=0;j<pkhoigach->cot;j++)

            if(pkhoigach->arr[i][j]==1)
            {
                board[pkhoigach->iboard+i][pkhoigach->jboard+j]=1;
            }


}
void xoaykhoigach(khoigach *pkhoigach)
{
    int **temparr;
    int temphang = pkhoigach->cot;
    int tempcot = pkhoigach->hang;
    // cap phat bo nho cho ma tran phu .
    temparr = (int**)malloc(temphang*sizeof(int*));
    for(int i=0;i<temphang;i++)
    {
        temparr[i] = (int*)malloc(tempcot*sizeof(int));
    }
    // xoay
    for(int i = pkhoigach->hang-1;i>=0;i--)

        for(int j=pkhoigach->cot-1;j>=0;j--)
        {
            temparr[j][pkhoigach->hang-i-1]=pkhoigach->arr[i][j];
        }

    // kiem tra xem co xoay duoc khong
    for(int i=0;i<temphang;i++)
    {
        for(int j=0;j<tempcot;j++)

            if(!thuocbang(pkhoigach->iboard+i,pkhoigach->jboard+j)||board[pkhoigach->iboard+i][pkhoigach->jboard+j]==1)
                return;

    }
    for(int i=0;i<pkhoigach->hang;i++)
        free(pkhoigach->arr[i]);
        free(pkhoigach->arr);
    pkhoigach->hang = temphang;
    pkhoigach->cot = tempcot;
    pkhoigach->arr = temparr;
}
