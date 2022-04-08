# Citirea din fisier folosind supraincarcarea opratorului >>

```C++
class A{
    int x;
public:
    A(){}

    int getX() const {
        return x;
    }

    friend istream& operator >> (istream& is, A& ob) 
    {
       is>>ob.x;
       return is;
    }
};
int main(){
    A a;
    ifstream myFile;
    myFile.open("input.txt");

    myFile >> a;
    cout<<a.getX();
    
}
```