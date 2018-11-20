#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <ctime>
#include <time.h>
#include <iomanip>
#include <fstream>
#include <typeinfo>
#include <vector>
#include <algorithm>

using namespace std;

enum tp
{
    kapellmeister,
    pianist,
    violinist,
    orchestra
};

class date
{
protected:
    int year;
    int month;
    int day;
public:
    date();
    date(int d, int m, int y);
    date(const date&);
    virtual int getd();
    virtual int getm();
    virtual int gety();
    virtual void reinit(int d, int m, int y);
    virtual void show()
    {
        cout << "Date: " << day << "." << month << "." << year;
    }
    friend ostream& operator<< (ostream& os, const date& dt);
    friend istream& operator>> (istream& stream, const date& dt);
};

istream& operator>> (istream& stream, date& dt)
{
    int year, month, day;
    cin >> year >> month >> day;
    dt.reinit(day, month, year);
    return stream;
}

ostream& operator<< (ostream& os, const date& dt)
{
    os.width(7);
    os << dt.day ;
    os << ".";
    os.width(2);
    os << dt.month;
    os << ".";
    os << dt.year;
    return os;
}

date::date()
{
    year = 1990;
    month = 1;
    day = 1;
}

date::date(int d, int m, int y)
{
    year = y;
    month = m;
    day = d;
}

date::date(const date& p)
{
    *this = p;
}

date::getd()
{
    return day;
}

date::getm()
{
    return month;
}

date::gety()
{
    return year;
}

void date::reinit(int d, int m, int y)
{
    year = y;
    month = m;
    day = d;
}

class musician
{
protected:
    int type;
public:
    musician();
    musician(int t);
    virtual void reinit(int t);
    musician(const musician&);
    musician(const musician*);
    virtual void show()
    {
        switch(type)
        {
            case kapellmeister: cout << "Kapellmeister";break;
            case pianist: cout << "Pianist";break;
            case violinist: cout << "Violinist"; break;
            case orchestra: cout << "Orchestra";break;
            default: cout << "ERROR";
        }
    }
    friend ostream& operator<< (ostream& os, const musician& mt);
    friend istream& operator>> (istream& stream, const musician& mt);
};

istream& operator>> (istream& stream, musician& mt)
{
    string temp;
    cin >> temp;
    if (temp == "Kapellmeister") mt.reinit(kapellmeister);
    else if (temp == "Pianist") mt.reinit(pianist);
    else if (temp == "Violinist") mt.reinit(violinist);
    else if (temp == "Orchestra") mt.reinit(orchestra);
    else cout << "ERROR";
    return stream;
}

void musician::reinit(int t)
{
    type = t;
}

ostream& operator<< (ostream& os, const musician& mt)
{
    os.width(14);
    switch(mt.type)
    {
        case kapellmeister: os << "Kapellmeister";break;
        case pianist: os << "Pianist";break;
        case violinist: os << "Violinist"; break;
        case orchestra: os << "Orchestra";break;
        default: os << "ERROR";
    }
    return os;
}

musician::musician()
{
    type = kapellmeister;
}

musician::musician(int t)
{
    type = t;
}

musician::musician(const musician& p)
{
    *this = p;
}

musician::musician(const musician* p)
{
    *this = *p;
}

class person : public date
{
protected:
    string surname;
    string name;
public:
    person();
    person(string s, string n, int d, int m, int y);
    person(string s, string n, date tmp);
    person(const person&);
    string get_person_name() {return name;}
    string get_person_surname() {return surname;}
    void reinit(string s, string n);
    void show()
    {
        cout << "Name: " << name << " Surname: " << surname << "Birth ";
        date::show();
    }
    friend ostream& operator<< (ostream& os, const person& pt);
    friend istream& operator>> (istream& stream, const person& pt);
};

istream& operator>> (istream& stream, person& pt)
{
    string snm, nm;
    stream >> (date&)pt;
    stream >> snm >> nm;
    pt.reinit(snm,nm);
    return stream;
}

ostream& operator<< (ostream& os, const person& pt)
{
        os << "Name: " << pt.name << " Surname: " << pt.surname << "Birth " << (date&)pt;
        return os;
}

void person::reinit(string s, string n)
{
    surname = s;
    name = n;
}

person::person()
{
    surname = "Black";
    name = "John";
    day = 22;
    month = 4;
    year = 1994;
}

person::person(string s, string n, int d, int m, int y)
{
    surname = s;
    name = n;
    day = d;
    month = m;
    year = y;
}

person::person(string s, string n, date tmp)
{
    surname = s;
    name = n;
    day = tmp.getd();
    month = tmp.getm();
    year = tmp.gety();
}

