/*******************************************************************
*Name: Suby Singh

*File: RBInstances.cpp
*Description: This is a C++ program file containing code related to generate RB instances for CSP
*
*Compile: "g++ assign2ssz389.cpp -o assign2ssz389"
*Sample run: "assign2ssz389"   --- Follow the execution for program input
*
*Please note : For some CSP cases, there can be no solution. This is due to random generation of constraints over the variables and domains.
*You can also enter lower value for p(tightness) and check the result.
*You can try running the program for lower value for tightness like 0.25, 0.3, and 0.2 and so on.
*
*********************************************************************/

//include hearder files section
#include <iostream>
#include <string>
#include <iterator> 
#include <map>
#include <cmath> 
#include <iomanip>
#include <vector>
#include <algorithm>
#include <sstream>
#include <time.h>

using namespace std;

//function decalaration section
bool getInputs(int &, float &, float &, float &);	//to get parameter input from the user
bool get_variables_and_domain(int, int);		//to determine variables and their domain values. Results in variables list and domain_ofvariables map
bool get_variables_pairs(int, vector<int>);		//to obtain CSP constraint pairs. Results in constraints_vars list
string convert_to_string(int);				//helper function to convert int to string
int convert_to_int(string);				//helper function to covert string to int
bool get_constraint(int);			//function to obtain constraints over the domain values of CSP constraint pairs. Results in constraint map
bool check_arc_consistency(vector<int>, map<int, vector<int> >, map<string, vector<string> >, bool revert=false);	//checks arc_consistency
bool domain_revision(string, bool);			//to perform domain revision for each CSP constraint pair according to arc_consistency
vector<string> get_constr_for_revArc(string);		//to obtain constraints for reverse pair of CSP constraint
vector<int> get_neighbours(vector<string>, int, int);	//obtains neighbours of a variable
bool std_back_Tracking();				//Implementation of standard back tracking CSP solver algorithm
bool forward_Checking();				//Implementation of forward checking CSP solver algorithm
bool full_look_Ahead();					//Implementation of full look ahead CSP solver algorithm
bool is_constraint_Satified(int, int);			//to check if the constraints defined in constraint map for each CSP constraint pair is satisfied while variable assignement
bool check_subconstr(int, int);				//Finds sub constraints in case of full look ahead algorithm

//global variables declaration
vector<int> variables;					//Stores the list of variables for CSP
vector<string> constraints_vars;			//Stores the CSP constraint pair seperated by "|"
map< int, vector<int> > domain_of_variables;		//Stores the domain of each CSP variable
map< string, vector<string> > constraint;		//Stores constraint over the domain values for each CSP constraint pair defined in constraints_vars, seperated by ","
map<int, int> var_assign;				//Stores the assignement of domain value for each CSP variable

