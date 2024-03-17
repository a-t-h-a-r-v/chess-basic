#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class chess_basic_position{
	private:
		int i;
		int j;
	public:
		chess_basic_position(int i,int j){
			this->i=i-1;
			this->j=j-1;
		}

		chess_basic_position(int p){
			i=p/8;
			j=p%8;
		}

		chess_basic_position(const char str[2]){
			if(strlen(str) < 2){
				throw std::invalid_argument("Arguments should be of type <a-h><1-8>");
			}

			if((int)str[0]<97 || (int)str[0]>104 ){
				throw std::invalid_argument("1st value can be from one of these(a,b,c,d,e,f,g,h)");
			}

			if((int)str[1]<49 || (int)str[1]>56 ){
				throw std::invalid_argument("2nd value can be between 1 and 8");
			}

			i=((int)str[0]-97)%8;
			j=((int)str[1]-49)%8;
		}

		void seti(char i){
			if((int)i<97 || (int)i>104 ){
				throw std::invalid_argument("Value can be from one of these(a,b,c,d,e,f,g,h)");
			}
			this->i=((int)i-97)%26;
		}

		void seti(int i){
			if(i<1 || i>8){
				throw  std::invalid_argument("Value can be between 1 and 8");
			}
			this->i = i;
		}

		void setj(int j){
			if(j<1 || j>8){
				throw  std::invalid_argument("Value can be between 1 and 8");
			}
			this->j = j;
		}

		int geti(){
			return i;
		}

		int getj(){
			return j;
		}

		string getPosition(){
			return string(1,static_cast<char>(97+i))+to_string(j+1);
		}

		~chess_basic_position(){}
};
int main(){
	chess_basic_position obj(1,3);
	chess_basic_position obj1("e4");
	cout<<"i : "<<obj.geti()<<"j : "<<obj.getj()<<endl;
	cout<<"Position : "<<obj.getPosition()<<endl;
}
