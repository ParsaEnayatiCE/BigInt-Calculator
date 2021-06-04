
//-----------------------------------Simple Calculator-----------------------------------//

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

string findSum(string str1, string str2);
string findDiff(string str1, string str2);
string findMultiply(string num1, string num2);
string findDivision(string number, int divisor);
string findPower(string number, int power);
bool isSmaller(string str1, string str2);



int main() {

    string first;
    string mathOperator;
    string second;

    cout << "Enter First Number:" << endl;
    cin >> first;
    cout << "Enter Operator(/ * + - ^):" << endl;
    cin >> mathOperator;
    cout << "Enter First Number:" << endl;
    cin >> second;

    char firstNegativeOrPositive;
    char secondNegativeOrPositive;

    if (first[0]=='-'){
        first.erase(std::remove(first.begin(), first.end(), '-'), first.end());
        firstNegativeOrPositive = '-';
    }
    else{
        firstNegativeOrPositive = '+';
    }
    if (second[0]=='-'){
        second.erase(std::remove(second.begin(), second.end(), '-'), second.end());
        secondNegativeOrPositive = '-';
    }
    else{
        secondNegativeOrPositive = '+';
    }

    //------------------SUM-----------------//
    if (mathOperator == "+"){
        if (firstNegativeOrPositive == '+' && secondNegativeOrPositive == '+'){
            cout << findSum(first,second);
        }
        else if (firstNegativeOrPositive == '-' && secondNegativeOrPositive == '-'){
            cout << "-" << findSum(first,second);
        }
        else if (firstNegativeOrPositive == '+' && secondNegativeOrPositive == '-'){
            string resultNegativeOrPositive = "";
            if (isSmaller(first,second) && findDiff(first,second)[0]!='0'){
                resultNegativeOrPositive = "-";
            }
            cout << resultNegativeOrPositive << findDiff(first,second);
        }
        else{
            string resultNegativeOrPositive = "";
            if (!isSmaller(first,second) && findDiff(first,second)[0]!='0'){
                resultNegativeOrPositive = "-";
            }
            cout << resultNegativeOrPositive << findDiff(first,second);
        }
    }

    if (mathOperator == "-"){
        if (firstNegativeOrPositive == '+' && secondNegativeOrPositive == '+'){
            string resultNegativeOrPositive = "";
            if (isSmaller(first,second) && findDiff(first,second)[0]!='0'){
                resultNegativeOrPositive = "-";
            }
            cout << resultNegativeOrPositive << findDiff(first,second);
        }
        else if (firstNegativeOrPositive == '-' && secondNegativeOrPositive == '-'){
            string resultNegativeOrPositive = "";
            if (!isSmaller(first,second) && findDiff(first,second)[0]!='0'){
                resultNegativeOrPositive = "-";
            }
            cout << resultNegativeOrPositive << findDiff(first,second);
        }
        else if (firstNegativeOrPositive == '+' && secondNegativeOrPositive == '-'){
            cout << findSum(first,second);
        }
        else{
            cout << "-" << findSum(first,second);

        }
    }

    if (mathOperator == "*"){
        string resultNegativeOrPositive;
        if ((firstNegativeOrPositive == '-' && secondNegativeOrPositive == '-') || (firstNegativeOrPositive == '+' && secondNegativeOrPositive == '+')){
            resultNegativeOrPositive = "";
        }
        else{
            if (first!="0" && second!="0") {
                resultNegativeOrPositive = "-";
            }
        }
        cout << resultNegativeOrPositive << findMultiply(first,second);

    }

    if(mathOperator == "/"){
        stringstream geek(second);
        int divisor = 0;
        geek >> divisor;
        string resultNegativeOrPositive;
        if ((firstNegativeOrPositive == '-' && secondNegativeOrPositive == '-') || (firstNegativeOrPositive == '+' && secondNegativeOrPositive == '+')){
            resultNegativeOrPositive = "";
        }
        else{
            if (first!="0" && second!="0") {
                resultNegativeOrPositive = "-";
            }
        }
        if (second == "0"){
            cout << "Can not divide number to zero!";
        }
        else{
            cout << resultNegativeOrPositive << findDivision(first,divisor);
        }
    }

    if(mathOperator == "^"){
        if (first == "0" && second == "0"){
            cout << "Not initialized";
        }
        else if (first != "0" && second == "0"){
            cout << "1";
        }
        else{
            stringstream geek(second);
            int power = 0;
            geek >> power;
            string resultNegativeOrPositive = "";
            if (firstNegativeOrPositive == '-' && power%2==1 ){
                resultNegativeOrPositive = "-";
            }
            cout << resultNegativeOrPositive << findPower(first,power);

        }

    }


}

//-------------------Main Functions-------------------------------------//

string findSum(string str1, string str2)
{
    if (str1.length() > str2.length())
        swap(str1, str2);

    string str = "";
    int n1 = str1.length(), n2 = str2.length();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    if (carry)
        str.push_back(carry+'0');
    reverse(str.begin(), str.end());

    return str;
}

string findDiff(string str1, string str2)
{

    if (isSmaller(str1, str2))
        swap(str1, str2);

    string str = "";

    int n1 = str1.length(), n2 = str2.length();


    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;

    for (int i = 0; i < n2; i++) {


        int sub
            = ((str1[i] - '0') - (str2[i] - '0') - carry);


        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }


    for (int i = n2; i < n1; i++) {
        int sub = ((str1[i] - '0') - carry);


        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }


    reverse(str.begin(), str.end());

    return str;
}

string findMultiply(string num1, string num2)
{
    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 == 0 || len2 == 0)
        return "0";
    vector<int> result(len1 + len2, 0);
    int i_n1 = 0;
    int i_n2 = 0;
    for (int i=len1-1; i>=0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';

        i_n2 = 0;

        for (int j=len2-1; j>=0; j--)
        {
            int n2 = num2[j] - '0';
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;
            carry = sum/10;
            result[i_n1 + i_n2] = sum % 10;
            i_n2++;
        }

        if (carry > 0)
            result[i_n1 + i_n2] += carry;

        i_n1++;
    }

    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
        i--;

    if (i == -1)
        return "0";

    string s = "";

    while (i >= 0)
        s += std::to_string(result[i--]);

    return s;
}

string findDivision(string number, int divisor)
{
    string ans;
    int idx = 0;
    int temp = number[idx] - '0';
    while (temp < divisor)
        temp = temp * 10 + (number[++idx] - '0');

    while (number.size() > idx) {
        ans += (temp / divisor) + '0';

        temp = (temp % divisor) * 10 + number[++idx] - '0';
    }

    if (ans.length() == 0)
        return "0";

    return ans;
}

string findPower(string number, int power){
    string temp = number;


    for (int i = 1; i < power ; i++) {
        number = findMultiply(number,temp);
    }
    return number;
}



//---------------------Help Functions---------------------------------//

bool isSmaller(string str1, string str2)
{
    int n1 = str1.length(), n2 = str2.length();

    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;

    for (int i = 0; i < n1; i++)
        if (str1[i] < str2[i])
            return true;
        else if (str1[i] > str2[i])
            return false;

    return false;
}
