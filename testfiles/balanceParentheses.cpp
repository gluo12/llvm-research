#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

char opposite(char input);

int main(){
	vector<char> data;
	char next = 'n';
	bool balanced = true;
	for(istream_iterator<char> start = istream_iterator<char>(cin); start != istream_iterator<char>(); ++start){
		if(*start == '(' || *start == '{' || *start == '['){
			data.push_back(*start);
			next = opposite(*start);
		}
		else if(*start == next){
			if(next != 'n'){
			// if(next == ')' || next == '}' || next == ']'){
				data.pop_back();
				next = opposite(data.back());
			}
		}
		//once the above conditions have been checked, if one of these parentheses appears
		//that means that it is unbalanced
		else if(*start == ')' || *start == '}' || *start == ']'){
			balanced = false;
			break;
		}
	}

	if(!data.empty()){
		balanced = false;
	}

	if(balanced){
		cout << "Balanced" << endl;	
	}
	else{
		cout << "Not balanced" << endl;
	}
}

char opposite(char input){
	if(input == '('){
		return ')';
	}
	if(input == '{'){
		return '}';
	}
	if(input == '['){
		return ']';
	}
	return 'n';
}
