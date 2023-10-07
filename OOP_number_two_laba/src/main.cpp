#include "Decimal.h"



void check_number_correct(char elem_number){
        if (elem_number < '0' || elem_number > '9'){
            throw logic_error(" это недопустимый символ. Число может содержать символы 0,1,2,3,4,5,6,7,8,9. Осуществите ввод числа заново");
        }
    }

void check_operation_correct(string oper){
        if (oper != "+" && oper != "-" && oper != "=" && oper != ">"  && oper != "<"){
            throw logic_error(" это недопустимая операция. Существуют операции +, -, =, >, <. Осуществите ввод операции заново");
        }
    }

void not_empty(string number){
    if (number.length() == 0){
        throw logic_error(" введена пустая строка. Выполнять операцию несчем. Введите число, которое может содержать символы 0,1,2,3,4,5,6,7,8,9");
    }
}

int main(){
    string operation;
    string f_number;
    string s_number;
    char unsuitable_elem;
    bool first_number;
    bool correct_operation;
    bool second_number;
    
    first_number = true;
    cout << "введите первое число:" << endl;
    while(first_number){
        getline(cin, f_number);
        try{
            not_empty(f_number);
            for(char elem_number : f_number){
                unsuitable_elem = elem_number;
                check_number_correct(elem_number);
            }
            first_number = false;
            cout << "первое число = " << f_number << endl;
        }
        catch (exception &ex){
            cout << unsuitable_elem << ex.what() <<endl;
        }
    }
    
    correct_operation = true;
    cout << "Введите операцию:" << endl;
    while (correct_operation){
        getline(cin, operation);
        try{
            check_operation_correct(operation);
            correct_operation = false;
        }
        catch (exception &ex){
            cout << operation << ex.what() <<endl;
        }

    }

    
    second_number = true;
    cout << "введите втрое число:" << endl;
    while(second_number){
        getline(cin, s_number);
        try{
            not_empty(s_number);
            for(char elem_number : s_number){
                unsuitable_elem = elem_number;
                check_number_correct(elem_number);
            }
            second_number = false;
            cout << "второе число = " << s_number << endl;
        }
        catch (exception &ex){
            cout << unsuitable_elem << ex.what() <<endl;
        }
    }

    cout << "Получаем ";

    Decimal l_number{f_number}, r_number{s_number};

    try{
        if(operation == "+") 
            l_number.add(r_number).print(cout) << '\n';
        else if(operation == "-") 
            l_number.remove(r_number).print(cout) << '\n';
        else if(operation == "="){
            if(l_number.equal(r_number)) 
                cout << "эквивалентны" << endl;
            else 
                cout << "не эквивалентны" << endl;
        }
        else if(operation == ">"){
            if(l_number.big(r_number)) 
                cout << "Верно" << endl;
            else 
                cout << "Не верно" << endl;
        }
        else if(operation == "<"){
            if(l_number.small(r_number)) 
                cout << "Верно" << endl;
            else 
                cout << "Не верно" << endl;
        }
    }
    catch(exception &ex){
        cerr << "Ошибка: " << ex.what() << endl;
    }

    return 0;
}