int main(int argc, char* argv[])
{
	int n, domain_size, constraint_size, incompatible_tuples, input;
	float p, a, r;
	char ar = 'n';
	if (!getInputs(n, p, a, r))			//obtain RB parameter inputs
	{
		cout<<"Input error from getInputs(): value for tightness(p), alpha(a) and r constant must be between 0 and 1"<<endl;
		return -1;
	}
	domain_size = int(round(pow(n,a)));			//calculate domain size
	cout << endl<<setw(50)<<"Domain size(d), (n^alpha)"<<": "<<domain_size;
	constraint_size = int(round(n * r * log(n)));	//calculate constraint size
	cout << endl<<setw(50)<<"Constraint size(c), (n*r*log(n))"<<": "<<constraint_size;	
	incompatible_tuples = int(round(p * pow(double(domain_size),2)));	//calculate no of incompatible pairs
	cout << endl<<setw(50)<<"no of Incompatible pairs(ip), (p*d^2)"<<": "<<incompatible_tuples<<endl;
	if(!get_variables_and_domain(n,domain_size))	//get variables list and domain of each variable
	{ 	
		cout<<"\nget_variables_and_domain(): Error while finding domain for the variables"<<endl;
		return -1;
	}
	if(!get_variables_pairs(constraint_size,variables))	//get  CSP constraint pair
	{
		cout << "\nget_variables_pairs: Error while loading the constraints"<<endl;
		return -1;
	}
        if(!get_constraint(incompatible_tuples))		//get constraint of domain values for 
        {
                cout << "\nget_constraint: Error while obtaining constraints" <<endl;
                return -1;
        }
	cout<< endl <<"Please select a solving strategy from below list :";   	//allow flexibility to user to select a CSP solving method
	cout<< endl <<"1. Standard Backtracking";
	cout<< endl <<"2. Forward Checking";
	cout<< endl <<"3. Full Look Ahead";
	cout<< endl <<"Please select a number from 1 to 3 : ";
	cin >> input;
	if (input<1||input>3)							//cout error if invalid input
	{
		cout<<"\nStrategy selection Error: Please select any strategy from 1 to 3.";
		return -1;
	}
	cout<< endl <<"Check Arc-consistency before backtrack?? Enter (y/n) : ";	//allow to perform arc_consistency?
	cin >> ar;
	if (ar != 'Y' && ar != 'y' && ar != 'N' && ar != 'n')				//cout error for invalid character
	{
		cout<<"\nInvalid entery for Arc consistency. Please enter y (yes) or n (no)";
		return -1;
	}
	else
	{
		if (ar == 'Y' || ar == 'y')
		{
			if(check_arc_consistency(variables, domain_of_variables, constraint))	//call method for arc_consistency
			{
				cout<<"\nThe CSP is Arc-consistent.";
			}
			else
			{
				cout<<"\nThe CSP is not Arc-consistent. No solution exist!!!";
				return -1;
			}
		}
	}
	time_t begin, end;						//record processing time
	time(&begin);
	cout<<"\n****Finding Solution****";
	if (input == 1)
	{
		if(std_back_Tracking())					//calling standard back tracking if choice is 1
		{
			cout<<"\n*************************Solution**************************";
			map<int, int>::iterator itr;
			for (itr = var_assign.begin(); itr != var_assign.end(); ++itr)			//printing assigned domain value if solution is found
			{
				cout<<"\n    X"<<itr->first<<"  :  "<<itr->second;
			}
		}
		else
		{
			cout<<"\n*************Solution not found***************";
		}
	}
	else if(input == 2)						//calling forward checking if choice is 2
	{
		if(forward_Checking())
                {
                        cout<<"\n*************************Solution**************************";		//printing assigned domain value if solution is found
                        map<int, int>::iterator itr;
                        for (itr = var_assign.begin(); itr != var_assign.end(); ++itr)
                        {
                                cout<<"\n    X"<<itr->first<<"  :  "<<itr->second;
                        }
                }
                else
                {
                        cout<<"\n*************Solution not found***************";
                }
	}
	else
	{
		if(full_look_Ahead())					//calling full look ahead method if choice is 3
                {
                        cout<<"\n*************************Solution**************************";		//printing assigned domain value if solution is found
                        map<int, int>::iterator itr;
                        for (itr = var_assign.begin(); itr != var_assign.end(); ++itr)
                        {
                                cout<<"\n    X"<<itr->first<<"  :  "<<itr->second;
                        }
                }
                else
                {
                        cout<<"\n*************Solution not found***************";
                }
	}

	time(&end);
	time_t elapsed = end - begin;
	cout<<"\n\nTime measured : "<<elapsed<<" seconds.";				//printing total processing time take to look for a solution
	cout<<endl;
	return 0;
}