person::person(const person& p)
{
    *this = p;
}

class performer : public person, public musician
{
public:
    performer();
    performer(string s, string n, int d, int m, int y, int t);
    performer(string s, string n, date tmp, int t);
    performer(const performer&);
    void show()
    {
        person::show();
        musician::show();
    }
    friend ostream& operator<< (ostream& os, const performer& pr);
    friend istream& operator>> (istream& stream, const performer& pr);
};

istream& operator>> (istream& stream, performer& pr)
{
    stream >> (person&)pr >> (musician&)pr;
    return stream;
}

ostream& operator<< (ostream& os, const performer& pr)
{
    os << (person&)pr << (musician&)pr;
    return os;
}

performer::performer()
{
    surname = "Black";
    name = "John";
    day = 22;
    month = 4;
    year = 1994;
    type = kapellmeister;
}

performer::performer(string s, string n, int d, int m, int y, int t)
{
    surname = s;
    name = n;
    day = d;
    month = m;
    year = y;
    type = t;
}

performer::performer(string s, string n, date tmp, int t)
{
    surname = s;
    name = n;
    day = tmp.getd();
    month = tmp.getm();
    year = tmp.gety();
    type = t;
}

performer::performer(const performer& p)
{
    *this = p;
}

class composition: public person
{
protected:
    string name;
    int numb;
    string description;
    date cr;
public:
    composition();
    composition(string n, int nm, string descr, int d, int m, int y, string pn, string ps, int pd, int pm, int py);
    composition(const composition&);
    composition(const composition*);
    string get_name() {return name;}
    int get_numb() {return numb;}
    void reinit(string n, int nm, string descr, date tcr);
    void reinit_long(string n, int nm, string descr, int d, int m, int y, string pn, string ps, int pd, int pm, int py);
    void randomize(int ind);
    void show()
    {
        cout << "Composition name:  " << name << "  No." << numb << "\nDescription: " << description << "\nCreation ";
        cr.show();
    }
    friend ostream& operator<< (ostream& os, const composition& ct);
    friend istream& operator>> (istream& stream, const composition& ct);
};

istream& operator>> (istream& stream, composition& ct)
{
    string name;
    int numb;
    string description;
    date cr;
    stream >> (person&)ct;
    stream >> name >> numb >> description >> cr;
    ct.reinit(name, numb, description, cr);
    return stream;
}

ostream& operator<< (ostream& os, const composition& ct)
{
    //os << "Composition name:  ";
    os.width(40);
    os << ct.name;
    os.width(6);
    os << "  No." << ct.numb;
    //os << "\nDescription: ";
    //os << ct.description;
    //os << "\nCreation ";
    os << (date&)ct.cr;
    return os;
}

void composition::reinit(string n, int nm, string descr, date tcr)
{
    name = n;
    numb = nm;
    description = descr;
    cr = tcr;
}

void composition::reinit_long(string n, int nm, string descr, int d, int m, int y, string pn, string ps, int pd, int pm, int py)
{
    name = n;
    numb = nm;
    description = descr;
    cr.reinit(d,m,y);
    person::name = pn;
    person::surname = ps;
    day = pd;
    month = pm;
    year = py;
}

void composition::randomize(int ind)
{
    switch(ind)
    {
    case 0:
    name = "Ride of the Valkyries";
    description = "The \"Ride of the Valkyries\" refers to the beginning of act 3 of Die Walkure, the second of the four operas constituting Richard Wagner's Der Ring des Nibelungen.";
    cr.reinit(23,7,1851);
    person::name = "Richard";
    person::surname = "Wagner";
    day = 22;
    month = 5;
    year = 1813;
    break;

    case 1:
    name = "La halte des Calmouckes";
    description = "Text is available under the Creative Commons Attribution-ShareAlike License.";
    cr.reinit(23,4,1761);
    person::name = "Christoph";
    person::surname = "Gluck";
    day = 22;
    month = 8;
    year = 1714;
    break;

    case 2:
    name = "Triumph March";
    description = "Op. 40: Triumph March for large orchestra and chorus.";
    cr.reinit(16,9,1892);
    person::name = "Alexander";
    person::surname = "Glazunov";
    day = 12;
    month = 6;
    year = 1865;
    break;

    case 3:
    name = "So You Want to Write a Fugue?";
    description = "Completed original work, for 4 solo voices & piano or string quartet.";
    cr.reinit(16,9,1963);
    person::name = "Glenn";
    person::surname = "Gould";
    day = 25;
    month = 9;
    year = 1932;
    break;
    }
    numb = ind + 1;
}

