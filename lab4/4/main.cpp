#include <iostream>
#include <math.h>
#include <cstdlib>

using namespace std;

class Prostopadloscian{
	private:
		int a;
		int b;
		int H;
	
	public:
		int pole() {
			return a*b*H;
		}

		int getA(){
			return a;
		}

		int getB(){
			return b;
		}

		int getH(){
			return H;
		}
		
		void setA(int b){
			this->b=b;
		}
		void setB(int b){
			this->b=b;
		}
		void setH(int H){
			this->H=H;
		}
};

class Kula{
	private:
		int R;

	public:
		double objetosc(){
			return (4.0/3) * R * R * R * M_PI;
		}

		int getR(){
			return R;
		}

		void setR(int R){
			this->R=R;
		}
};

class FunkcjaKwadratowa{
	private:
		int a;
		int b;
		int c;

	public:
		void wyswietl() {
			printf("%dx^2 + %dx + %d\n",a,b,c);
		}

		int getA(){
			return a;
		}

		int getB(){
			return b;
		}

		int getC(){
			return c;
		}

		void setA(int a){
			this->a=a;
		}
		void setB(int b){
			this->b=b;
		}
		void setC(int c){
			this->c=c;
		}
};

class Student{
	private:
		string name;
		string lastName;
		int nr_al;
		int l_pyt;
		int pop_odp;

	public:
		double ile_proc(){
			return 100*pop_odp/(double)l_pyt;
		}

		string getName(){
			return name;
		}

		string getLastName(){
			return lastName;
		}

		int getNrAlbumu()
		{
			return nr_al;
		}

		int getLiczbaPytan()
		{
			return l_pyt;
		}

		int getPopOdp()
		{
			return pop_odp;
		}
		
		void setName(string name){
			this->name=name;
		}

		void setLastName(string lastName){
			this->lastName=lastName;
		}
		
		void setNrAlbumu(int nr_al){
			this->nr_al=nr_al;
		}
		
		void setLiczbaPytan(int l_pyt){
			this->l_pyt=l_pyt;
		}
		
		void setPopOdp(int pop_odp){
			this->pop_odp=pop_odp;
		}

};

int main()
{
	/* Prostopadloscian a; */
	/* a.a=1; */
	/* a.b=2; */
	/* a.H=4; */
	/* cout << a.pole() << endl; */

	/* Kula b; */
	/* b.R=2; */
	/* cout << b.objetosc() << endl; */

	/* FunkcjaKwadratowa c; */
	/* c.a=3; */
	/* c.b=4; */
	/* c.c=5; */
	/* c.wyswietl(); */

	/* Student d; */
	/* d.l_pyt= 20; */
	/* d.pop_odp= 5; */
	/* cout << d.ile_proc() << endl; */

	return 0;
}