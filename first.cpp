#include <iostream> 
#include <string> 


int operate(int number_1 , int number_2, char operatorValue){
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
        return number_1 / number_2;
    } 
    else {
        std::cout << "Unknown operator!" << std::endl;
        return 0;
    }

}

int getInput(int &number_1,int &number_2, char operatorValue){
    number_1 = 2; 
}




int main() {

    while(true){
        std::cout << "calculator: " << std::endl;
        int a,b; 

        getInput(a,b,z);
        int result = operate(x,y,z);
        std::cout << "Result :  " << result << std::endl;
    }





    // ----- 
    std::string input; 
    double number_1;
    double number_2;
    char opr; 
    
    while (true) {
        std::cout << "calculator: " << std::endl;
        std::cin >> input;
        if (input == "exit" || input == "EXIT" || input == "Exit") break; 
        try { 
            number_1 = std::stod(input); 
        } catch (...) {
            std::cout << "Invalid number!" << std::endl;
            continue; // برگرد به ابتدای حلقه 
        }
        std::cin >> input;
        if (input == "exit") break;
        opr = input[0]; 
        std::cin >> input;
        if (input == "exit") break;
        try {
            number_2 = std::stod(input);
        } catch (...) {
            std::cout << "Invalid number!" << std::endl;
            continue; // برگرد به اول حلقه 
        } 
        // std::cin >> number_1;
        // std::cin >> opr;
        // std::cin >> number_2;
        if (number_1 > 999999999 || number_1 < -999999999 || number_2 > 999999999 || number_2 < -999999999){
        std::cout << "Error: number out of allowed range!" << std::endl;
        continue; 
    }
    switch (opr) { 
        case '+':
            std::cout << number_1 + number_2 << std::endl;
            break;
        case '-':
            std::cout << number_1 - number_2 << std::endl;
            break;
        case '*':
            std::cout << number_1 * number_2 << std::endl;
            break;
        case '/': 
            if (number_2 == 0) {
                std::cout << "undefined" << std::endl;
            }
            else {
                std::cout << number_1/number_2 << std::endl;
            }
        break; 
        default:
            std::cout << "Unknown operator!" << std::endl;  
    } 
    
    }
    return 0; 
}