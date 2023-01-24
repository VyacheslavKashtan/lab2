#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;
int main()
{
    vector<char> symbols(50,'#');
    vector<char> alfavite;
    vector<int> qleft;
    vector<int> qright;
    vector<char> moveright;
    vector<char> symbleft;
    vector<char> symbright;
    vector<char> ukztl;
    symbols.reserve(100);
    alfavite.reserve(20);
    qleft.reserve(50);
    qright.reserve(50);
    moveright.reserve(50);
    symbleft.reserve(50);
    symbright.reserve(50);
    string path = "data.txt";
    ifstream datta;
    datta.open(path);
    if (!datta.is_open())
    {
       cout<<"closed"<<endl;
    }
    else    
    {
        cout<<"open"<<endl;
        char ch;
        int l=0;
        int kk=0; 
        int ukazetel=0;
        int rr;
        int r=0;
        while (datta.get(ch))
        {
            
            if (ch=='#')
            {
                cout<<"ukazetel"<<' ';
                while ((r)<(ukztl.size()))
                {
                    rr=ukztl[r]-'0';
                    ukazetel=10*ukazetel + rr;
                    ++r;
                }
                break;
            }
            ukztl.push_back(ch);
        }
        cout<<ukazetel<<endl;
        datta.get(ch);
        ukazetel=ukazetel-1;
        while (datta.get(ch))
        {
            if (ch=='#')
            {
                alfavite.push_back(ch);
                cout<<ch<<' ';
                break;
            }
            if ((ch)!=',')
            {
            alfavite.push_back(ch);
            cout<<ch<<' ';
            ++kk;
            }
            
        }//запис алфавіта
        cout<<endl;
        int k = ukazetel;
        datta.get(ch);
        while ((datta.get(ch)))
        {
                symbols[k] = ch;
                cout<<ch;
                if(symbols[k]=='#')
                {
                    cout<<endl;
                    break;
                }
            ++k;
        }//запис слова      
        int a1=0;
        int b1=0;
        int t1;
        int t0=0;
        while(a1<symbols.size())
        {
            cout<<symbols[a1];
            t1=symbols[a1];
            while(b1<alfavite.size())
            {
                if (alfavite[b1]==t1)
                {
                    ++t0;
                    
                }
                ++b1;
            }
            b1=0;
            ++a1;
        } //перевірка на алфавіт
        cout<<endl;
        if (symbols.size()!=t0)
        {
            cout<<"Wrong alfavite"<<endl;
            datta.close();
        }
        else
        {
            cout<<"Everything alright"<<endl;
        }
        datta.get(ch);
        
        while (!datta.eof( ))
        {
            datta.get();
            datta.get(ch);
            qleft.push_back(ch-'0');
            datta.get();
            datta.get(ch);
            symbleft.push_back(ch);
            datta.get();
            datta.get();
            datta.get(ch);
            qright.push_back(ch-'0');
            datta.get();
            datta.get(ch);
            symbright.push_back(ch);
            datta.get(ch);
            moveright.push_back(ch);
            datta.get(ch);
        }//запис команд
    
        int q=1;
        int w=0;
        
        k=ukazetel;
        while (q!=0)
        {
            
            while(w<qleft.size())
            {
                if (qleft[w]==q)
                {
                    if (symbleft[w]==symbols[k])
                    {
                        q=qright[w];
                        symbols[k]=symbright[w];
                        Sleep(1000);
                        {
                        for(char n0 : symbols)
                            cout << n0 << " ";
                        }
                        cout<<endl;
                        if (moveright[k]='R')
                        {
                            ++k;
                        }
                        else if (moveright[k]='L')
                        {
                            --k;
                        }
                    }
                }   
                ++w;
            }
        w=0;
        }
    }//відтворення команд на стрічці
    
    
    cout <<endl;
    alfavite.clear();
    symbols.clear();
    qleft.clear();
    qright.clear();
    moveright.clear();
    symbleft.clear();
    symbright.clear();
    datta.close();
    return 0;   
}