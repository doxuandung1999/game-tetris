
struct thongtin{
    int score;
    int level;
    float speed;
};
void hienthith (thongtin *th)
{
    th->level = 1;
    th->score= 0;
    th->speed=0.3;
}
int capnhat(thongtin *th , int score)
{
    th->score += score;
    if(th->score>=200&&th->level<2)
    {
        th->level ++;
        th->speed -=0.1;
    }
    return 0;
}
void inthongtin(thongtin th)
{
    textcolor(20);
    gotoxy(rong + maxj+3 , 10); cout << "score : "<< th.score;
    gotoxy(rong + maxj+3 , 11); cout << "level : "<< th.level;
    gotoxy(rong + maxj+3 , 12); cout << "speed : "<< th.speed;
}
