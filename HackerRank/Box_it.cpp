#include<bits/stdc++.h>

using namespace std;
class Box  {
    int l,b,h ;

    public:
        Box() {l=0; b=0; h=0;};
        Box(int t_l,int t_b ,int t_h) {l=t_l; b=t_b; h=t_h;};
        Box(const Box& B) {l=B.l; b=B.b; h=B.h;};

        int getLength() {return l;};// Return box's length
        int getBreadth () {return b;};// Return box's breadth
        int getHeight ()  {return h;};//Return box's height
        long long CalculateVolume() 
        {
            long long vol = l;
            vol*=b;
            vol*=h;
            return vol;
        };

        //Overload operator < as specified
        bool operator<( const Box& B) 
        {
            if (l < B.l) {return true;}
            if (b < B.b && l==B.l) {return true;}
            if (h < B.h && l==B.l && h==B.h) {return true;}
            return false;
        };
        
        //Overload operator << as specified
        friend std::ostream& operator<<(std::ostream& os, const Box& obj)
        {
            os << obj.l << " " << obj.b << " " << obj.h;
            return os;
        }
};

void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}