#include<iostream>

using namespace std;

class poly{

    private:
        int **p;
        int d,in;
    public:
        poly(int de);
        void create();
        void display();
        void insert(int a, int b);
        void add(poly p1);
        ~poly(){
            delete []p;
        }

};

poly::poly(int de){

    d=de;
    in=0;
    p = new int *[2];
    for(int i=0;i<2;i++){
        p[i] = new int [de];
    }

}

void poly::insert(int a,int b){

    p[0][in]=a;
    p[1][in]=b;
    in++;

}

void poly::create(){

        for(int j=0;j<=d;j++){
            cout<<"deg"<<endl;
            cin>>p[0][j];
            cout<<"coeff"<<endl;
            cin>>p[1][j];
        }
        cout<<endl;

}

void poly::display(){

    for(int i=0;i<2;i++){
        for(int j=0;j<=d;j++){
            cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }

}

void poly::add(poly p1){
    int i=0;
    poly result(d);
    while(i<d+1){
        result.insert(i,(p[1][i]+p1.p[1][i]));
        i++;
    }
    cout<<"success"<<endl;
    result.display();
}

int main(void){
    int deg;
    cout<<"max degree for poly"<<endl;
    cin>>deg;
    poly p(deg);
    poly p2(deg);
    p.create();
    cout<<"value for poly 2"<<endl;
    p2.create();
    p.display();
    p2.display();
    cout<<"result"<<endl;
    p.add(p2);
    // p.display();

}