bool std_back_Tracking()
{
	if(var_assign.size() != variables.size())				//unless all the variables are assigned a domain value
	{
		map<int, int>::iterator itr;
		vector<int> unassign_vars;
		int selected_var;
		for (int i=0; i<variables.size(); i++)
		{
			itr = var_assign.find(variables[i]);
			if (itr == var_assign.end())
				unassign_vars.push_back(variables[i]);
		}
		if(!unassign_vars.empty())
		{
			selected_var = unassign_vars[0];			//select an unassigned variable
			map<int, vector<int> >::iterator it;
			it = domain_of_variables.find(selected_var);
			vector<int> domain;
			if (it != domain_of_variables.end())
				domain = it->second;				//obtain its domain values
			for (int i=0; i<domain.size(); i++)
			{
				if(is_constraint_Satified(selected_var, domain[i]))		//if related constraints are satisfied
				{
					var_assign.insert(pair<int, int>(selected_var, domain[i]));		//assign the value to the variable
					bool status = std_back_Tracking();	
					if (status)
						return true;
				}
			}
			return false;
		}
	}
	return true;
}

bool is_constraint_Satified(int sel_var, int value)
{
	bool var_pair_consistent = true;
	map<int, int>::iterator itr;
	for (itr = var_assign.begin(); itr != var_assign.end(); ++itr)
	{
		int var = itr->first;
		string test_pair = convert_to_string(var) + "|" + convert_to_string(sel_var);			//find the constraint pair for the variable
		map<string, vector<string> >::iterator it;
		it = constraint.find(test_pair);
		if(it != constraint.end())									//if there any constraint pair present
		{
			vector<string> dom_constr = it->second;
			int assigned_var = itr->second;
			string check_dom_pair = convert_to_string(assigned_var) + "," + convert_to_string(value);
			for (int i=0; i<dom_constr.size(); i++)
			{
				if (dom_constr[i] == check_dom_pair)						//check for domain constraint
					var_pair_consistent = false;
			}
		}
		test_pair = convert_to_string(sel_var) + "|" + convert_to_string(var);				//check for reverse pair
		it = constraint.find(test_pair);
                if(it != constraint.end())									//if reverse pair present
                {
                        vector<string> dom_constr = it->second;
                        int assigned_var = itr->second;
			string check_dom_pair = convert_to_string(value) + "," + convert_to_string(assigned_var);
                        for (int i=0; i<dom_constr.size(); i++)
                        {
                                if (dom_constr[i] == check_dom_pair)						//if the domain pair is present for CSP
                                        var_pair_consistent = false;
                        }
                }
	}
	return var_pair_consistent;
}

bool forward_Checking()
{
        if(var_assign.size() != variables.size())			////unless all the variables are assigned a domain value
        {
                map<int, int>::iterator itr;
                vector<int> unassign_vars;
                int selected_var;
                for (int i=0; i<variables.size(); i++)
                {
                        itr = var_assign.find(variables[i]);
                        if (itr == var_assign.end())
                                unassign_vars.push_back(variables[i]);
                }
                if(!unassign_vars.empty())
                {
                        selected_var = unassign_vars[0];		//select an unassigned variable
                        map<int, vector<int> >::iterator it;
                        it = domain_of_variables.find(selected_var);
                        vector<int> domain;
                        if (it != domain_of_variables.end())
                                domain = it->second;			//obtain its domain values
                        for (int i=0; i<domain.size(); i++)
                        {
                                if(is_constraint_Satified(selected_var, domain[i]))		//if related constraints are satisfied
                                {
                                        var_assign.insert(pair<int, int>(selected_var, domain[i]));		//assign the value to the variable
                                        if(check_arc_consistency(variables, domain_of_variables, constraint, true))  //check for arc_consistency for revert
					{	
						bool status = forward_Checking();
                                        	if (status)
                                                	return true;
					}
                                }
                        }
                        return false;
                }
        }
        return true;
}

