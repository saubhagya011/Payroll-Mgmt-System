#include<iostream>
#include<fstream>
using namespace std;
class payroll
{
	
	char name[20];
	float da, basic , hra ,pf;
	int tanure;
	int age;
	char sex;
	char status;
	char sub[20];
	public:
	void enter()
	{
		cout<<"\n Enter the details of the teacher who are working in school.";
		cout<<"\n Enter the serial number of teaher";
		cin>>sno;
		cout<<"\n Enter the name of the teacher.";
		cin>>name;
		cout<<"\n Enter the class which teacher teaches.";
		cin>>cls;
		cout<<"\n The salray paid to the teacher is.";
		cout<<pay;
		cout<<"\n Enter the  time period of working of a 			teacher in school.";
		cin>>tanure;
		cout<<"\n Enter the age of the teacher";
		cin>>age;
		cout<<"\n Enter the gender of teacher.";
		cin>>sex;
		cout<<"\n Enter the working status of the teacher 			i.e. working or resigned.";
		cin>>status;
		cout<<"\n Enter the subject which the  teacher 				teaches.";
		cin>>sub;
	 } 
	 void enter2()
	 {
	 	cout<<"\n Enter the details of teachers who have 			left the school.";
	 	cout<<"\n Enter the name of the teacher.";
	 	cin>>name;
	 	cout<<"\n ENter the tanure for which the teacher 			worked in the school.";
	 	cin>>tanure;
	 }
	 void display2()
	 {
	 	cout<<"\n The details of the teacher who have 				stopped working are.";
	 	cout<<"\n The name of the teacher.";
	 	cout<<name;
	 	cout<<"\n The salary paid to he teacher.";
	 	cout<<pay;
	 	cout<<"\n the tanure for which the teacher worked 			is.";
	 	cout<<tanure;
	 	cout<<"\n The working status of the teacher 				is="<<status;
	 }
	 void calculate()
	 {
	 	cout<<"\n Enter the payment details of the 					teacher.";
	 	cout<<"\n Enter the D.A of the teacher.";
	 	cin>>da;
	 	cout<<"\n Enter the basic of the  salary of 					teacher.";
	 	cin>>basic;
	 	cout<<"\n Enter H.R.A. of the salary of teacher.";
	 	cin>>hra;
	 	cout<<"\n Enter the provident fund details 0f 				teacher.";
	 	cin>>pf;
	 	pay=(basic + da + hra)-pf;
	 }
	 int cls;
	 int sno ;
	 float pay;
	 payroll()
	 {
	 	status='l';
	 }
	 char subject()
	 {
	 	return sub[0];
	 }
	 float provident()
	 {
	 	return pf; 
	 }
	 char gender()
	 {
	 	return sex;
	 }
	 int ag()
	 {
	 	return age;
	 }
	 char nam()
	 {
	 	return name[0];
	 }
	 int t()
	 {
	 	return tanure;
	}
	char stat()
	{
		return status;
	}
	 void display()
	 {
	 	cout<<"\n The detail of teacher are.";
	 	cout<<"\n The serial number of teacher.";
	 	cout<<"="<<sno;
		cout<<"\n Name of teacher.";
	 	cout<<"="<<name;
	 	cout<<"\n Salary of teacher.";
	 	cout<<"="<<pay;
	 	cout<<"\n The class teacher teaches.";
	 	cout<<"="<<cls;
	 	cout<<"\n The working time period of techer is.";
	 	cout<<tanure;
	 	cout<<"\n The age of the teacher is.";
	 	cout<<age;
	 	cout<<"\n The working status of theteacher is.";
	 	cout<<status;
	 	cout<<"\n The subject which the teacher teaches 			is.";
	 	cout<<sub;
	 }
};
void make()
{
	payroll p;
	int m;
	cout<<"\n It is the function to enter the record of 			teacher present in school.";
	cout<<"\n \n Enter the  number of teachers in school.";
	cin>>m;
	ofstream A("Teacher.dat",ios::binary);
	for(int i=0; i<m; i++)
	{
		p.calculate();
		p.enter();
		A.write((char*)&p , sizeof(p));
	}
	A.close();
}
void salary()
{
	payroll P;
	cout<<"\n \n It is the function to display the records of 		teacher who earn more the 20000.";
	ifstream A("Teacher.dat" , ios::binary);
	while(!A.eof())
	{
		A.read((char*)&P, sizeof(P));
		if(P.pay>20000)
		P.display();
	}
	A.close();
}
void newrec()
{
	payroll N;
	int i ,n;
	cout<<"\n \n It is the function to enter the record of a 		newly appointed teeacher.";
	cout<<"\n Enter the number of new teachers whose 			records are to be entered.";
	cin>>n;
	ofstream A("Teacher.dat" ,ios::binary | ios::app);
		for(i=0 ; i<n ; i++)
		{		
	    	N.calculate();
			N.enter();
			A.write((char*)&N, sizeof(N));
		}
	A.close();
}
void promote()
{
	payroll M;
	cout<<"\n \n It is the function to display the records of 		teachers teaching the board classes.";
	ifstream A("Teacher.dat",ios::binary);
	while(!A.eof())
	{
		A.read((char*)&M , sizeof(M));
		if(M.cls==10 || M.cls==12)
		M.display();
		else 
		cout<<"\n No records present.";
	}
	A.close();
}
void dis()
{
	payroll Q;
	cout<<"\n \n It is the function to promote the teachers 		teaching class 2 to class 4.";
	ifstream A("Teacher.dat" , ios::binary);
	ofstream B("Temp.dat" , ios::binary);
	while(!A.eof())
	{
		A.read((char*)&Q ,sizeof(Q));
		if(Q.cls==2)
		{
			Q.cls=4;
			B.write((char*)&Q , sizeof(Q));
		}
		else
		B.write((char*)&Q , sizeof(Q));
		Q.display();
	} 
	A.close();
	B.close();
}
void work()
{
	payroll W;
	int w=0;
	cout<<"\n \n It is the function to count the total 			number of teachers teaching in school.";
	ifstream A("Teacher.dat" , ios::binary);
	while(!A.eof())
	{
		A.read((char*)&W , sizeof(W));
		if(W.stat()=='w')
		w++;
	}
	cout<<"\n The number of teachers teaching in school 			are."<<w;
	A.close();
}
void names()
{
	payroll K;
	cout<<"\n \n It is the function to display the records of 		teachers who have thein nume starting with k or 		g.";
	ifstream A("Teacher.dat", ios::binary);
	while(!A.eof())
	{
		A.read((char*)&K , sizeof(K));
		if(K.nam()=='k' || K.nam()=='g')
		K.display(); 
		else
		cout<<"\n No records are present.";
	}
	A.close();
}
void retirement()
{
	payroll E;
	cout<<"\n It is the function to display the list of those 		tecahers who are going to be retired.";
	cout<<"\n The list of retired teachers going to be retired 		is.";
	ifstream A("Teacher.dat" , ios::binary);
	while(!A.eof())
	{
		A.read((char*)&E , sizeof(E));
		if(E.ag()>=40)
		E.display();
		else
		cout<<"\n No records present.";
	}
	A.close();
}
void count()
{
	payroll R;
	int c=0;
	cout<<"\n \n It is the function to count the number of 		female teachers in school.";
	ifstream A("Teacher.dat" , ios::binary);
	while(!A.eof())
	{
		A.read((char*)&R , sizeof(R));
		if(R.gender()=='F')
		c++;
	}
	cout<<"\n The number of Female teachers in school 			are="<<c;
	A.close();
}
void count1()
{
	payroll T;
	int t=0;
	cout<<"\n It is the functionto display the number of 			teachers who are going to be retired.";
	ifstream A("Teacher.dat" , ios::binary);
	while(!A.eof())
	{
		A.read((char*)&T , sizeof(T));
		if(T.ag()>=40)
		t++;
	 } 
	 cout<<"\n The number of teachers going to be retired 		are="<<t;
	 A.close();
}
void count2()
{
	payroll Y;
	int y;
	cout<<"\n \n It is the function to count the number of 		teachers who earn more then 30000"; 
	ifstream A("Teacher.dat" , ios::binary);
	while(!A.eof())
	{
		A.read((char*)&Y , sizeof(y));
		if(Y.pay>=30000)
		y++;
	}
	cout<<"\n The number of teachers earning more than 		30000 are="<<y;
	A.close();
}
void youngsters()
{
	payroll O;	
	cout<<"\n It is the function to increase the pay for all 		the teachers who have worked for the school for 		more than 5 years.";
	ifstream A("Teacher.dat" , ios::binary);
	ofstream C("Temp2.dat" , ios::binary);
	while(!A.eof())
	{
		A.read((char*)&O ,sizeof(O));
		if(O.t()>=5)
		{
			O.pay+=5000;
			C.write((char*)&O , sizeof(O));
		}
		else
		C.write((char*)&O , sizeof(O));
		O.display();
	} 
	A.close();
	C.close();
}
void make2()
{
	payroll I;
	int i;
	cout<<"\n This function lets us make the list of the 			teachers who have left the school and stopped 			working.";
	cout<<"\n \n Enter the number of teachers which have 		left the school.";
	cin>>i;
	ofstream A("Teacher.dat" , ios::binary | ios::app);
	for(int j =0 ;j<i ; j++)
	{
		I.calculate();
		I.enter2();
		A.write((char*)&I , sizeof(I));
		I.display2();
	}
	A.close();
}
void p_f()
{
	payroll K;
	float amount;
	cout<<"\n It is the function to calculate the provident 		fund which the teacher will be getting as they 			have left the school.";
	ifstream A("Teacher.dat" , ios::binary);
	while(!A.eof())
	{
		A.read((char*)&K , sizeof(K));
		if(K.stat()=='l')
		amount=((K.t()*K.provident())-0.05*K.provident());
	}
	cout<<"\n The amount which te teacher will get 				is"<<amount;
	A.close();
}
void show()
{
	payroll L;
	cout<<"\n It is the function to display the details of all 		teachers.";
	ifstream A("Teacher.dat",ios::binary);
	while(!A.eof())
	{
		A.read((char*)&L , sizeof(L));
		L.display();
	}
	A.close();
}
int main()
{
	int ch;
	char wish;
	do
	{
		cout<<"\n Enter \n 1. for making the binary file.";
		cout<<"\n 2. for displaying the records of teacher 			who earn more then 20000.";
		cout<<"\n 3. for entering the record of the newly 			appointed teacher.";
		cout<<"\n 4. for showing the details of teacher 				teaching board classes.";
		cout<<"\n 5. for updating the class or to make 				promotion of the teacher.";
		cout<<"\n 6. for counting the total numbber of 				teachers teaching in the school..";
		cout<<"\n 7. for showing the records of teachers 				whose name start with some specific 					alphabet. ";
		cout<<"\n 8. for showing the details of the teachers 			going to be retired.";
		cout<<"\n 9. for counting the number of female 				teachers.";
		cout<<"\n 10. for counting number of teachers 				going to be retired.";
		cout<<"\n 11. for counting number of tecahers 				earning more than 30000. ";
		cout<<"\n 12. for increasing the pay of the teachers 			who have worked for more than 5 years.";
		cout<<"\n 13. show details of teachers left 					working.";
		cout<<"\n 14. for calculating the pf.";
		cout<<"\n 15. for showing te complete file.";
		cin>>ch;
		switch(ch)
		{
			case 1 :make();
			break;
			case 2 :salary();
			break;
			case 3 :newrec();
			break;
			case 4 :promote();
			break;
			case 5 :dis();
			break;
			case 6 :work();
			break;
			case 7 :names();
			break;
			case 8 :retirement();
			break;
			case 9 :count();
			break;
			case 10 :count1();
			break;
			case 11 :count2();
			break;
			case 12 :youngsters();
			break;
			case 13 :make2();
			break;
			case 14 :p_f();
			break;
			case 15 :show();
			break;
			defaut : cout<<"\n Invalid choice";
		}
		cout<<"\n press y if you want to continue.";
		cin>>wish;
	}
	while(wish=='y');
	return 0;
}



