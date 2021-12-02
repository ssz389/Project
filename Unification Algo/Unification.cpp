/*******************************************************************
*Name: Suby Singh
*Description: This is a C++ program file containing code related to Unification algorithm implementation
*
*Compile: "g++ assign1ssz389.cpp -o assign1ssz389"
*Sample run: "assign1ssz389 "f(f(X,Y),X),f(f(V,U),g(U,Y))""   --- provide both the terms inside double quotes with a comma in between as shown in sample run.
*
*
*
*
*********************************************************************/

//include hearder files section
#include <iostream>
#include <string>
#include <iterator> 
#include <map> 
#include <vector>

using namespace std;

//function decalaration section
bool check_input(string); 						//checks syntax of the input terms
bool find_two_terms(string);					//finds two terms from a single input(2 terms are comma seperated)
bool check_for_more_terms(string);				//looks if more terms than 2 terms
int check_type(string);							//checks type of the terms, i.e. function, variable, or constant
int process_unification(string,string);			//builds unification algorithm
bool check_matched_argument(string, string);	//checks if Variable is the part of funtion argument
void call_substitute(map<string, string> &, map<string, string> &);	//substitues the selected values for variables using 2 maps
string check_functionName(string);				//finds function name
int check_noOfArg(string);						//checks number of arguments to a function
vector<string> getargument(string);				//retrieves the list of arguments of a function

//global variables declaration
bool valid = true;								//Used to maintain status of the program globally
string first_term = "";							//first term
string second_term = "";						//second term
map<string, string> replacable;					//map to get the substitution
map<string, string> replaced;					//map to store the sunstitution

int main(int argc, char* argv[])
{
	int var = 1;
	if(argc != 2)
	{
		cout<<"Argument ERROR:" << "usage: " << argv[0] << " <term1,term2> "<<endl;
		return -1;
	}
	string input(argv[1]);
	//string input = argv[1];  // both are same
	
  cout<<"...checking input syntax " <<endl;
	if(!check_input(input))                     //check the input term syntaxically
	{	return -1;}
	cout<<"...finding terms " << endl;
	if(!find_two_terms(input))					//find the two terms from the input string
	{	return -1;}
	cout << "Term1 = " << first_term << " Term2 = "<<second_term<<endl;
	if(!check_for_more_terms(second_term))		//check for more than 2 terms, if yes exit()
	{	cout<<"Require only two terms"<<endl; return -1; }
	int first_type = check_type(first_term);	//find the type of term1
	int second_type = check_type(second_term);	//find the type of term2
	cout<<"Type(term1) = " <<first_type<<" Type(term2) = "<<second_type<<endl;
	if (first_type == 1 and second_type == 1 and first_term != second_term)
	{	
    cout<<'\t' << second_term <<" = "<< first_term << endl;     //print the list of substitution if any
		cout << "\tyes"<<endl;
		return 0;
	}
	while(var == 1)
	{
		if (replacable.empty())
			var = process_unification(first_term,second_term);		//call unification algorithm implentation with initial terms
		else
		{
			string s = replacable.begin()->first;	//"from" string
			string to = replacable.begin()->second;	 //"to" string
			size_t pos = 0;
			while((pos = first_term.find(s, pos)) != std::string::npos) 	//If "from" found in term1
			{
        first_term.replace(pos, s.length(), to); //replace it with "to"
        pos += to.length();		// Handles case where 'to' is a substring of 'from'
    	}
			pos = 0;
      while((pos = second_term.find(s, pos)) != std::string::npos)	//If "from" found in term2
      {
        second_term.replace(pos, s.length(), to);		//replace it with "to"
        pos += to.length();		// Handles case where 'to' is a substring of 'from'
      }
			/*//if (first_term.find(s) != std::string::npos)
			//	first_term.replace(first_term.find(s), s.length(), replacable.begin()->second);
			//if (second_term.find(s) != std::string::npos)
			//	second_term.replace(second_term.find(s), s.length(), replacable.begin()->second);*/
			replacable.clear();
			var = process_unification(first_term,second_term);    //call unification algorithm implementation with updated terms
		}
	}
	if (var == 0)	//monitor the solution; 0 means unification not applicable
	{
		cout <<"\tno"<<endl;
		replaced.clear();
	}
	else if (var == -1)		//error in input
	{
		cout <<"\tinput error"<<endl;
		replaced.empty();
	}
	else if (var == 2)	 //substitution can be performed to unify the terms
	{
		map<string, string>::iterator itr;
		for (itr = replaced.begin(); itr != replaced.end(); ++itr)
		{
			cout<<'\t' << itr->first <<" = "<<itr->second << endl;	//print the list of substitution if any
		}
		cout << "\tyes"<<endl;
	}
	return 0;
}

bool check_input(string ip)
{
	int character;
	int brackets = 0;
	for(int i=0; i<ip.length(); i++)	//count the number of opening and closing bracket
	{
		if(ip[i] == '(')
			brackets ++;
		else if (ip[i] == ')')
			brackets --;

		if (ip[i] != ')' && character == ip.length())
      valid = false;
		character++;
	}
	if (brackets != 0)		//if number of brackets do not match, return error
		valid = false;

	return valid;
}

