//
//  main.cpp
//  NumberWriter
//
//  Created by Dominic Chang on 2/1/14.
//  Copyright (c) 2014 Dominic Chang. All rights reserved.
//

#include <iostream>


#define ARC4RANDOM(max) (arc4random() % (int)(max))

#include <vector>
using namespace std;

typedef vector<string> v_str;
typedef v_str::iterator v_str_iter;

v_str Number_Singles ({
    " Zero",
    " One",
    " Two",
    " Three",
    " Four",
    " Five",
    " Six",
    " Seven",
    " Eight",
    " Nine",
    " Ten",
    " Eleven",
    " Twelve",
    " Thirteen",
    " Fourteen",
    " Fifteen",
    " Sixteen",
    " Seventeen",
    " Eighteen",
    " Nineteen"
});

v_str Number_Tens({
    "",
    " Ten",
    " Twenty",
    " Thirty",
    " Forty",
    " Fifty",
    " Sixty",
    " Seventy",
    " Eighty",
    " Ninety"
});

v_str Number_Thousands({
    " Hundred",
    " Thousand",
    " Million",
    " Billion",
    " Trillion"
});

string ThousandWriter(unsigned int hundred , unsigned int ten , unsigned int single) {
    
    string result;
    
    //ten , eleven , ... nineteen
    if (ten == 1) {
        
        result = Number_Singles[10 + single];
        
    } else {
        
        //singles
        if (single > 0) {
            result = Number_Singles[single];
        }
        
        //Twenty ...
        if (ten > 1) {
            result = Number_Tens[ten] + result;
        }
        
    }
    
    //hundreds
    if (hundred > 0) {
        result = Number_Singles[hundred] + Number_Thousands[0] + result;
    }
    
    
    return result;
}

string numberWriter(unsigned long value , unsigned int level) {
    
    if (value == 0 && level == 0) {
        return Number_Singles[0];
    }
    
    
    if (value == 0) {
        return "";
    }
    
    
    //parse 3 digits
    unsigned int single = value % 10;
    
    value /= 10;
    
    unsigned int ten = value % 10;
    
    value /= 10;
    
    unsigned int hundred = value % 10;
    
    value /= 10;
    
    //    cout << hundred << ":" << ten << ":" << single << endl;
    
    
    string levelString;
    if (level > 0 && hundred + ten + single > 0) {
        levelString = Number_Thousands[level];
    }
    
    
    return numberWriter(value , level + 1) + ThousandWriter(hundred, ten, single) + levelString;
}


typedef vector<unsigned long> v_ulong;
typedef v_ulong::iterator v_ulong_iter;

void testNumberWriter() {
    for (int i = 0; i < 10000; i++) {
        unsigned long number = ARC4RANDOM(10000000000);
        cout << number << " :" << numberWriter(number , 0) << endl;
    }
    
    v_ulong specialCasesNumbers({
        10000000000000,
        9000000000,
        10000,
        100,
        10,
        0
    });
    
    for (v_ulong_iter iter = specialCasesNumbers.begin(); iter != specialCasesNumbers.end(); iter++) {
        cout << *iter << " :" << numberWriter(*iter, 0) << endl;
    }
    
}


int main(int argc, const char * argv[])
{
    
    string input;
    
    do {
        
        testNumberWriter();
        
    } while (cin >> input && input != "q");
    
    return 0;
}

