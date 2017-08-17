#include <iostream>
using namespace std;
void hollowsquare(int rows){
	int cols=rows;
	for(int i=0;i<rows;++i){
		for(int j=0;j<cols;++j){
			if((i==0)||(i==(rows-1))){
				cout<<"* ";
			}
			else if((j==0)||(j==(cols-1))){
				cout<<"* ";
			}
			else{
				cout<<"  ";
			}


		}
cout<<endl;
	}

}
void hollowtriangle(int rows){
	int z=1;
	for (int i=0; i<rows; ++i)
	  {
	    for (int j=rows; j>i; --j)
	    {
	      cout<<" ";
	    }
	    cout<<"*";
	    if (i!=0 && i!=(rows-1))
	    {
	      for (int k=1; k<=z; k++)
	      {
	        cout<<" ";
	      }
	      cout<<"*";
	      z+=2;
	    }
	    if (i==(rows-1)){
	    	for (int l=0; l<(rows-1);++l){
	    		cout<<" *";
	    	}
	    }
	    cout<<endl;
	  }
}
void hollowdiamond(int rows){
	int z=1;

		for (int i=0; i<rows; ++i)
		  {
		    for (int j=rows; j>i; --j)
		    {
		      cout<<" ";
		    }
		    cout<<"*";
		    if (i>0)
		    {
		      for (int k=1; k<=z; k++)
		      {
		        cout<<" ";
		      }
		      cout<<"*";
		      z+=2;
		    }

		    cout<<endl;
		  }
		z-=4;
		for (int l=0;l<rows-1;++l)
		{
			for(int m=0;m<=l+1;++m)
			{
				cout<<" ";
			}
			cout<<"*";

				for(int n=1;n<=z;n++)
				{
					cout<<" ";
				}

				z-=2;
				if(l!=rows-2)
				{
				cout<<"*";
				}

		cout<<endl;

		}
}
void soliddiamond(int rows){
	int z=1;

		for (int i=0; i<rows; ++i)
		  {
		    for (int j=rows; j>i; --j)
		    {
		      cout<<" ";
		    }
		    cout<<"*";
		    if (i>0)
		    {
		      for (int k=1; k<=z; k++)
		      {
		        cout<<" *";
		      }

		      z+=1;
		    }

		    cout<<endl;
		  }
		z-=2;
		for (int l=0;l<rows-1;++l)
		{
			for(int m=0;m<=l+1;++m)
			{
				cout<<" ";
			}
			cout<<"*";
			if(l!=rows-2){
				for(int n=1;n<=z;n++)
				{
					cout<<" *";
				}
			z-=1;}

				//if(l!=rows-2)
				//{
				//cout<<"*";
				//}

		cout<<endl;

		}
}
int main(){
	int choice,sizesquare,sizetriangle,sizehollowdiamond,sizesoliddiamond;
	while(true){
		cout<<"Welcome to the Shape Printer!"<<endl;
		cout<<endl;
		cout<<"1: Hollow Square"<<endl;
		cout<<"2: Hollow Triangle"<<endl;
		cout<<"3: Hollow Diamond"<<endl;
		cout<<"4: Solid Diamond"<<endl;
		cout<<"0: Exit program"<<endl;
		cout<<"Input the type of shape you want to print, or exit program: ";
		cin>>choice;
			while ((choice>4)||(choice<0)){
				cout<<"INVALID CHOICE, PLEASE TRY AGAIN: ";
				cin>>choice;
				cout<<endl;
				}
		if(choice==1){
			cout<<"Please input the size of the square: ";
			cin>>sizesquare;
			cout<<endl;
			hollowsquare(sizesquare);
		}
		if(choice==2){
			cout<<"Please input the size of the triangle: ";
			cin>>sizetriangle;
			cout<<endl;
			hollowtriangle(sizetriangle);

		}
		if(choice==3){
			cout<<"Please input the size of the hollow diamond: ";
			cin>>sizehollowdiamond;
			cout<<endl;
			hollowdiamond(sizehollowdiamond);

		}
		if(choice==4){
			cout<<"Please input the size of the solid diamond: ";
			cin>>sizesoliddiamond;
			cout<<endl;
			soliddiamond(sizesoliddiamond);

		}
		if(choice==0){
			cout<<"BYE BYE";
			break;
		}
	}


}



