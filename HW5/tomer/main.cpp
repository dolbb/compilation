#include <iostream>
#include "registers.hpp"
#include <sstream>

using namespace std;

//bool test_separate_regs() {
//    Registers& r1 = Registers::instance();
//    string t0 = r1.getTempReg();
//    string s0 = r1.getSavedReg();
//    string t1 = r1.getTempReg();
//    string s1 = r1.getSavedReg();
//    cout << "t0: " << t0 <<endl;
//    cout << "t1: " << t1 <<endl;
//    cout << "s0: " << s0 <<endl;
//    cout << "s1: " << s1 <<endl;
//    cout << "-------------------------------" << endl;
//    Registers& r = Registers::instance();
//    for (std::map<string,bool>::iterator it=r1.saved_regs.begin(); it!=r1.saved_regs.end(); ++it){
//        cout << it->first << " " << it->second << endl;
//    }
//    for (std::map<string,bool>::iterator it=r1.temp_regs.begin(); it!=r1.temp_regs.end(); ++it){
//        cout << it->first << " " << it->second << endl;
//    }
//    for (std::map<string,bool>::iterator it=r1.saved_regs.begin(); it!=r1.saved_regs.end(); ++it){
//        if (r1.saved_regs[it->first] != r.saved_regs[it->first]) {
//            cout << "ERROR" << endl;
//        }
//    }
//    for (std::map<string,bool>::iterator it=r1.temp_regs.begin(); it!=r1.temp_regs.end(); ++it){
//        if (r1.temp_regs[it->first] != r.temp_regs[it->first]) {
//            cout << "ERROR" << endl;
//        }
//    }
//    r.releaseTempReg(t0);
//    r.releaseSavedReg(s0);
//    cout << "-------------------------------" << endl;
//    for (std::map<string,bool>::iterator it=r.saved_regs.begin(); it!=r.saved_regs.end(); ++it){
//        cout << it->first << " " << it->second << endl;
//    }
//    for (std::map<string,bool>::iterator it=r.temp_regs.begin(); it!=r.temp_regs.end(); ++it){
//        cout << it->first << " " << it->second << endl;
//    }
//    for (std::map<string,bool>::iterator it=r1.saved_regs.begin(); it!=r1.saved_regs.end(); ++it){
//        if (r1.saved_regs[it->first] != r.saved_regs[it->first]) {
//            cout << "ERROR" << endl;
//        }
//    }
//    for (std::map<string,bool>::iterator it=r1.temp_regs.begin(); it!=r1.temp_regs.end(); ++it){
//        if (r1.temp_regs[it->first] != r.temp_regs[it->first]) {
//            cout << "ERROR" << endl;
//        }
//    }
//    cout << "-------------------------------" << endl;
//    t0 = r.getTempReg();
//    s0 = r.getSavedReg();
//    cout << "t0: " << t0 <<endl;
//    cout << "t1: " << t1 <<endl;
//    cout << "s0: " << s0 <<endl;
//    cout << "s1: " << s1 <<endl;
//    r.releaseTempReg(t0);
//    r.releaseSavedReg(s0);
//    r.releaseTempReg(t1);
//    r.releaseSavedReg(s1);
//    cout << "-------------------------------" << endl;
//    for (std::map<string,bool>::iterator it=r.saved_regs.begin(); it!=r.saved_regs.end(); ++it){
//        cout << it->first << " " << it->second << endl;
//    }
//    for (std::map<string,bool>::iterator it=r.temp_regs.begin(); it!=r.temp_regs.end(); ++it){
//        cout << it->first << " " << it->second << endl;
//    }
//    for (std::map<string,bool>::iterator it=r1.saved_regs.begin(); it!=r1.saved_regs.end(); ++it){
//        if (r1.saved_regs[it->first] != r.saved_regs[it->first]) {
//            cout << "ERROR" << endl;
//        }
//    }
//    for (std::map<string,bool>::iterator it=r1.temp_regs.begin(); it!=r1.temp_regs.end(); ++it){
//        if (r1.temp_regs[it->first] != r.temp_regs[it->first]) {
//            cout << "ERROR" << endl;
//        }
//    }
//    return true;
//}

