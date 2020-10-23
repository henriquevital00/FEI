
class AbstractOrderedList
{
    public:
        ListaEstaticaSequencial(){

        };
        virtual ~AbstractOrderedList(){

        };

        virtual bool insert (int value) = 0;
        virtual bool remove (int value) = 0;
        virtual bool search (int value) = 0;
        
};

#define MAX 11

class LES : public AbstractOrderedList
{
    private:
        int n;
        int v[MAX];

    public:
        LES(){
            n=0;
        };
        bool insert (int value){
            if (n == MAX)
                return false;

            int i;
            for (i = 0; i < n &&  v[i] <= value; ++i);

            for (int j = n; j >= i; j--) {
                v[j] = v[j-1];
                n++;
            }
            return true;
        }
        virtual bool remove (int value) = 0;
        virtual bool search (int value) = 0;
        
        virtual ~LES(){

        };
};



int main(int argc, char *argv[])
{
    
    return 0;
}
