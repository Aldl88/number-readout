#include <iostream>
#include <stdio.h>
#include <vector>
#include <array>
#include <string>
#include <windows.h>

using namespace std;

vector<int> round_down_scores(vector<double> student_scores) {
	vector<int> result{};
	

	for (double i : student_scores) {
		result.emplace_back(static_cast<int>(i));
	}
	return result;

}

struct ElectionResult {
	// Name of the candidate
	std::string name{};
	// Number of votes the candidate has
	int votes{};
};

int count_failed_students(vector<int> scores) {
	int counter{};

	for (int i : scores) {
		if (i < 40) {
			counter++;
		}
	}

	return counter;
}

vector<int> above_threshold(vector<int> student_scores, int topScore) {
	vector<int> result;

	for (int i : student_scores) {
		if (i >= topScore) {
			result.push_back(i);
		}
	}

	return result;
}


array<int , 4> letter_grades(int score) {
	array<int, 4> result{};
	const int lowest = 40;

	int level = (score - lowest) / 4;
	int add_num = 0;

	for (int& i : result) {
		i += lowest + add_num + 1;
		add_num += level;
	}

	return result;

}

vector<string> student_ranking(vector<int> student_scores,vector<string> student_names) {
	vector<string> result{};
	string temp;
	

	for (int i = 0; i < student_scores.size();i++ ) {
		result.emplace_back(to_string(i + 1) + ". " + student_names[i] + ": " + to_string(student_scores[i]));
	}

	return result;
}

vector<string> perfect_score(vector<int> student_scores, vector<string> student_names) {
	int counter = 0;
	vector<string> result;

	for (int i : student_scores) {
		if (i == 100) {
			 result.push_back(student_names[counter]);
		}
		counter++;
	}
	return result;
}

int vote_count(ElectionResult &a) {
	return a.votes;
}

vector<string> split_into_triplets(int number) {
	vector<string> triplets;

	for (int i = 0; i < to_string(number).length() / 3; i++) {
		triplets.push_back(to_string(number % 1000));
		number /= 1000;
	}
	triplets.push_back(to_string(number));

	return triplets;
}

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
	cout << num << endl;
	int numLen = num.length();
	reverse(num.begin(), num.end());
	string result;
	for (int i = numLen - 1; i >=0  ; i--) {
		cout << num[i] << endl;
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
	SetConsoleOutputCP(1256);
	long long num{222'333'444};

	cout<<print(num);

	return 0;
}