bool find_two_terms(string ip)		//This function looks for two terms 
{
	size_t  pos = 0;
	int cnt = 0;
	bool found = false;
	int brackets = 0;
  while( cnt != ip.length() && found == false)
  {
    pos+=1;
		brackets = 0;
    pos = ip.find(",", pos);	//looks for comma and then finds substring 
    if ( pos == std::string::npos )
    {	valid = false;
			return valid;}
		first_term = ip.substr(0,pos);
		second_term = ip.substr(pos+1);
		for (int i = 0; i<first_term.length(); i++)	 //checks for the number of brackets
		{
			if(first_term[i] == '(')
			brackets ++;
      else if (first_term[i] == ')')
		  brackets --;
		}
		if (brackets != 0)
			continue;
		else
			found = true;
    cnt++;
  }
  return valid;
}	

bool check_for_more_terms(string second_term)
{
	size_t  pos = 0;
  int cnt = 0;
  bool found = false;
  int brackets = 0;
	bool ifFirst = 1;
  string second_trm = "", next_trm = "";
  while( cnt != second_term.length() && found == false)
  {
		pos+=1;
    brackets = 0;
    pos = second_term.find(",", pos);	//divides the second term based on comma and brackets
    if ( pos == std::string::npos && ifFirst)
			return valid;
    else
		{
      ifFirst = false;
			if ( pos == std::string::npos)
			{	valid = true; return valid;}
			second_trm = second_term.substr(0,pos);
      next_trm = second_term.substr(pos+1);
      for (int i = 0; i<second_term.length(); i++)
      {
				if(second_trm[i] == '(')
					brackets ++;
        else if (second_trm[i] == ')')
          brackets --;
      }
      if (brackets != 0)
        continue;
      else
				found = true;
		}
    cnt++;
  }
	if (! next_trm.empty())		//If next_term is not empty, it means input has more than 2 terms
		valid = false;

	return valid;
}

int check_type(string term)		//finds the type of terms
{
    int type = -1;
	for (int i = 0; i<term.length(); i++)
	{
		if (!isalpha(term[i])) 
		{	if(term[i] == '(' || term[i] == ')' || term[i] == ',')
				continue;
			else
			{	type = 0;	//if not alpha, bracket and comma then invalid character
				return type; //invalid_type
			}		
		}
	}
	if(term.find('(')!=std::string::npos || term.find(')')!=std::string::npos || term.find(',')!=std::string::npos)
	{
		if (term.find('(')!=std::string::npos && term.find(')')!=std::string::npos)
		{
			if (check_input(term))
				type = 3;   //function_type
			else
				type = 0;	//type_error
		}
		else if (term.find('(')!=std::string::npos && term.find(')')==std::string::npos)
			type = 0;		//type_error
		else if (term.find('(')==std::string::npos && term.find(')')!=std::string::npos)
			type = 0;		//type_error
	}
	else if (term.find('(')==std::string::npos && term.find(')')==std::string::npos && term.find(',')==std::string::npos)
	{
		for (int i = 0; i <term.length(); i++)
		{
			if(isupper(term[i]))
				type = 1; //variable_type
			else
				type = 2; //constant_type	
		}
	}
	return type;
}