composition::composition()
{
    name = "Ride of the Valkyries";
    numb = 1;
    description = "The \"Ride of the Valkyries\" refers to the beginning of act 3 of Die Walkure, the second of the four operas constituting Richard Wagner's Der Ring des Nibelungen.";
    cr.reinit(23,7,1851);
    person::name = "Richard";
    person::surname = "Wagner";
    day = 22;
    month = 5;
    year = 1813;
}

composition::composition(string n, int nm, string descr, int d, int m, int y, string pn, string ps, int pd, int pm, int py)
{
    name = n;
    numb = nm;
    description = descr;
    cr.reinit(d,m,y);
    person::name = pn;
    person::surname = ps;
    day = pd;
    month = pm;
    year = py;
}

composition::composition(const composition& p)
{
    *this = p;
}

composition::composition(const composition* p)
{
    *this = *p;
}

class perfomance : public composition
{
protected:
    composition *arr;
    musician *mlist;
    int sec;
    date pdate;
    int n;
    int ki;
public:
    perfomance();
    perfomance(musician *lst, int k, int s, date pdo);
    perfomance(musician *lst, int k, int s, int d, int m, int y);
    perfomance(const perfomance&);
    int gett();
    int get_arr_size() {return ki;}
    composition& operator[] (int i);
    void show()
    {
        cout << "Compositions list: \n";
        for (int i(0); i < ki; i++)
        {
            (*(arr + i)).show();
            cout << endl;
        }
        cout << "\nMusicians list: \n";
        for (int i(0); i < n; i++)
        {
            (*(mlist + i)).show();
            cout << endl;
        }
        cout << "\nTime:  " << sec << "\nComposition ";
        pdate.show();
    }

    void WriteFile();
    void WriteFileBinary();

    friend ostream& operator<< (ostream& os, const perfomance& pn);
};

void perfomance::WriteFile()
{
      ofstream file_out("file_single_out.txt");
      file_out << *this;
      file_out.close();
}

void perfomance::WriteFileBinary()
{
      ofstream file_out("file_binary_out.txt", ios_base::binary);
      file_out << *this;
      file_out.close();
}

ostream& operator<< (ostream& os, const perfomance& pn)
{
        os << "Compositions list: \n";
        os.width(40);
        os << "Composition name";
        os.width(6);
        os << "  Number";
        os << "  Creation date\n\n";
        for (int i(0); i < pn.ki; i++)
        {
            os << (composition&)pn.arr[i];
            os << endl;
        }
        os << "\nMusicians list: \n";
        for (int i(0); i < pn.n; i++)
        {
            os << (musician&)pn.mlist[i];
            os << endl;
        }
        os << "\nTime:  " << pn.sec << "\nComposition " << (date&)pn.pdate;
        return os;
}


perfomance::gett()
{
    return sec;
}

perfomance::perfomance()
{
    n = 5;
    mlist = new musician [n];
    for(int i(0); i < n; i++)
    {
        *(mlist + i) = rand() % 4;
    }
    sec = rand() % 4500 + 5000;
    pdate.reinit(rand() % 30 + 1, rand() % 12 + 1, rand() % 25 + 2000);
    ki = 22000;
    arr = new composition [ki];
    for(int i(0); i < ki; i++)
    {
        (*(arr + i)).randomize(rand() % 4);
    }
}

perfomance::perfomance(musician *lst, int k, int s, date pdo)
{
    n = 10;
    mlist = new musician [k];
    for(int i(0); i < k; i++)
    {
        *(mlist + i) = *(lst + i);
    }
    sec = s;
    pdate = pdo;
    ki = k;
    arr = new composition [ki];
    for(int i(0); i < ki; i++)
    {
        (*(arr + i)).randomize(rand() % 4);
    }
}

perfomance::perfomance(musician *lst, int k, int s, int d, int m, int y)
{
    n = 10;
    mlist = new musician [k];
    for(int i(0); i < k; i++)
    {
        *(mlist + i) = *(lst + i);
    }
    sec = s;
    date dt(d,m,y);
    ki = k;
    arr = new composition [ki];
    for(int i(0); i < ki; i++)
    {
        (*(arr + i)).randomize(rand() % 4);
    }
}

perfomance::perfomance(const perfomance& p)
{
    *this = p;
}

composition &perfomance::operator[] (int i)
{
    if(i < 0)
    {
        cout << "INVALID INDEX" << endl;
        exit(1);
    }
    return *(arr + i);
}

template<class T>
double func (perfomance *arr, T n)
{
    double H = 0;
    for(int i(0); i < n; i++)
    {
        H += 1./ (arr+i) -> gett();
    }
    return ((double)n - 1) / H;
}

