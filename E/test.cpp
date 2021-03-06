#include<fstream>
#include<cstring>
#include"lentext.cpp"
#include"fixtext.cpp"
#include"deltext.cpp"
#include"person.cpp"
using namespace std;

void testDelText(){
    int result;
    Person p;
    strcpy(p.LastName, "taware");
    strcpy(p.FirstName, "abhijit");
    strcpy(p.Address, "dange");
    strcpy(p.City, "pune");
    strcpy(p.State, "ma");
    strcpy(p.ZipCode, "33");
    p.Print(cout);

    DelimTextBuffer Buff(6);
    p.Pack(Buff);
    Buff.Print(cout);
    ofstream TestOut("deltext.dat", ios::out|ios::binary);
    Buff.Write(TestOut);
    TestOut.close();
   
    Person q; 
    ifstream TestIn("deltext.dat", ios::in|ios::binary);
    DelimTextBuffer InBuff(6);
    InBuff.Clear();
    InBuff.Read(TestIn);
    InBuff.Print(cout);
    q.Unpack(InBuff);
    q.Print(cout);
}

void testFixText(){
    int result;
    Person p;
    FixedTextBuffer Buff(6);
    Person::InitBuffer(Buff);
    strcpy(p.LastName, "taware");
    strcpy(p.FirstName, "abhijit");
    strcpy(p.Address, "dange");
    strcpy(p.City, "pune");
    strcpy(p.State, "ma");
    strcpy(p.ZipCode, "33");
    p.Print(cout);
    p.Pack(Buff);
    Buff.Print(cout);

    ofstream TestOut("fixtext.dat", ios::out|ios::binary);
    Buff.Write(TestOut);
    TestOut.close();
   
    Person q; 
    ifstream TestIn("fixtext.dat", ios::in|ios::binary);
    FixedTextBuffer InBuff(6);
    InBuff.Clear();
    Person::InitBuffer(InBuff);
    InBuff.Read(TestIn);
    InBuff.Print(cout);
    q.Unpack(InBuff);
    q.Print(cout);
}

void testLenText(){
    Person p;
    LengthTextBuffer Buff;
    Buff.Init(100);
    strcpy(p.LastName, "taware");
    strcpy(p.FirstName, "abhijit");
    strcpy(p.Address, "dange");
    strcpy(p.City, "pune");
    strcpy(p.State, "ma");
    strcpy(p.ZipCode, "33");
    p.Print(cout);
    Buff.Print(cout);
    cout << "pack person "<< p.Pack(Buff)<<endl;
    Buff.Print(cout);

    ofstream TestOut("lentext.dat", ios::out|ios::binary);
    Buff.Write(TestOut);
    Buff.Write(TestOut);
    strcpy(p.FirstName, "anaya");
    p.Print(cout);
    p.Pack(Buff);
    Buff.Print(cout);
    Buff.Write(TestOut);
    TestOut.close();

    Person p2;
    ifstream TestIn("lentext.dat", ios::in|ios::binary);
    cout << "read " << Buff.Read(TestIn) << endl;
    cout << "unpack " << p2.Unpack(Buff) << endl;
    p2.Print(cout);
}

int main(){
    testDelText();
    //testLenText();
    //testFixText();
    return 0;
}