bool full_look_Ahead()
{
        if(var_assign.size() != variables.size())			//unless all the variables are assigned a domain value
        {
                map<int, int>::iterator itr;
                vector<int> unassign_vars;
                int selected_var;
                for (int i=0; i<variables.size(); i++)
                {
                        itr = var_assign.find(variables[i]);
                        if (itr == var_assign.end())
                                unassign_vars.push_back(variables[i]);
                }
                if(!unassign_vars.empty())
                {
                        selected_var = unassign_vars[0];		//select an unassigned variable
                        map<int, vector<int> >::iterator it;
                        it = domain_of_variables.find(selected_var);
                        vector<int> domain;				//obtain its domain values
                        if (it != domain_of_variables.end())
                                domain = it->second;
                        for (int i=0; i<domain.size(); i++)
                        {
                                if(is_constraint_Satified(selected_var, domain[i]))	//if related constraints are satisfied
                                {
                                        var_assign.insert(pair<int, int>(selected_var, domain[i]));		//assign the value to the variable
                                        if(check_subconstr(selected_var, domain[i]))
                                        {
                                                bool status = forward_Checking();
                                                if (status)
                                                        return true;
                                        }
                                }
                        }
                        return false;
                }
        }
        return true;
}

bool check_subconstr(int sel_var, int value)		//check for the variables constraints
{
	map<string, vector<string> >::iterator itr;
	vector<int> unassign_var;
	map<string, vector<string> > sub_constr;
        for (itr = constraint.begin(); itr != constraint.end(); ++itr)			//loop throught the actual set of constraints
	{
		string current_arc = itr->first;
		int a = convert_to_int(current_arc.substr(0, current_arc.find("|")));
		int b = convert_to_int(current_arc.substr(current_arc.find("|")+1));
		if ( a == sel_var || b == sel_var)					//obtain related constraint pair
		{
			int l;
			if (a == sel_var)
				l = a;
			else
				l = b;
			map<int,int>::iterator it;
			it = var_assign.find(l);					//look if not assigned
			if (it == var_assign.end())
			{
				unassign_var.push_back(l);				//create a liste of unassigned variable
				sub_constr.insert(pair<string, vector<string> >(current_arc,itr->second));		//load related domain constraint
			}
		}
	}
	return check_arc_consistency(unassign_var, domain_of_variables, sub_constr, true);	//check arc consistency for the unassigned list of variables
}

bool getInputs(int &n, float &p, float &a, float &r)			//input the program parameter
{
	cout<<setw(50)<<left<<"Enter number of variables"<<": ";
	cin>>n;
	cout<<endl<<setw(50)<<left<<"Enter the value for tightness"<<": ";
	cin>>p;
	cout<<endl<<setw(50)<<left<<"Enter the value for alpha constant"<<": ";
	cin>>a;
	cout<<endl<<setw(50)<<left<<"Enter the value for r constant"<<": ";
	cin>>r;
	if((a <= 0 || a >= 1) || (p <= 0 || p >= 1) || (r <= 0 || r >= 1))
		return false;

	return true;
}

bool get_variables_and_domain(int n, int domain_size)
{
	for (int i=0; i<n; i++)
	{
		variables.push_back(i);				//load variables based on value for 'n', 0,1,...,n-1
	}
	for (int i=0; i<variables.size(); i++)
	{
		vector<int> domain_variables;
		for (int j=0; j<domain_size; j++)
		{
			domain_variables.push_back(j);		//load domain values for each variable, 0,1,...,d-1
		}
		int var = variables[i];
		domain_of_variables.insert(pair<int, vector<int> >(var,domain_variables));	//add variable and domain to map one by one
	}
	if (variables.empty() || domain_of_variables.empty())
	{
		return false;
	}
	cout <<"\n"<<left<<"Variables    :    "<<"{";			//print the list of variables
	for (int i = 0; i< variables.size(); i++)
		if (i == variables.size()-1)
			cout<<"X"<<variables[i]<<"}";
		else
			cout<<"X"<<variables[i]<<", ";
	cout<<"\n"<<setw(20)<<left<<"Domain of the variable    :"<<endl;
	map<int, vector<int> >::iterator itr;
        for (itr = domain_of_variables.begin(); itr != domain_of_variables.end(); ++itr)
        {
		vector<int> domain_variables = itr->second;
		cout<<"   " << "X" << itr->first << " : {";
		for (int i=0; i<domain_variables.size(); i++)
			if ( i == domain_variables.size()-1)
				cout << " " << domain_variables[i]<<"}";				//print the list of domain for each variable
			else
				cout << " " << domain_variables[i]<<", ";
		cout<<endl;
        }

	return true;
}