bool test_regs() {
    Registers& r1 = Registers::instance();
    cout << "-------------------------------" << endl;
    string t0 = r1.getReg();
    string t1 = r1.getReg();
    string t2 = r1.getReg();
    string t3 = r1.getReg();
    string t4 = r1.getReg();
    string t5 = r1.getReg();
    string t6 = r1.getReg();
    string t7 = r1.getReg();
    string t8 = r1.getReg();
    string t9 = r1.getReg();
    string s0 = r1.getReg();
    string s1 = r1.getReg();
    cout << "t0: " << t0 <<endl;
    cout << "t1: " << t1 <<endl;
    cout << "s0: " << s0 <<endl;
    cout << "t9: " << t9 <<endl;
    cout << "-------------------------------" << endl;
    Registers& r = Registers::instance();
//    for (std::map<string,bool>::iterator it=r1.saved_regs.begin(); it!=r1.saved_regs.end(); ++it){
//        cout << it->first << " " << it->second << endl;
//    }
//    for (std::map<string,bool>::iterator it=r1.temp_regs.begin(); it!=r1.temp_regs.end(); ++it){
//        cout << it->first << " " << it->second << endl;
//    }
//    for (std::map<string,bool>::iterator it=r1.saved_regs.begin(); it!=r1.saved_regs.end(); ++it){
//        if (r1.saved_regs[it->first] != r.saved_regs[it->first]) {
//            cout << "ERROR" << endl;
//        }
//    }
//    for (std::map<string,bool>::iterator it=r1.temp_regs.begin(); it!=r1.temp_regs.end(); ++it){
//        if (r1.temp_regs[it->first] != r.temp_regs[it->first]) {
//            cout << "ERROR" << endl;
//        }
//    }
    r.releaseReg(t0);
    r.releaseReg(s0);
    cout << "-------------------------------" << endl;
//    for (std::map<string,bool>::iterator it=r1.saved_regs.begin(); it!=r1.saved_regs.end(); ++it){
//        cout << it->first << " " << it->second << endl;
//    }
//    for (std::map<string,bool>::iterator it=r.temp_regs.begin(); it!=r.temp_regs.end(); ++it){
//        cout << it->first << " " << it->second << endl;
//    }
//    for (std::map<string,bool>::iterator it=r1.saved_regs.begin(); it!=r1.saved_regs.end(); ++it){
//        if (r1.saved_regs[it->first] != r.saved_regs[it->first]) {
//            cout << "ERROR" << endl;
//        }
//    }
//    for (std::map<string,bool>::iterator it=r1.temp_regs.begin(); it!=r1.temp_regs.end(); ++it){
//        if (r1.temp_regs[it->first] != r.temp_regs[it->first]) {
//            cout << "ERROR" << endl;
//        }
//    }
    cout << "-------------------------------" << endl;
    t0 = r.getReg();
    s0 = r.getReg();
    cout << "t0: " << t0 <<endl;
    cout << "t1: " << t1 <<endl;
    cout << "s0: " << s0 <<endl;
    cout << "t9: " << t9 <<endl;
    r.releaseReg(t0);
    r.releaseReg(s0);
    r.releaseReg(t1);
    r.releaseReg(s1);
    r.releaseReg(t2);
    r.releaseReg(t3);
    r.releaseReg(t4);
    r.releaseReg(t5);
    r.releaseReg(t6);
    r.releaseReg(t7);
    r.releaseReg(t8);
    r.releaseReg(t9);
    cout << "-------------------------------" << endl;
//    for (std::map<string,bool>::iterator it=r.saved_regs.begin(); it!=r.saved_regs.end(); ++it){
//        cout << it->first << " " << it->second << endl;
//    }
//    for (std::map<string,bool>::iterator it=r.temp_regs.begin(); it!=r.temp_regs.end(); ++it){
//        cout << it->first << " " << it->second << endl;
//    }
//    for (std::map<string,bool>::iterator it=r1.saved_regs.begin(); it!=r1.saved_regs.end(); ++it){
//        if (r1.saved_regs[it->first] != r.saved_regs[it->first]) {
//            cout << "ERROR" << endl;
//        }
//    }
//    for (std::map<string,bool>::iterator it=r1.temp_regs.begin(); it!=r1.temp_regs.end(); ++it){
//        if (r1.temp_regs[it->first] != r.temp_regs[it->first]) {
//            cout << "ERROR" << endl;
//        }
//    }
    return true;
}

vector<int> merge(const vector<int> &l1,const vector<int> &l2)
{
    vector<int> newList(l1.begin(),l1.end());
    newList.insert(newList.end(),l2.begin(),l2.end());
    return newList;
}


int main() {
//    test_regs();
    vector<int> a;
    vector<int> b (1,1);
    vector<int> c = merge(a, b);
    cout << c.empty() << endl;

    return 0;
}