template <class A>
class perfomance_new : public composition
{
protected:
    A *arr;
    musician *mlist;
    int sec;
    date pdate;
    int n;
    int ki;
public:
    perfomance_new();
    perfomance_new(musician *lst, int k, int s, date pdo);
    perfomance_new(musician *lst, int k, int s, int d, int m, int y);
    perfomance_new(const perfomance_new&);
    int gett();
    void show()
    {
        cout << "Compositions list: \n";
        for (int i(0); i < ki; i++)
        {
            (*(arr + i)).show();
            cout << endl;
        }
        cout << "\nMusicians list: \n";
        for (int i(0); i < n; i++)
        {
            (*(mlist + i)).show();
            cout << endl;
        }
        cout << "\nTime:  " << sec << "\nComposition ";
        pdate.show();
    }
};

template <class A>
perfomance_new<A>::gett()
{
    return sec;
}

template <class A>
perfomance_new<A>::perfomance_new()
{
    n = 5;
    mlist = new musician [n];
    for(int i(0); i < n; i++)
    {
        *(mlist + i) = rand() % 4;
    }
    sec = rand() % 4500 + 5000;
    pdate.reinit(rand() % 30 + 1, rand() % 12 + 1, rand() % 400 + 1500);
    ki = 600;
    arr = new A [ki];
    for(int i(0); i < ki; i++)
    {
        (*(arr + i)).randomize(rand() % 4);
    }
}

template <class A>
perfomance_new<A>::perfomance_new(musician *lst, int k, int s, date pdo)
{
    n = k;
    mlist = new musician [k];
    for(int i(0); i < k; i++)
    {
        *(mlist + i) = *(lst + i);
    }
    sec = s;
    pdate = pdo;
    ki = rand() % 12 + 3;
    arr = new A [ki];
    for(int i(0); i < ki; i++)
    {
        (*(arr + i)).randomize(rand() % 4);
    }
}

template <class A>
perfomance_new<A>::perfomance_new(musician *lst, int k, int s, int d, int m, int y)
{
    n = k;
    mlist = new musician [k];
    for(int i(0); i < k; i++)
    {
        *(mlist + i) = *(lst + i);
    }
    sec = s;
    date dt(d,m,y);
    ki = rand() % 12 + 3;
    arr = new A [ki];
    for(int i(0); i < ki; i++)
    {
        (*(arr + i)).randomize(rand() % 4);
    }
}

template <class A>
perfomance_new<A>::perfomance_new(const perfomance_new& p)
{
    *this = p;
}

void SortDynamicArraySymbol(perfomance a)
{
    string temp;
    string *arrStr = new string[a.get_arr_size()];
    for (int i = 0; i < a.get_arr_size(); i++)
    {
        arrStr[i] = a[i].get_name();
    }
    for (int i = 1; i <= a.get_arr_size(); i++)
    {
        for (int j = 0; j < a.get_arr_size() - i; j++)
        {
            if (strcmp(arrStr[j].c_str(), arrStr[j + 1].c_str()) > 0)
            {
                temp = arrStr[j];
                arrStr[j] = arrStr[j + 1];
                arrStr[j + 1] = temp;
            }
        }
        for (int i = 0; i < a.get_arr_size(); i++)
        {
            //cout << arrStr[i] << endl;
        }
    }
}

void SortDynamicArrayInt(perfomance a)
{
    int temp;
    int *arrInt = new int[a.get_arr_size()];
    for (int i = 0; i < a.get_arr_size(); i++)
    {
        arrInt[i] = a[i].get_numb();
    }

    for (int i = 1; i <= a.get_arr_size(); i++)
    {
        for (int j = 0; j < a.get_arr_size() - i; j++)
        {
            if (*(arrInt + j) > *(arrInt + j + 1))
            {
                temp = *(arrInt + j);
                *(arrInt + j) = *(arrInt + j + 1);
                *(arrInt + j + 1) = temp;
            }
        }
    }
    for (int i = 0; i < a.get_arr_size(); i++)
    {
        //cout << arrInt[i] << endl;
    }
}