bool get_variables_pairs(int constraint_size, vector<int> vars)
{
	int no_of_vars= vars.size();
	for (int i=1; i<=constraint_size; i++)
	{
		int RandIndex1 = rand() % no_of_vars;					//randomly select the index of variable1
		int RandIndex2 = rand() % no_of_vars;					//randomly select the index of variable2
		if (vars[RandIndex1] == vars[RandIndex2])				//if both variables are same
		{
			i--;
			continue;
		}
		string pair = convert_to_string(vars[RandIndex1]) + "|" + convert_to_string(vars[RandIndex2]);		//otherwise create the CSP pair
		string revpair = convert_to_string(vars[RandIndex2]) + "|" + convert_to_string(vars[RandIndex1]);
		bool found = false;
		for (int j = 0; j<constraints_vars.size(); j++)
		{
			if (constraints_vars[j] == pair || constraints_vars[j] == revpair) 	//if pair or rev pair already not present in the list
			{
				found = true;	
				i--;
			}
		}
		if (found == false)
		{
			constraints_vars.push_back(pair);			//add it to the list of not present
		}
	}
	if (constraints_vars.empty())
		return false;
	/*cout<<"\n"<<"Constraint avariable pairs :"<<endl;			//print the constraint pair
	for (int i=0; i<constraints_vars.size(); i++)
                cout << " " << constraints_vars[i];*/
	return true;
}

string convert_to_string(int i)
{
	string str;
	stringstream ss;
	ss << i;
	ss >> str;
	return str;
}

bool get_constraint(int incompatible_pairs)
{
	for (int i=0; i<constraints_vars.size(); i++)			//loop through the constraint pair
	{
		string var_pair = constraints_vars[i];
		string var1 = var_pair.substr(0,var_pair.find("|"));
		string var2 = var_pair.substr(var_pair.find("|")+1);
		map<int, vector<int> >::iterator itr;
		itr = domain_of_variables.find(convert_to_int(var1));
		vector<int> var1_domain;
		if (itr != domain_of_variables.end())
		{
			var1_domain = itr->second;			//find the domain for variable1
		}
		vector<int> var2_domain;
		itr = domain_of_variables.find(convert_to_int(var2));
                if (itr != domain_of_variables.end())
		{
			var2_domain = itr->second;			//find the domain for variable2
		}
		int var1_domain_size = var1_domain.size();
		int var2_domain_size = var2_domain.size();
		vector <string> incompatible_pair;
		for (int j = 1; j<=incompatible_pairs; j++)
		{
			int RandIndex1 = rand() % var1_domain_size;		//randomly select the domain for forming constaint over domain
			int RandIndex2 = rand() % var2_domain_size;		//randomly select domain for incompatible pairs
			string inc_pair = convert_to_string(var1_domain[RandIndex1]) + "," + convert_to_string(var2_domain[RandIndex2]);
                	string inc_revpair = convert_to_string(var2_domain[RandIndex2]) + "," + convert_to_string(var1_domain[RandIndex1]);
			bool found_inc_pair = false, found_inc_revpair = false;
			for (int k = 0; k<incompatible_pair.size(); k++)		//loop until number of incompatible pairs is found
			{
				if (incompatible_pair[k] == inc_pair)			//if already present
					found_inc_pair = true;
				if (incompatible_pair[k] == inc_revpair)		//if reverse pair is already present
					found_inc_revpair = true;
			}
			if (found_inc_pair ==  false)
			{
				incompatible_pair.push_back(inc_pair);			//if not present, add it to the list of incompatible pair
			}
			else if(found_inc_revpair == false)
			{
				incompatible_pair.push_back(inc_revpair);
			}
			else
			{	j--; }
		}
		if (incompatible_pair.empty())						//if list of incompatible pair is not empty 
			return false;
		else
			constraint.insert(pair<string, vector<string> >(constraints_vars[i],incompatible_pair));	//add it to the constraint
	}
	if (constraint.empty())
	{
		return false;
	}
	cout << "\n" <<setw(20)<<left<<"Constraints :"<<left<<"Incompatible pairs"<<endl;		//print the constraint and incompatible pair
	map<string, vector<string> >::iterator itr;
        for (itr = constraint.begin(); itr != constraint.end(); ++itr)
        {
		string constr = itr->first;
		string var1 = constr.substr(0, constr.find("|"));
		string var2 = constr.substr(constr.find("|")+1);
                vector<string> domain_constraint = itr->second;
                cout<<"   "<<"(X"<<var1<<", X"<<var2<<")   :   [";
                for (int i=0; i<domain_constraint.size(); i++)
			if (i==domain_constraint.size()-1)
				cout <<"("<< domain_constraint[i]<<")]";
			else
                        	cout <<"("<< domain_constraint[i]<<"), ";
                cout<<endl;
        }
	return true;
}

