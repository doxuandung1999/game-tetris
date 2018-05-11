
// tao khung ...
void taobang()
{
    for(int i = rong;i<=rong+10+1;i++)
    {
        for(int j=dai;j<=dai+18+1;j++)
        {
            if((i==rong||i==rong+10+1)&&j>dai&&j<dai+18+1)
            {
                gotoxy(i,j); cout << char(186);
            }
            if((j==dai||j==dai+18+1)&&i>rong&&i<rong+10+1)
            {
                gotoxy(i,j); cout << char(205);
            }
        }
    }
    gotoxy(rong,dai);textcolor(11); cout << char(219);
    gotoxy(rong+10+1,dai);textcolor(11); cout << char(219);
    gotoxy(rong,dai+18+1);textcolor(11); cout << char(219);
    gotoxy(rong+10+1,dai+18+1); textcolor(11);cout << char(219);
}
 //maxi = hang tu tren xuong ;
//maxj = cot tu trai sang;
void trangthaibang()
{
    for(int i=0;i<maxi;i++)

        for(int j=0;j<maxj;j++)
        {
            if(board[i][j]==1&&i>=4)
            {
                gotoxy(j+rong+1,i+dai+1-4);textcolor(9); cout << char(2);
            }
            if(board[i][j]==0&&i>=4)
            {
                 textcolor(0) ;gotoxy(j+rong+1,i+dai+1-4);cout << " ";
            }
        }

}

void capnhatlaitoado(int hang)
{
    for(int i=hang;i>0;i--)

        for(int j=0;j<maxj;j++)
        {
            board[i][j]=board[i-1][j];
        }

}

