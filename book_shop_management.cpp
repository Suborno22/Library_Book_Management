#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class book
{
    private:
       char *author,*title,*publisher;
       float *price;
       int *stock;

    public:
       book(){
        author = new char[50];
        title = new char[50];
        publisher = new char[50];
        price = new float;
        stock = new int;
       };

    void givedata();
	void updatedata();
	void showdata();
	int search(char[],char[]);
	void buybook();

};

void book::givedata(){
    cin.ignore();
    cout<<"Enter the title of the book: "; cin.getline(title,50);
    cout<<"Enter the author of the book: "; cin.getline(author,50);
    cout<<"Enter the publisher of the book: "; cin.getline(publisher,50);
    cout<<"Enter price: "; cin>>*price;
    cout<<"Enter stock: "; cin>>*stock;
};


void book::updatedata(){
    cout<<"Enter the title of the book: "; cin.getline(title,50);
    cout<<"Enter the author of the book: "; cin.getline(author,50);
    cout<<"Enter the publisher of the book: "; cin.getline(publisher,50);
    cout<<"Enter price: "; cin>>*price;
    cout<<"Enter stock: "; cin>>*stock;
};

void book :: showdata(){
    cout<<"\nAuthor Name: "<<author;
	cout<<"\nTitle Name: "<<title;
	cout<<"\nPublisher Name: "<<publisher;
	cout<<"\nPrice: "<<*price;
	cout<<"\nStock Position: "<<*stock;
}

int book::search(char tbuy[20],char abuy[20] )	{
	if(strcmp(tbuy,title)==0 && strcmp(abuy,author)==0)
		return 1;
	else return 0;

}
void book::buybook(){
    int count;
    cout<<"\nEnter number of books to buy: "; cin>>count;
    if(count=*stock){
        *stock = *stock - count;
        cout<<"\nAmount of items brought: "<<(*price)*count;
        cout<<"\nDone";
    }
    else{
        cout<<"\nError!";
    }

};

int main(){
    book *b[50];
	int i=0,t;
	int choice;
	char tbuy[20],abuy[20];

    while(1){
            cout<<"\n\n\t\tMENU"
            <<"\n 1. Entry of new book."
            <<"\n 2. Find book."
            <<"\n 3. Update book."
            <<"\n 4. Buy book."
            <<"\n 5. Exit."
            <<"\nEnter the choice(Number only, type alphabet if you want an infinite loop): ";
            cin>>choice;
            switch(choice){
            case(1):b[i] = new book;
                    b[i] ->givedata();
                    i++;
                    break;
            case(2):cin.ignore();
                    cout<<"\nEnter title of the book: ";cin.getline(tbuy,20);
                    cout<<"\nEnter the author's name: ";cin.getline(abuy,20);
                    for(t=0;t<i;t++){
                        if(b[t]->search(tbuy,abuy)){
                            cout<<"\nBook found";
                            b[t]->showdata();
                            break;
                        }
                    }
                    if(t==i){
                        cout<<"Not in stock";
                        break;
                    }
            case(3):cin.ignore();
                    cout<<"\nEnter title of the book: ";cin.getline(tbuy,20);
                    cout<<"\nEnter the author's name: ";cin.getline(abuy,20);
                    for(t=0;t<i;t++){
                        if(b[t]->search(tbuy,abuy)){
                            cout<<"\nBook found";
                            b[t]->updatedata();
                            break;
                        }
                    }
                    if(t==i){
                        cout<<"Not in stock";
                        break;
                    }
            case(4):cin.ignore();
                    cout<<"\nEnter title of the book: ";cin.getline(tbuy,20);
                    cout<<"\nEnter the author's name: ";cin.getline(abuy,20);
                    for(t=0;t<i;t++){
                        if(b[t]->search(tbuy,abuy)){
                            cout<<"\nBook found";
                            b[t]->buybook();
                            break;
                        }
                    }
                    if(t==i){
                        cout<<"Not in stock";
                        break;
                    }
            case(5):exit(0);
            default: cout<<"Go home and learn english first.";
        }
    }
}