int convert_to_int(string ss)
{
	stringstream str(ss);
	int i = 0;
	str >> i;
	return i;
}

bool check_arc_consistency(vector<int> variables, map<int, vector<int> > domain_of_variables, map<string, vector<string> > constraint, bool revert)
{
	vector<string> arc;
	if(!constraint.empty())
	{
		map<string, vector<string> >::iterator itr;
		for (itr = constraint.begin(); itr != constraint.end(); ++itr)
		{
			string constr = itr->first;
			arc.push_back(constr);
		}
	}
	if(arc.size())
	{
		vector<string>item;
		item.push_back(arc[0]);
		while (item.size())					//loop through  the list of arcs
		{
			string current_arc = item.back();
			item.pop_back();
			int a,b,X1,X2;
			if (revert)
			{
				a = convert_to_int(current_arc.substr(0,current_arc.find("|")));//create reverese pair incase of forward checking
                		b = convert_to_int(current_arc.substr(current_arc.find("|")+1));
				current_arc = convert_to_string(b) + "|" + convert_to_string(a);
			}
			if(domain_revision(current_arc,revert))			//domain revision for the constraint pair
			{
				X1 = convert_to_int(current_arc.substr(0,current_arc.find("|")));//identify variables from the pair
                                X2 = convert_to_int(current_arc.substr(current_arc.find("|")+1));
				map<int, vector<int> >::iterator itr;
				itr = domain_of_variables.find(X1); 
				if(itr != domain_of_variables.end())
				{
					vector<int> dom = itr->second;			//select domain of first variable
					if(dom.empty())
						return false;
				}
				vector<int> neighbours_X1 = get_neighbours(arc, X1, X2);	//find neighbours of the first variable in constraint
				for(int i = 0; i<neighbours_X1.size(); i++)		//if neighbours found, look through its arc
				{
					for (int i=0; i<arc.size(); i++)
					{
						string arc_pair = arc[i];
						int a = convert_to_int(arc_pair.substr(0,arc_pair.find("|")));
						int b = convert_to_int(arc_pair.substr(arc_pair.find("|")+1));
						if (neighbours_X1[i] == a || neighbours_X1[i] == b)
							item.push_back(arc_pair);
					}
				}
			}
		}
	}
	return true;
}