void ReadWriteFileWithArrayOfPointers(perfomance a)
{
    composition b;
    composition *pb = &a;
    cout << "pointer on :  " << typeid(pb).name() << endl;
    cout << "*pointer on :  " << typeid(*pb).name() << endl << endl;

    composition **pp = new composition *[a.get_arr_size()];
    for (int i = 0; i < a.get_arr_size(); i++)
    {
        pp[i] = new composition[8];
    }
    int pp_count, number, creation_day, creation_month, creation_year;
    int creator_day, creator_month, creator_year;
    string name, description, creator_name, creator_surname;
    a.WriteFile();
    ifstream fin("file_single_out.txt");
    if (!fin.is_open())
    {
        cout << "Can't open file!\n";
    }
    else
    {
        fin >> pp_count;
        for (int i = 0; i < pp_count; i++)
        {
              fin >> name >> number >> description >> creation_day >> creation_month >> creation_year>> creator_name >> creator_surname >> creator_day >> creator_month >> creator_year;
              pp[i]->reinit_long(name, number, description, creation_day, creation_month, creation_year, creator_name, creator_surname, creator_day, creator_month, creator_year);
        }
        fin.close();
    }

    ofstream f_out("file_pp_out.txt");
    f_out << pp_count;
    for (int i = 0; i < a.get_arr_size(); i++)
    {
        f_out << "       ";
        f_out << *pp[i] << endl;
    }
  f_out.close();
}

void CompareVectorVsDynamicArr(perfomance a) {

    vector<string> myVector;
    for (int i = 0; i < a.get_arr_size(); i++)
    {
        myVector.push_back(a[i].get_name());
    }
    clock_t t1;
    t1 = clock();
    sort(myVector.begin(), myVector.end());
    cout << "String vector Sorted by Function: " << endl;
    for (int i = 0; i < a.get_arr_size(); i++)
    {
        //cout << myVector[i] << endl;
    }
    t1 = clock() - t1;
    printf("\nIt took me %d clicks (%f seconds).\n", (int)t1, ((double)t1) / CLOCKS_PER_SEC);
    cout << endl << endl;

    clock_t t2;
    t2 = clock();
    cout << "String dynamic array sorted by my sort function: " << endl;
    SortDynamicArraySymbol(a);
    t2 = clock() - t2;
    printf("\nIt took me %d clicks (%f seconds).\n", (int)t2, ((double)t2) / CLOCKS_PER_SEC);

    vector<int> myVectorInt;
    for (int i = 0; i < a.get_arr_size(); i++)
    {
        myVectorInt.push_back(a[i].get_numb());
    }
    clock_t t3;
    t3 = clock();
    sort(myVectorInt.begin(), myVectorInt.end());
    cout << "int vector Sorted by Function: " << endl;
    for (int i = 0; i < a.get_arr_size(); i++)
    {
        // cout << myVectorInt[i] << endl;
    }
    t3 = clock() - t3;
    printf("\nIt took me %d clicks (%f seconds).\n", (int)t3, ((double)t3) / CLOCKS_PER_SEC);
    cout << endl << endl;

    clock_t t4;
    t4 = clock();
    cout << "Int dynamic array sorted by my sort function: " << endl;
    SortDynamicArrayInt(a);
    t4 = clock() - t4;
    printf("\nIt took me %d clicks (%f seconds).\n", (int)t4, ((double)t4) / CLOCKS_PER_SEC);
}

class ExceptionInt
{
public:
    int errNum;
    ExceptionInt() { errNum = 1; }
    ExceptionInt(int s) { errNum = s; }
};

class ExceptionStr : virtual public ExceptionInt
{
public:
    string errStr;
    ExceptionStr() { errStr = "OK"; }
    ExceptionStr(string s) { errStr = s; }
    ExceptionStr(int s) { errNum = s; }
};

int main()
{
    /*
    int X;
    cout << "Input X:\n";
    cin >> X;
    clock_t a = clock();
    perfomance *obj = new perfomance [X];
    cout << "Harmony average:   " <<func(obj, X);
    cout << "\n\nTime:  " << (double)(clock() - a)/1000 << " Seconds";
    */
   /* perfomance obj;
    cout << obj;
    obj.WriteFile();
    obj.WriteFileBinary();*/
    try
    {
        person a("xxx","noname", 22 , 1 ,2000);
        cout << a << endl;
        if (a.get_person_name() == "noname") throw ExceptionStr(2);
        else if (a.getm() < 0) throw ExceptionStr(404);
        else if (a.gety() > 2007) throw ExceptionStr(" TOO YOUNG");
        else if (a.getd() >= 32) ExceptionStr("  WRONG DAY");
        else
        {
            cout << a << endl;
        }
    }

    catch (ExceptionStr obj)
    {
        if (obj.errStr == "")
        {
            cout << "ERROR " << obj.errNum << endl;
        }
        else
        {
            cout << obj.errStr << endl;
        }
    }

    catch (ExceptionInt obj)
    {
        cout << "ERROR "<< obj.errNum << "Number error!!" << endl;
    }

    perfomance obj;
    CompareVectorVsDynamicArr(obj);
    return 0;
}
