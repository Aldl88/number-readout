#include <iostream>
#include <stdio.h>
#include <vector>
#include <array>
#include <string>
#include <windows.h>

using namespace std;
string one_num_detector(char num) {
	switch (num)
	{
	case '0':
		return "";
	case '1':
		return "one";
		break;
	case '2':
		return "two";
		break;
	case '3':
		return "three";
		break;
	case '4':
		return "four";
		break;
	case '5':
		return "five";
		break;
	case '6':
		return "six";
		break;
	case '7':
		return "seven";
		break;
	case '8':
		return "eight";
		break;
	case '9':
		return "nine";
		break;
	}
	return "-1";
}

string tens_detector(char num) {
	switch (num)
	{
	case '0':
		return "ten";
	case '1':
		return "eleven";
		break;
	case '2':
		return "twelve";
		break;
	case '3':
		return "thirteen";
		break;
	case '4':
		return "fourteen";
		break;
	case '5':
		return "fifteen";
		break;
	case '6':
		return "sixteen";
		break;
	case '7':
		return "seventeen";
		break;
	case '8':
		return "eighteen";
		break;
	case '9':
		return "ninteen";
		break;
	}		
	return "-1";
}

string two_num_detector(char num_1 , char num_2) {
	switch (num_1)
	{
	case '0':
		return "";
	case '1':
		return tens_detector(num_2);
		break;
	case '2':
		return "twenty";
		break;
	case '3':
		return "thirthy";
		break;
	case '4':
		return "forthy";
		break;
	case '5':
		return "fifty";
		break;
	case '6':
		return "sixty";
		break;
	case '7':
		return "seventy";
		break;
	case '8':
		return "eithy";
		break;
	case '9':
		return "ninethy";
		break;
	}
	return "-1";

}

string print(long long number) {
	string num = to_string(number);
	int numLen = num.length();
	reverse(num.begin(), num.end());
	string result;
	for (int i = numLen - 1; i >=0  ; i--) {
		switch (i % 3)
		{
		case 2:
			 result +=one_num_detector(num[i]);
			 result += " hundred ";
			 break;
		case 1:
			result += two_num_detector(num[i], num[i - 1]);
			result += " ";
			break;
		default:
			break;

		case 0:
			if (num[i + 1] != '1') {
				result += one_num_detector(num[i]);
				result += " ";
			}
			break;
		}

		switch (i)
		{
		case 9:
			result += "billion ";
			break;
		case 6:
			result += "million ";
			break;
		case 3:
			result += "thousand ";
			break;
		default:
			break;
		}

	}

	return result;
}

int main(int argc, char* argv[]) {
	//vector<double> student_scores{ 0, 100, 100 };
	//vector<string> student_names{ "Nur", "Tony", "Fatima" };
	//vector<int>    rouded_scores{};
	//vector<int>    top{};
	//array <int, 4> grades{};
	//vector<string> ranking{};
	//vector<string> perfect_score_Name;
	//int failed_count;
	long long num{222'333'444};

	cout<<print(num);

	return 0;
}