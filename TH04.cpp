// Chu trinh Euler 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Doc File, Xuat file, xuat ma tran ke
// Tao dieu kien gi do de no tra ve 0 neu khong co chu trinh và tra ve 1 khi co chu trinh
// Day la do thi vo huong
// Gia su File xuat ra dc ma tran ke

#include <iostream>
#include <fstream>
#include <stack>
#include <string>
using namespace std;

bool kiemtraFiletontai(ifstream& fi) {
    bool cotontai = true;
    bool khongtontai = fi.fail();
    if (khongtontai == true) {
        cotontai = false;
    }
    return cotontai;

}

//chuyen tu danh sach ke sang ma tran ke
void docFile(ifstream& fi, int** a, int n) {
    int x, i;
    while (!fi.eof())
    {
        fi >> i;
        while (true)
        {
            fi >> x;
            if (x > 0)
                a[i][x] = 1;
            if (fi.eof())
                break;
            char c;
            fi.get(c);
            char ch[2] = { c };
            if (strcmp(ch, " ") != 0)
            {
                break;
            }
        }
    }
}

void xuatMatranke(int** a, int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

bool kiemtrabacchan(int sb) {
    if (sb % 2 == 0) {
        return true;
    }
    else {
        return false;
    }
}

// gia thuyet do thi là vo huong lien thong
// chỉ can kiem tra cac dinh la bac chan la okay
int kiemtradothi(int** a, int n) {
    int sobac = 0;
    for (int i = 1; i <= n; i++) {
        sobac = 0;
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 1) {
                sobac++;
            }
            //cout << "Dinh " << i << " co " << sobac << " bac\n";
            
        }  
        if (kiemtrabacchan(sobac) == false) {
            return 0;
            break; // toi uu chuong trinh
        }
        else {
            return 1;
        }
    }

}

void chutrinhEuler(int** a, int n, int u) {
    stack<int> st, CE;
    st.push(u);
    while (!st.empty()) {
        int counter = 0;
        int s = st.top(); 
        for (int i = 1; i <= n; i++) {
            if (a[s][i] == 0) {
                counter++;
            }
        }
        if (counter != n) {
            for (int t = 1; t <= n; t++) {
                if (a[s][t] == 1) {
                    st.push(t);
                    a[s][t] = a[t][s] = 0;
                    break;
                }
            }
        }
        else {
            CE.push(s);
            st.pop(); // trường hợp u và s giống nhau nên phải pop một giá trị 
        }
    }
    cout << "Chu trinh Euler: " << endl;
    while (!CE.empty()) {
        cout << CE.top() << " ";
        CE.pop();
    }
}

int main()
{
    cout << "[TH04]Chu trinh Euler --- 2051120333/Tcheng Nhu Quan\n";
    ifstream fi("data.txt");
    kiemtraFiletontai(fi);
    if (kiemtraFiletontai(fi) == true) {
        cout << "File ton tai\n";
    }
    else {
        cout << "Loi. File khong ton tai!\n";
    }

    int n = 0;
    fi >> n;
    string s;
    getline(fi, s);

    int** a = new int* [n + 1];
    for (int i = 1; i <= n; i++)
        a[i] = new int[n + 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) a[i][j] = 0;

    docFile(fi, a, n);
    cout << "Xuat ma tran ke cua do thi la: " << endl;
    xuatMatranke(a, n);
    cout << "------------\n";
    int ketqua = kiemtradothi(a, n);
    if (ketqua == 0) {
        cout << 0;
    }
    else {
        cout << 1 << endl;
        int u;
        cout << "Nhap dinh bat dau: ";
        cin >> u;
        chutrinhEuler(a, n, u);
    }

    fi.close();


    for (int i = 1; i <= n; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}


