#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;
#pragma once

class TestCase{
	private:
		string s;
		ostream& os;
		int fail=0, success=0;
	public:
		TestCase(string s, ostream& os): os(cerr){this->s = s; this->os << "";}   // constructor
		template <typename T1, typename T2>
		TestCase& check_equal(T1 t1,T2 t2){ // check operator ==. 
			if(!(t1 == t2)){
				os << s <<" Failure in test  #1: "<< t1 << " should equal "<< t2<< "!"<< endl;
				fail++;
				return *this;
			} 
			success++;
			return *this;
		}        
		check_different(t t1,t t2);     // check operator !=. 
		ctemplate <typename F, typename T1, typename T2>
		 TestCase& check_function(F f, T1 t1,T2 t2){  // check a function int->int.
			auto t3=f(t1);
			if(t3==t2) {success++; return *this;}
			else {
				os << " Function should return "<< t2 << " but returned "<< t3<< "!"<< endl;
				fail++;
				return *this;
			}
		} 
		check_output(int, string);    // check output operator <<
		void print();                      // prints how many tests passed and faild
		string getString(){ return s;}
		ostream& getOs(){ return os;}
		int getFail(){ return fail;}
		int getSucc(){ return success;}

};