int process_unification(string term1, string term2)		//implementation of unification algorithm
{
	int var = 1;
	int term1_type = check_type(term1);		//check the input term's type
	int term2_type = check_type(term2);
	if (term1_type == -1 or term2_type == -1)
		return -1;    //return "error"
	
	if (term1_type == 3 or term2_type == 3)
	{
		if(term1_type == 2 or term2_type == 2)
			return 0;  // return "no"
		else
		{
			if(term1_type == 1 and term2_type == 3) 	// if term1 is variable and term2 is function
			{
				if(check_matched_argument(term1,term2))  //If argument of term2 contains term1
					return 0;     //return "no"
				else
				{
					replacable.insert(pair<string,string>(term1,term2));   //add substitution
					if (!replaced.empty())
						call_substitute(replaced,replacable);
					replaced.insert(pair<string,string>(term1,term2));
					return 1; //to replace the value of variable with fucntion
				}
			}
			else if(term1_type == 3 and term2_type == 1) 	// if term1 is function and term2 is variable
			{
				if(check_matched_argument(term2,term1)) 	//If argument of term1 contains term2
					return 0; //return "no"
				else
				{
					replacable.insert(pair<string,string>(term2,term1)); //add substitution
					if(!replaced.empty())
						call_substitute(replaced,replacable);
					replaced.insert(pair<string,string>(term2,term1));
					return 1; //to replace the value of variable with function
				}
			}
			else  	//term1 and term2 both are function
			{
				string f1 = check_functionName(term1);
				string f2 = check_functionName(term2); 
				int a1 = check_noOfArg(term1);
				int a2 = check_noOfArg(term2);
				if (a1 == -1 or a2 == -1)
					return -1; //return "error"
				if(f1==f2 && a1==a2)	//unify only if function name and number of arguments are same
				{
					int cnt = 0;
					vector<string> arg1 = getargument(term1);	//get argument list of term1
					vector<string> arg2 = getargument(term2);	//get arguemnt list of term2
					while(cnt < arg1.size())
					{
						var = 1;
						var = process_unification(arg1[cnt],arg2[cnt]);	//unify the arguments
						if (var == 1)
							return 1;	//to replace the value of variable with function
						else if(var == 0)
							return 0;	//return "no"
						else if(var == -1)
							return -1;	//return "inout error"
						else if (var == 2 and cnt == arg2.size()-1)
						{
							cnt++;		
							return 2;	//return "yes or true"
						}
						else
							cnt++;
					}
				}
				else
					return 0; //return "no"
			}
		}
	}
	else if (term1_type == 2 && term2_type == 2)  	//if both are constant
	{
		if (term1 == term2)
			return 2; //return "true"
		else
			return 0; //return "no"
	}
	else if (term1_type == 1 or term2_type == 1)   	//if either of terms is variable
	{
		if (term1_type == 1)
		{
			if(term2_type == 1)     // if both terms are variable
			{
				if (term1 == term2)
					return 2; //return "true"
				else     //if term 1 is variable and term2 is also a variable 
        {
					replacable.insert(pair<string,string>(term1,term2));   //add substitution
          if (!replaced.empty())
						call_substitute(replaced,replacable);
          replaced.insert(pair<string,string>(term1,term2));
          return 1; //to replace the value of variable with fucntion
				}
			}
			else    //if term 1 is variable and term2 is constant
			{
				replacable.insert(pair<string,string>(term1,term2));   //add substitution
        if (!replaced.empty())
					call_substitute(replaced,replacable);
        replaced.insert(pair<string,string>(term1,term2));
        return 1; //to replace the value of variable with fucntion
			}
		}
		else   	//if term2 is variable and term 1 is constant
		{
			replacable.insert(pair<string,string>(term2,term1));   //add substitution
      if (!replaced.empty())
				call_substitute(replaced,replacable);
      replaced.insert(pair<string,string>(term2,term1));
      return 1; //to replace the value of variable with fucntion
		}
	}
}	 //end of unification algo implementation

bool check_matched_argument(string term1, string term2)		//check if variable is the part of function argument
{
	string substring;
	size_t pos = term2.find(term1);		//look for term1 in term2
	if (pos != std::string::npos)
	{
		size_t comma = term2.find(",",pos);		//look for comma
		if (comma != std::string::npos)
		{
			substring = term2.substr(pos, (comma - pos));	//if yes, get the subsrting until then
		}
		else
		{
			substring = term2.substr(pos, (term2.length()-pos-1));	//if not, get substring untill last character
		}
	}
	else
	{
		return false;	// if variable not found, return false; means variable not found in term
	}
	if ( substring == term1 )	//if substring of term2 equals term1, means found and return true
		return true;
	else
		return false; //else false; not found
}

void call_substitute(map<string,string> &replaced, map<string,string> &replacable)	//substitue the variables
{
	map<string, string>::iterator itr;
	for (itr = replaced.begin(); itr != replaced.end(); ++itr) 
	{ 
    string s = replacable.begin()->first;
		string s1 = itr->second;
		if (s1.find(s) != std::string::npos)	//if replacable term found in final map, update it with new substitution
		{
			s1.replace(s1.find(s), s.length(), replacable.begin()->second);
			itr->second = s1;
		} 
  } 	
}

string check_functionName(string term)		//finds the function name
{
	size_t pos = term.find("(");		//find the opening bracket and find the substring till just before it
	string fun_name = term.substr(0,pos);
	return fun_name;	
}

int check_noOfArg(string term)		//check for the number of arguments
{
	int bracket = 0, comma = 0;
	for(int i = 0; i<term.length(); i++)
	{
		if(term[i] == '(')		//look for comma and brackets
			bracket++;
		else if (term[i] == ')')
			bracket--;
		if(term[i] == ',' and bracket == 1)
			comma++;
	}
	if (bracket == 0)
	{
		return ++comma;		//returns the number of arguments, if same number of brackets
	}
	else
		return -1;		  //if mismatch in the number of brackets, return error
}

vector<string> getargument(string term)		//get the list of arguemnts
{
	vector<string> arguments;
	size_t pos = term.find("(");
  string actualArgs = term.substr(pos+1,(term.length()-pos-2));
	string substring = "";
	int bracket = 0, comma =0;
	for(int i = 0; i<actualArgs.length(); i++)
	{
		if(actualArgs[i] == ',' and bracket == 0)	 //look for the comma seperated values in the term
		{
			comma++;
			arguments.push_back(substring);
			substring = "";
		}
		else
      substring = substring + actualArgs[i];				

		if(actualArgs[i] == '(')
			bracket++;
		else if(actualArgs[i] == ')')
			bracket--;
	}
	if(comma == 0)
	{
		arguments.push_back(actualArgs);	//store the value as it is if no comma found
	}
	else
		arguments.push_back(substring);		//If comma found stroe it seperately

	return arguments;		//returns the vector of arguments
}
