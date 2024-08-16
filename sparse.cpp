
#include <iostream>
#define max 50
using namespace std;

class sparse 
    {
    int sp[max][3];
    int len = 0;
    public:
        sparse(int r , int c, int l)
            {
                sp[0][0] = r;
                sp[0][1] = c;
                sp[0][2] = l;
                len = 0;
            }

        void insert(int row , int col , int val);
        void display();
             
    };
    void sparse::insert(int row , int col , int val)
            {
                if(row >= sp[0][0] || col >= sp[0][1])
                    {
                        cout<<"invalid";
                    } 
                else
                    {
                        sp[len+1][0] = row;
                        sp[len+1][0] = col;
                        sp[len+1][0] = val;

                    }

            }
    void sparse::display()
        {   
            cout<<"row\tcolumn\tvalue"<<endl;
            for (int i = 0; i <= len; i++)
            {
                cout<<sp[ i][0]<<"\t"<<sp[i][1]<<"\t"<<sp[i][2]<<endl;
            }
            

        }
int main()
    {
        int r1 , c1 ,l1;
        int r , c ,v;
        cout<<"\n Enter the no of rows of sparks matrix";
        cin>>r1;
        cout<<"\n Enter the no of coloums of sparks matrix";
        cin>>c1;
        cout<<"\n Enter the no of non zero value of sparks matrix";
        cin>>l1;
        sparse sp(r1,c1,l1);
        for ( int i = 0; i < l1; i++)
        {
            cout<<"\n Enter the   rows  no";
            cin>>r;
            cout<<"\nEnter the   coloumn  no";
            cin>>c;
            cout<<"\n Enter the   value   ";
            cin>>v;

            sp.insert(r,c,v);

        }
        
        sp.display();


        return 0;
    }