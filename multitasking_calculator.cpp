#include <iostream> 
#include <string> 
#include <cctype>
#include <sstream> 



double operate(double &number_1 ,char &operatorValue, double &number_2 ){
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



void getInput(){

}


int main(){ 
    std::string line;
    std::string token;
    int pos = 0;
    while(true) { 
        std::cout << "Enter something: " << std::endl;
        std::getline(std::cin,line);
        std::stringstream ss(line);
        char chr; 
        double num1 , num2;
        bool isFirst = true; 
        while (ss >> token) {
            bool isNumber = true; 
            if (pos % 2 == 0){ 
                for (char c : token) {
                    if (!isdigit(c) && c != '.') {
                        !isNumber;
                        std::cout << "It is not a number!" << std::endl;
                        break;
                    }
                }
                if (isFirst){
                    num1 = std::stod(token); 
                    isFirst = false;
                }else {
                    num2 = std::stod(token); 
                    num1 = operate(num1,chr,num2);

                }
            pos++;
            } 

            else if (pos % 2 != 0) {
                if (token != "+" && token != "-" && token != "*" && token != "/") {
                    std::cout << "Error! Expected an operator but got: " << token << std::endl;
                    break;
                } else if (token == "+" || token == "-" || token == "*" || token == "/"){ 
                    chr = token[0];
                    pos++;
                }
            }


        }
        std::cout << "Resultttt = " << num1 << std::endl; 
        pos = 0;
    }


}