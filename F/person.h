using namespace std;

class Person{
    public:
        char LastName[16];    char FirstName[16];
        char Address[16];     char City[16];
        char State[3];        char ZipCode[10];
        Person();
        static int InitBuffer(DelimFieldBuffer &);
        int Unpack(IOBuffer &);
        int Pack(IOBuffer &) const;
        void Clear();
        void Print(ostream &, char *label=0);
};

