#include <iostream>
#include<iomanip>
#include<math.h>

using namespace std;

float encrypt[3][3], decrypt[3][3], a[3][3], b[3][3], mes[3][3], c[3][3];
string msg;
char pesan[3][3];
float determinan=0;
void getMatriks();
void enkripsi();
void dekripsi();
void findDeterminant();
void adjoint();
void inverse();
int main()
{
      getMatriks();
      cout << "========================Enkripsi========================" << endl;
      enkripsi();

      cout << "\n========================Dekripsi========================" << endl;
      dekripsi();
    return 0;
}

void findDeterminant(){
    for(int r = 0; r < 3; r++){
        determinan = determinan + (a[0][r] * (a[1][(r+1)%3] * a[2][(r+2)%3] - a[1][(r+2)%3] * a[2][(r+1)%3]));
    }
    cout << "Determinan = " << determinan;
}

void adjoint(){
    cout<<"\nMatriks adjoin: \n";
    for(int r = 0; r < 3; r++){
        for(int c = 0; c < 3; c++){
            cout<<((a[(c+1)%3][(r+1)%3] * a[(c+2)%3][(r+2)%3]) - (a[(c+1)%3][(r+2)%3] * a[(c+2)%3][(r+1)%3]))<<" ";
        }
        cout<<endl;
    }
}

void inverse(){
        cout<<"\nInvers matriks kunci: \n";
        for(int r = 0; r < 3; r++){
            for(int c = 0; c < 3; c++){
                b[r][c] = ((a[(c+1)%3][(r+1)%3] * a[(c+2)%3][(r+2)%3]) - (a[(c+1)%3][(r+2)%3] * a[(c+2)%3][(r+1)%3]))/determinan;

                cout<< b[r][c] <<" ";
            }
            cout<<endl;
        }
    }
void getMatriks() {
    int i, j;
    int k=0;
    int l=0;
    int m=0;
    string key = "udinusmrv";

    cout << "Matriks kunci = " << key;
    cout << "\nMatriks dari [" << key << "] adalah = " << endl;
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++) {
            c[i][j] = key[k] - 97;
            a[i][j] = c[i][j];
            cout << a[i][j] << " ";
            k++;
        }
        cout << endl;
    }

    msg = "cobahcphr";
    cout << "\nMatriks plaintext = " << msg;
    cout << "\nMatriks dari [" << msg << "] adalah = " << endl;

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++) {
            pesan[i][j] = msg[m];
            cout << pesan[i][j] << " ";
            m++;
        }
        cout << endl;
    }
    cout << endl;
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++) {
            mes[i][j] = msg[l] - 97;
            cout << mes[i][j] << " ";
            l++;
        }
        cout << endl;
    }
    cout << endl;
}

void enkripsi() {
    int i, j, k;

    cout << "Matrik kunci dikali dengan matriks [" << msg << "]"<< endl;

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            for (k = 0; k < 3; k++){
                encrypt[i][j] += a[i][k] * mes[k][j];
            }
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << "*" << endl;

    for (i = 0; i < 3; i++){
        for (j = 0; j < 1; j++){
            for (k = 0; k < 3; k++){
                cout << mes[i][k] << " ";
            }
            cout << endl;
        }
    }
    cout << "\nHasil perkalian matriks [" << msg << "] dengan matriks kunci = " << endl;

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            cout << encrypt[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nHasil perkalian matriks [" << msg << "] dengan matriks kunci dimodulo 26 = " << endl;

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            cout << fmod(encrypt[i][j], 26) << " ";
        }
        cout << endl;
    }

    cout << "\nHasil enkripsi: ";

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            cout << (char)(fmod(encrypt[i][j], 26) + 97);
        }
    }
}
void dekripsi() {
    int i, j, k;

    findDeterminant();
    adjoint();
    inverse();

    cout << "\nInverse matriks kunci dikali dengan matriks enkripsi [" << msg << "] = " << endl;
    for (i = 0; i < 3; i++){
        for (j = 0; j < 1; j++){
            for (k = 0; k < 3; k++){
                cout << b[i][k] << " ";
            }
        }
        cout << endl;
    }

    cout << "*" << endl;

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            cout << encrypt[i][j] << " ";
        }
        cout << endl;
    }

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            for (k = 0; k < 3; k++){
                decrypt[i][j] += b[i][k] * encrypt[k][j];
            }
        }
    }

    cout << "\nHasil perkalian matriks inverse dengan matriks enkripsi [" << msg << "] = " << endl;

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            cout << (int)decrypt[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nHasil perkalian matriks inverse dengan matriks enkripsi [" << msg << "] dimodulo 26 = " << endl;

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            cout << fmod((int)decrypt[i][j], 26) << " ";
        }
        cout << endl;
    }

    cout << "\nHasil dekripsi: ";

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            cout << (char) (fmod((int)decrypt[i][j], 26)+ 97);
        }
    }
    cout << "\n";
}
