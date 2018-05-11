
int kiemtra(khoigach *pkhoigach , thongtin * thongtingame)
{
    int dem;
    int i = pkhoigach->hang-1;
    if(pkhoigach->iboard<=3) return -1;
    if(thongtingame->score>=300) return 0;
		do
		{
			dem=0;
			for(int j=0;j<maxj;j++)
			{
				if(board[pkhoigach->iboard+i][j]==1)	dem++;
			}
			if(dem==maxj)
			{
				capnhat(thongtingame,20);
				capnhatlaitoado(pkhoigach->iboard+i);
				trangthaibang();
				Beep(700,300);
			}
			else
			{
				i=i-1;
			}
		}while(i>=0);
    return 1;
}
