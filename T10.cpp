#include<iostream>
#include<string>
#include<iomanip>
#include <limits>
using namespace std;
struct information
{
string name;//اسم
string family;//فامیل
string field;//رشته
long long int ID;//شماره دانشجویی
string lesson[10];//نام درس
int vahed[10];//تعداد واحد
float score[10];
float avrrag;
int n;
};
void bubblesort(information k[],int num);
void delet(information[],int & num,int i);
information read();
void write1(information k);//A
void write2(information k);//B
void write3(information k);//3
int main(){
int num=0,n=0;    
cout<<"Enter the number of students:  ";
while (!(cin >> num)) {
cout << "Error!"<< endl;
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
cout << "Enter the number of students:  ";
    }
information k[num];
for (int i=0;i<num;i++)
{
cout<<"student number"<<i+1<<endl;
 k[i]=read();
}

bubblesort(k,num);
int ch1;  
int ch2; 
lbl_for:
cout<<"please select one option !"<<endl;
cout<<"1:List of student "<<endl;
cout<<"2:search by Name"<<endl;
cout<<"3:search by ID"<<endl;
cout<<"4:delete the students"<<endl;
cout<<"5:Exit"<<endl;
cout<<"Enter:";
while(!(cin>>ch1)){
cout << "Error! "<< endl;
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
cout << "Enter:";
}
if(ch1==1){
cout<<"please selsect one option!"<<endl;
cout<<"1:sorting by grade."<<endl;
cout<<"2:sorting by Major."<<endl;

while(!(cin>>ch2)){
cout << "Error! "<< endl;
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
cout << "please selsect one option: "<<endl;
}




if(ch2==1){
for(int h=0;h<num;++h)
write1(k[h]);
goto lbl_for;
}
else if(ch2==2){
string f;
int x1=0;
label_A1:
cout<<"Enter Magor :";
cin>>f;
for(int y=0;num>y;++y){  
if (f==k[y].field){
++x1;
write2(k[y]);}
                       }
if(x1==0){
cout<<"not found!"<<endl;
goto label_A1;}
else
goto lbl_for;
}
}

else if (ch1==2){
string g;
int x2=0;
label_A2:
cout<<"Enter Name :";
cin>>g;
for(int y=0;num>y;++y){  
if (g==k[y].name){
++x2;
write3(k[y]);  
for(int g=0;k->n>g   ;++g){
cout<<"lesson: "<<k[y].lesson[g]<<"   vahed: "<<k[y].vahed[g]<<"   Score: "<<k[y].score[g]<<endl;
cout<<"**********************************************"<<endl;
 }}
                       }
if(x2==0){
cout<<"not found!"<<endl;
goto label_A2;}
else
goto lbl_for;
}

else if (ch1==3){
int p;
int x3=0;
label_A3:
cout<<"Enter ID :";
while(!(cin>>p)){
cout << "Error! "<< endl;
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
cout << "Enter ID:  ";
}

for(int y=0;num>y;++y){  
if (p==k[y].ID){
++x3;
write3(k[y]);  
for(int g=0;k->n>g   ;++g){
cout<<"lesson: "<<k[y].lesson[g]<<"   vahed: "<<k[y].vahed[g]<<"   Score: "<<k[y].score[g]<<endl;
cout<<"**********************************************"<<endl;
 }}
                       }
if(x3==0){
cout<<"not found!"<<endl;
goto label_A3;
}
else
goto lbl_for;
}

else if(ch1==4){
long long int a;
int m=0;
agn:
cout << "Enter ID: ";
while(!(cin >> a)){
cout << "Error! "<< endl;
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
cout << "Enter ID: ";
}
for (int i = 0; i < num; ++i) {
if (a == k[i].ID){
++m;
delet(k,num,i);
goto lbl_for;
}
}
if(m==0){
cout<<"not found!"<<endl;
goto agn;
}

}

else if (ch1==5){
cout<<"bye";  }  

else{

cout<<"error"<<endl;
goto lbl_for;

};
}

information read( ){
information k;
int n;
float s=0,m=0;
float Avrage=0;
cout<<"Enter name:  ";
cin>>k.name;
cout<<"Enter family:  ";
cin>>k.family;
cout<<"Enter field:  ";
cin>>k.field;
cout<<"Enter ID:   ";
while(!(cin>>k.ID)){
cout << "Error! "<< endl;
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
cout << "Enter ID:  ";
}
cout<<"Enter number of lessons: ";
while(!(cin>>k.n)){
cout << "Error! "<< endl;
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
cout << "Enter number of lessons:";
}

for(int j=0;k.n>j;++j){
cout<<"Enter the name of the lesson: ";
cin>>k.lesson[j];

cout<<"Enter vahed: ";
while(!(cin>>k.vahed[j])){
cout << "Error! "<< endl;
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
cout << "Enter vahed:  ";
}
cout<<"Enter score: ";
while(!(cin>>k.score[j])){
cout << "Error! "<< endl;
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
cout << "Enter the scores of student:  ";
}
s=s+(k.score[j])*(k.vahed[j]);
m=m+k.vahed[j];
}
Avrage=s/m;
k.avrrag=Avrage;
return k;
}

void  bubblesort (information k[],int num)
{    
int i, j;
for(i = 0; i < num; i++)
{
for(j = 0; j < num-i-1; j++)
{
if( k[j].avrrag < k[j+1].avrrag)
{information temp;
temp = k[j];
k[j] = k[j+1];
k[j+1] = temp;
} 
}
}

}

void write1(information k)//خروجیA1
{
cout<<"name: "<<k.name<<"  family: "<<k.family<<"  ID: "<<k.ID<<"  moadel: "<<fixed<<setprecision(4)<<k.avrrag<<endl;
cout<<"************************************************"<<endl;
}
void write2(information k)//خروجی1B
{
cout<<k.field<<endl;
cout<<"name: "<<k.name<<"  family: "<<k.family<<"  ID: "<<k.ID<<"  moadel: "<<fixed<<setprecision(4)<<k.avrrag<<endl;
cout<<"************************************************"<<endl;
}
void write3(information k)//خروجی2
{
cout<<"name: "<<k.name<<"  family: "<<k.family<<"  ID: "<<k.ID<<"  moadel: "<<fixed<<setprecision(4)<<k.avrrag<<endl;
cout<<"************************************************"<<endl;
}

void delet(information k[],int & num,int i) {       
for (int j = i; j < num - 1; ++j) {
k[j] = k[j + 1];
}
cout<<"student with ID:  "<<k->ID<<"  has been deleted"<<endl;
num--; 

}




