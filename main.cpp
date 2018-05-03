
#include "hotro.h"
#include "hienthi.h"
#include "thongtin.h"
#include "taogach.h"
#include "dichuyen.h"
#include "luatchoi.h"

int main(){
    int idkhoigachtieptheo;
    clock_t Start,End;
    char c;
    thongtin th;
    khoigach * cakhoi;
//    srand(time(0));
    cakhoi = taokhoigach(loai());
    idkhoigachtieptheo = loai();
    taobang();
    hienthith(&th);
    Nocursortype();
    do
    {
        inthongtin(th);
        vekhoigach(cakhoi);
        xoanext();
        venext(idkhoigachtieptheo);
        Start=clock();
        do
        {
        if(_kbhit())
        {
            c=toupper(getch());
            xoakhoigach(cakhoi);
            switch(c)
            {
                case 72:
                    xoaykhoigach(cakhoi);
                    break;
                case 75:
                    sangtrai(cakhoi);
                    break;
                case 77:
                    sangphai(cakhoi);
                case 80:
                    xuongduoi(cakhoi);
                    break;
            }
            vekhoigach(cakhoi);
        }
        End=clock();
        }while(float(End-Start)/CLK_TCK<th.speed);
        xoakhoigach(cakhoi);
        if(xuongduoi(cakhoi)==0)
        {
            gangiatri(cakhoi);
            int ketqua = kiemtra(cakhoi, &th);
            if((ketqua==-1||ketqua==0)) break;
            cakhoi = taokhoigach(idkhoigachtieptheo);
            idkhoigachtieptheo = loai();
        }
        trangthaibang();
    }while(1);
        textcolor(LIGHTGREEN);
        gotoxy(50,20) ; cout << "end game";
        _getch();
        return 0;

}
