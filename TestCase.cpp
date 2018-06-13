
#include "TestCase.hpp"

using namespace std;
#pragma once

void TestCase::print(){
	this->os << this->s << ": " << this->getFail() << " failed, " << this->getSucc() << " passed, " << this->getFail() + this->getSucc() << " total." << endl << "---" << endl;


}
