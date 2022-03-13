#include "ED.hpp"

ED::ED(){//default
	
}

ED::ED(string pass_string_x, string pass_string_y){
  string_x = pass_string_x;
  string_y = pass_string_y;
}

ED::~ED(){

}

int ED::penalty(char a, char b){
	if(a == b){
	return 0;
	}  
	else if(a!=b){
    return 1;
	}
  return -1;
}

int ED::min(int a, int b, int c){
	if(a < b && a < c){
		return a;
	}

	else if(b < a && b < c){
		return b;
	}

	else if(c < a && c < b){
		return c;
	}
	return a;
}

int ED::OptDistance(){
	int N = string_x.length();
	int M = string_y.length();

	for(int i = 0; i <= M; i++){
		vector<int> temp;
		matrix.push_back(temp);
	
		for(int j = 0; j <= N; j++){
		matrix.at(i).push_back(0);
    }
 }


	for(int i = 0; i <= M; i++){
		matrix[i][N] = 2 * (M - i);
	}

	for(int j = 0; j <= N; j++){
		matrix[M][j] = 2 * (N - j);
	}

  for(int i = M - 1; i >= 0; i--){
    for(int j = N - 1; j >= 0; j--){
      int opt1 = matrix[i+1][j+1] + penalty(string_x[j], string_y[i]);
      int opt2 = matrix[i+1][j] + 2;
      int opt3 = matrix[i][j+1] + 2;

      matrix[i][j] = min(opt1, opt2, opt3);
    }
  }

  return matrix[0][0];
}

string ED::Alignment(){
	ostringstream Ostream;
	int M = string_y.length();
	int N = string_x.length();
	int i = 0;
	int j = 0;
	int penalty_num;
	int opt1;
	int opt2;
	int opt3;
	string result;

	while(i < M || j < N){
   
	  try{
		penalty_num =  penalty(string_x[j], string_y[i]);
		opt1 = matrix.at(i+1).at(j+1) + penalty_num;
      }
    catch(const out_of_range& bad){
      opt1 = -1;
    }
    try{
      opt2 = matrix.at(i+1).at(j) + 2;
    }catch(const out_of_range& bad)
    {
      opt2 = -1;
    }
    try{
      opt3 = matrix.at(i).at(j+1) + 2;
    }catch(const out_of_range& bad)
    {
      opt3 = -1;
    }

    if(matrix[i][j] == opt1){//diag
		Ostream << string_x[j] << " " <<  string_y[i] << " "  << penalty_num << endl;
		i++;
		j++;
    }

    else if(matrix[i][j] == opt2){//down
		Ostream << "- " << string_y[i] << endl;
		cout<<endl;
		i++;
    }

    else if(matrix[i][j] == opt3){//right
		Ostream << string_x[j] << " -" << endl;
		cout<<endl;
		j++;
    }
  }

  result = Ostream.str();
  return result;
}

