 //Name: Organization.cpp
//Project: CMSC 202 Project 2, Fall 2021
//Author:  Jeremy Dixon
//Date:    9/29/2021
//Desc: This file contains the header details for an Organization class.

#include "Organization.h" //Must be implemented before Organization
using namespace std;

  // Name: Organization
  // Desc - Default constructor for Organization
  // Preconditions - None
  // Postconditions - Organization is created (empty) with 0 people in the roster
Organization:: Organization(){

    m_name = "";
    m_fileName = "";
    m_numRoster = 0;
    

  }
  // Name: SetName
  // Desc - Sets m_name by asking user for name
  // Preconditions - m_name exists
  // Postconditions - Asks user for the organization name and populates m_name
void Organization::SetName(){

  //Setter for name
  
    string name;
    
    cout << "What is the name of your organization?" << endl;
    cin >> name;

    m_name = name;

    
  }
  // Name: LoadRoster
  // Desc - Sets m_fileName by asking user. Then populates all of the people loaded from file
  // Preconditions - m_fileName exists. m_roster empty
  // Postconditions - Asks user for m_fileName. Loads data from file and populates m_roster
void Organization::LoadRoster(){

  int iAge, iID, idx = 0, peopleCnt = 0;
  string fName, lName, age, id, file;
  ifstream inputFile;
  bool ask = true;


  do{
    
  cout << "What's the name of the file you would like to load?" << endl;
  cin >> file;
    

    inputFile.open(file);
      
    if (inputFile.is_open())
      {

	while(inputFile.is_open())
	  {

	    if(idx < MAX_PEOPLE)
	      {
		getline(inputFile, fName, ',');
	 	getline(inputFile, lName, ',');
		getline(inputFile, age, ',');
		getline(inputFile, id, '\n');	    

		iAge = stoi(age);
		iID = stoi(id);

       		m_roster[idx].SetDetails(fName, lName, iAge, iID);
	       	peopleCnt++;

	      }else{

	      inputFile.close();

	    }
	    
	idx++;
	    

	  }

	cout << peopleCnt << " people loaded into the roster." << endl;

	ask = false;
	
      }else{

      cout << "Error: File is not open, please check your input file name." << endl;

      ask = true;
    }
  }while(ask);

}
  // Name: DisplayRoster
  // Desc - Displays a numbered list of everyone in the roster (starts at 1)
  // Preconditions - m_roster is populated
  // Postconditions - Displays a numbered list of people
void Organization::DisplayRoster(){
  
    cout << "\n***** " << m_name << " *****\n" << endl;
    
    for(int i = 0; i < MAX_PEOPLE; i++)
      {
	
	cout << i+1 << " ";

	m_roster[i].DisplayDetails();

      }



  }
  // Name: GetPerson
  // Desc - Displays a list of people in m_roster and user enters number of desired person.
  //        Returns pointer of that person in m_roster
  // Preconditions - m_roster is populated
  // Postconditions - Returns pointer for the person chosen from list
Person* Organization::GetPerson(){

  // Getter for person
  int choice;

  do{
    cout << "\nWho would you like to be friends with?" << endl;
    cin >> choice;

  }while(choice > 40  || choice < 1);
  

  return &m_roster[choice - 1]; 

    
}

