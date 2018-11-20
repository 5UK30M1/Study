#include <iostream>
#include <string.h>

using namespace std;

class date
{
protected:
    int year;
    int month;
    int day;
public:
    date();
    date(int y, int m, int d);
    date(const date&);
    virtual void show()
    {
        cout << day << "." << month << "." << year;
    }
};

class book
{
protected:
    char *author;
    char *name;
    double price;
public:
    book();
    book(char *a, char *n, double p);
    book(const book&);
    virtual void show()
    {
        cout << "\nBook:\tAuthor:  " << author << ";\tName: \"" << name << "\";\tPrice:  " << price;
    }
};

class seller: public date
{
protected:
    char *surname;
    char *name;
    date bd;
public:
    seller();
    seller(char *a, char *n, date bd);
    seller(const seller&);
    void show()
    {
        cout << "\nSeller:\tSurname:  " << surname << ";\tName: " << name << ";\tBirth: ";
        bd.show();
    }
};

class sellop: public seller, public book
{
protected:
    int numb;
public:
    sellop();
    sellop(int n);
    sellop(int oy, int om, int od, char * ss, char *sn, date sbd, char *ba, char *bn, double bp, int n);
    sellop(int oy, int om, int od, char * ss, char *sn, int sly, int slm, int sld, char *ba, char *bn, double bp, int n);
    sellop(const sellop&);
    sellop(const sellop*);
    int getd();
    void show()
    {
        date::show();
        seller::show();
        book::show();
        cout << endl;
    }
};

sellop::sellop()
{
    numb = 20;
}

sellop::sellop(int oy, int om, int od, char * ss, char *sn, date sbd, char *ba, char *bn, double bp, int n)
{
    year = oy;
    month = om;
    day = od;
    surname = new char [strlen(ss)];
    strcpy(surname, ss);
    seller::name = new char [strlen(sn)];
    strcpy(seller::name, sn);
    bd = sbd;
    author = new char [strlen(ba)];
    strcpy(author, ba);
    book::name = new char [strlen(bn)];
    strcpy(book::name, bn);
    price = bp;
    numb = n;
}

sellop::sellop(int oy, int om, int od, char * ss, char *sn, int sly, int slm, int sld, char *ba, char *bn, double bp, int n)
{
    year = oy;
    month = om;
    day = od;
    surname = new char [strlen(ss)];
    strcpy(surname, ss);
    seller::name = new char [strlen(sn)];
    strcpy(seller::name, sn);
    date sbd(sly, slm, sld);
    bd = sbd;
    author = new char [strlen(ba)];
    strcpy(author, ba);
    book::name = new char [strlen(bn)];
    strcpy(book::name, bn);
    price = bp;
    numb = n;
}

sellop::sellop(int n)
{
    numb = n;
}

sellop::sellop(const sellop& p)
{
    *this = p;
}

sellop::sellop(const sellop* p)
{
    *this = *p;
}

sellop::getd()
{
    int m = date::month;
    int y = date::year;
    int d = date::day;
    int temp;
    while(m > 1)
    {
         if(m < 8)
            {
                if(m % 2)
                {
                    temp = 30;
                }
                else
                {
                    temp = 31;
                    if (m == 2)
                    {
                        if (y % 4 && y % 400 && !(y % 100))
                        {
                            temp = 28;
                        }
                        else
                        {
                            temp = 29;
                        }
                    }
                }
            }
            else
            {
                if(m % 2)
                {
                    temp = 31;
                }
                else
                {
                    temp = 30;
                }
            }
            d += temp;
            m--;
        }
        while(y > 1)
        {
            if (y % 4 && y % 400 && !(y % 100))
            {
                temp = 365;
            }
            else
            {
                temp = 366;
            }
            d += temp;
            y--;
        }
        return d;
}

class listsellop: public sellop
{
    sellop *info;
public:
    listsellop();
    listsellop(sellop *tinfo, int n);
    listsellop(const listsellop&);
    void show()
    {
        cout << "List of sells\n\nDate of first day:\n";
        date::show();
        cout << endl;
        cout << endl;
        int j = 0;
        for(;info[j].getd() <= info[0].getd() + 7; j++)
        {
            cout << "Sell number:  " << j + 1 << endl;
            info[j].show();
            cout << endl;
        }
        cout << endl;
    }
};

listsellop::listsellop()
{
    info = new sellop[45];
}


listsellop::listsellop(sellop *tinfo, int n)
{
    info = new sellop[n];
    for(int i = 0; i < n; i++)
    {
        info[i] = tinfo[i];
    }
}


listsellop::listsellop(const listsellop& p)
{
    *this = p;
}

seller::seller()
{
    date temp(1990,8,12);
    bd = temp;
    surname = "Peterson";
    name = "Peter";
}

seller::seller(char *s, char *n, date bd)
{
    surname = new char [strlen(s)];
    strcpy(surname, s);
    name = new char [strlen(n)];
    strcpy(name, n);

}

seller::seller(const seller& p)
{
    *this = p;
}

book::book()
{
    author = "Dante";
    name = "Comedy";
    price = 50;
}

book::book(char *a, char *n, double p)
{
    author = new char [strlen(a)];
    strcpy(author, a);
    name = new char [strlen(n)];
    strcpy(name, n);
    price = p;
}

book::book(const book& p)
{
    *this = p;
}

date::date()
{
    year = 2017;
    month = 10;
    day = 15;
}

date::date(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
}

date::date(const date& p)
{
    *this = p;
}

int main()
{
    date b_slr(1992,6,3);
    sellop *lst = new sellop[6];
    lst[0] = new sellop(2017, 10, 11, "Black", "John", b_slr, "Shakespeare", "Hamlet", 49.99, 7);
    lst[1] = new sellop(2017, 10, 13, "Black", "John", b_slr, "Shakespeare", "Hamlet", 49.99, 3);
    lst[2] = new sellop(2017, 10, 14, "Black", "John", b_slr, "Shakespeare", "Hamlet", 49.99, 8);
    lst[3] = new sellop(2017, 10, 15, "Black", "Peter", 1990, 12, 10, "Shakespeare", "Hamlet", 49.99, 2);
    lst[4] = new sellop(2017, 10, 16, "Black", "John", b_slr, "Shakespeare", "Hamlet", 49.99, 22);
    lst[5] = new sellop(2017, 10, 22, "Black", "John", b_slr, "Shakespeare", "Hamlet", 49.99, 4);

    listsellop obj(lst, 5);


    cout << endl << endl << sizeof(b_slr) << endl;
    obj.show();
    return 0;
}
