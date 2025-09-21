#include <iostream> 
#include <string> 
#include <cctype>
#include <sstream>


double operate(double number_1 ,char operatorValue, double number_2 ){
    if (operatorValue == '+') {
        return number_1 + number_2;
    }
    else if (operatorValue == '-') {
        return number_1 - number_2;
    }
    else if (operatorValue == '*') {
        return number_1 * number_2;
    }
    else if (operatorValue == '/'){
        if (number_2 == 0) {
            std::cout << "Error! second number should not be zero!" << std::endl; 
            return 0;
        }
        return number_1 / number_2 ; 
    } 
    else {
        std::cout << "Unknown operator!" << std::endl;
        return 0;
    }

} 

bool isNumber(const std::string &s){
    bool dotSeen = false;
    for (char c : s) {
        if (c == '.') {
            if (dotSeen) return false;
            dotSeen = true; 
        } 
        else if (!isdigit(c)) {
            return false;
        }
    }
    return !s.empty(); 
}


void numericRange(double number_1 , char &opr , double number_2) { 
    if (number_1 > 99999 ||  number_1 < -99999 || number_2 > 99999 || number_2 < -99999) {
        std::cout << "Error! Numbers must be between -99999 and 99999. " << std::endl;
        opr = 'e'; 
    }
}




void getInput(double &number_1 , char &opr , double &number_2){

    std::cout<< "If you want to quit program please enter exit! " << std::endl;
    std::cout<< "Enter your operation: "; 

    std::string line; 
    std::getline(std::cin, line);
    
    if (line.empty()){
        std::cout << "Please enter a valid operation! " << std::endl;
        opr = 'e';
        return;
    }
    
    
    if (line == "exit"){
        opr = 'q';
        return;
    }

    std::string num1_str, num2_str;
    std::stringstream ss(line);

    if (!(ss >> num1_str >> opr >> num2_str)) {
        std::cout <<"Error! Please enter in format: number operator number" << std::endl;
        opr = 'e';
        return;
    } 

    if (num2_str.empty()) {
        std::cout << "Please enter number 2! " << std::endl;
        opr = 'e';
        return;
    }



    if (!isNumber(num1_str) || !isNumber(num2_str)) {
        std::cout << "Error! Please enter correct number..." << std::endl;  
        opr = 'e'; 
        return;
    } 

    number_1 = std::stod(num1_str); 
    number_2 = std::stod(num2_str); 
    
    

    
     
}






int main(){ 
    while (true){
        double num1 , num2; 
        char op;

        

        getInput(num1,op,num2); 
        numericRange(num1,op,num2) ; 
        if (op == 'q') {
            std::cout << "Exiting program..." << std::endl; 
            break;
        } 

        if (op == 'e') {
            continue;
        }


        double result = operate (num1,op,num2);
        std::cout << "Result = " << result << std::endl; 


        

    }
return 0; 
}