vector<int> get_neighbours(vector<string> arc, int current_node, int neigbour_to_ignore)
{
	vector<int> neighbours;
	for (int i=0; i<arc.size(); i++)
	{
		string current_arc = arc.back();
		arc.pop_back();
		int a = convert_to_int(current_arc.substr(0,current_arc.find("|")));
                int b = convert_to_int(current_arc.substr(current_arc.find("|")+1));
		if ( a == current_node || b == current_node)		//check if one of the variable is one getting assigned the value
		{
			vector<int>::iterator it_a = find(neighbours.begin(), neighbours.end(), a);	//if possible neighbour already present in list
			vector<int>::iterator it_b = find(neighbours.begin(), neighbours.end(), b);
			if(a != current_node && a != neigbour_to_ignore && it_a !=neighbours.end())	//if not, add it to the list
				neighbours.push_back(a);
			else if (b!= current_node && b != neigbour_to_ignore && it_b !=neighbours.end())
                                neighbours.push_back(b);
		}
	}
	return neighbours;
}

bool domain_revision(string current_arc, bool revert)
{
	bool domain_revised = false;			//variable to keep track if domain has been revised
	map<string, vector<string> >::iterator itr;
	itr = constraint.find(current_arc);
	vector<string> constraint_to_be_checked;
	if (itr != constraint.end())
	{
		constraint_to_be_checked=itr->second;		//load contraint to be checked
	}
	if (revert)
	{
		constraint_to_be_checked = get_constr_for_revArc(current_arc);		//load constraint for reverse arc in case of forward checking
	}
	int a = convert_to_int(current_arc.substr(0,current_arc.find("|")));
        int b = convert_to_int(current_arc.substr(current_arc.find("|")+1));
	map<int, vector<int> >::iterator it1;
	map<int, vector<int> >::iterator it2;
	it1 = domain_of_variables.find(a);
	it2 = domain_of_variables.find(b);
	if (it1 == domain_of_variables.end() || it2 == domain_of_variables.end())	//obtain the domain of both the incolved variables
	{
		return false;
	}
	vector<int> a_domain = it1->second;
	vector<int> b_domain = it2->second;
	for(int i=0; i<a_domain.size(); i++)
	{
		bool not_compatible = false;
		for (int j=0; j<b_domain.size(); j++)
		{
			string domain = convert_to_string(a_domain[i]) + "," + convert_to_string(b_domain[j]);
			for(int k=0; k<constraint_to_be_checked.size(); k++)
			{
				if (constraint_to_be_checked[k] == domain)		//if constraint list contains the pairs
				{
					not_compatible = true;
					continue;
				}
			}
		}
		if(not_compatible)
		{
			a_domain.erase(find(a_domain.begin(),a_domain.end(),a_domain[i]));		//if not compatible, remove the domain from list
			it1->second = a_domain;
			domain_revised = true;
		}
	}
	return domain_revised;
}

vector<string> get_constr_for_revArc(string current_arc)			//this method obtains the constraints for reverse pair
{
	int a = convert_to_int(current_arc.substr(0,current_arc.find("|")));
        int b = convert_to_int(current_arc.substr(current_arc.find("|")+1));
	string rev_arc = convert_to_string(b) + "|" + convert_to_string(a);
	map<string, vector<string> >::iterator itr;
	itr = constraint.find(rev_arc);
	vector <string> rev_constraint;
	if (itr != constraint.end())						//if reverse pair exist in the list of constraint
	{
		vector<string> constraint_to_be_checked = itr->second;
		for (int i=0; i<constraint_to_be_checked.size(); i++)
		{
			string constr = constraint_to_be_checked[i];
			string c = constr.substr(0,constr.find(","));
        		string d = constr.substr(constr.find(",")+1);
			constr = d+","+c;
			rev_constraint.push_back(constr);			//load it to the reverse pair constraint list
		}
	}
	return rev_constraint;
}


