#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>

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
				os << s <<": Failure in test #"<<  (success+fail+1) << ": "<< t1 << " should equal "<< t2<< "!"<< endl;
				fail++;
				return *this;
			} 
			success++;
			return *this;
		}        
		template <typename T, typename F>
        TestCase& check_different(T t, F f) {   //check if different !=
		if(t != f){
			success++;
        }
		else {os << s<< ": Failure in test #"<<  (success+fail+1) << ": "<< t << " should differ than " << f << "!"<<endl;
		fail++;
		}
		return (*this);
	}
		
		
		
		template <typename F, typename T1, typename T2>
		 TestCase& check_function(F f, T1 t1,T2 t2){  // check a function int->int.
			auto t3=f(t1);
			if(t3==t2) {success++; return *this;}
			else {
				os << s << ": Failure in test #"<<  (success+fail+1) <<": Function should return "<< t2 << " but returned "<< t3<< "!"<< endl;
				fail++;
				return *this;
			}
		} 
		
		
		template <typename T>
	 TestCase& check_output(T t1, string s1) {  //check output<<
		ostringstream string;
        string << t1;
        if (string.str().compare(s1) == 0){
            success++;
        }
		else {os << s<< ": Failure in test #"<<  (success+fail+1) << ": string value should be "<<s1 << " but is " << string.str() << "!"<<endl;
		fail++;
		}
		return (*this);
	}
	
	
		void print();                      // prints how many tests passed and faild
		string getString(){ return s;}
		ostream& getOs(){ return os;}
		int getFail(){ return fail;}
		int getSucc(){ return success;}

};

