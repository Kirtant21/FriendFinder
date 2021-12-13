//Name: Person.cpp
//Project: CMSC 202 Project 2, Fall 2021
//Author:  Jeremy Dixon
//Date:    9/22/21
//Desc: This file contains the function defination for Person class.

#include "Person.h"
using namespace std;

  // Name: Person
  // Desc - Default Constructor for a Person
  // Preconditions - Creates a Person with no data associated with it
  // Postconditions - a Person is created
Person:: Person(){
    
    m_fName = "..";
    m_lName = "..";
    m_age = 0;
    m_ID = 0;
    m_friendCount = 0;
    

}
  // Name: Person
  // Desc - Overloaded Constructor for a Person
  // Preconditions - Creates a Person with passed data
  // Postconditions - a Person is created
Person:: Person(string fname, string lname, int age, int id){

    m_fName = fname;
    m_lName = lname;
    m_age = age;
    m_ID = id;
    m_friendCount = 0;

}
  
  // Name: AddFriend
  // Desc - A person pointer is stored from the roster of people in an organization
  // Preconditions - A person pointer is passed
  // Postconditions - A person pointer is added to this person's m_friend's array
  //                  if not at maximum and not already in the array
void Person::AddFriend(Person* person){

  // Adds a friend and increments the m_friendCount by 1
  
    if(CheckID(person->m_ID))
      {
	cout << "\nYou are already friends with " << person->m_fName << endl;
      }else{
    
	m_friends[m_friendCount] = person;
	m_friendCount++;

	cout << "\nYou are now friends with " << person->m_fName << "!" << endl;

    }

}
  
  // Name: RemoveFriend
  // Desc - Removes a person pointer from this person's m_friend array
  // Preconditions - Person pointer exists in m_friend
  // Postconditions - Person is removed from m_friend and all pointers are moved towards front
void  Person::RemoveFriend(){

  // Checks and see if there is any friend in the list if so asks user which friend they'd like to remove
  
  int input;

 
  if(m_friendCount > 0)
    {
  
    do{
      
      cout << "\nWho would you like to remove?" << endl;
      cin >> input;

    }while((input > MAX_FRIENDS || input < 1) || input > m_friendCount);

    for(int i = 0; i < m_friendCount; i++)
      {
	if(i >= input-1)
	  {
	    m_friends[i] = m_friends[i+1];
	  }
	
      }
    
    m_friendCount--;

    }

}

  // Name: CheckID
  // Desc - Checks to see if a specific person ID exists in m_friends - Note: IDs will always be unique in proj2
  // Preconditions - m_friends is populated
  // Postconditions - Returns true if id exists in m_friends else false
bool Person::CheckID(int id){

  // Checks the ID passed as arg   

    for(int i = 0; i < m_friendCount; i++)
      {
	if(m_friends[i]->m_ID == id)
	  {
	    return true;	    
	  }
	
      }
    
    return false;
    
}

  // Name: DisplayFriends
  // Desc - Displays information about each friend in the m_friend array
  // Preconditions - People are in the m_friend array
  // Postconditions - Displays information about person object in array
void Person::DisplayFriends(){

  // checks and see if there is any friend to display, if so displays the friend list

  
  if(m_friendCount > 0)
    {
      cout << "Friend list for " << m_fName << endl;
      cout << endl;
      
      for(int i = 0; i < m_friendCount; i++)
	{
	   cout << i+1 << ". ";
	   m_friends[i]->DisplayDetails();
	
        }


    }else{

    cout << "\nYou don't have any friends yet!" << endl;
  }

}
  // Name: DisplayDetails
  // Desc - Displays information about this person
  // Preconditions - Person data is populated
  // Postconditions - Displays information about person object
void Person::DisplayDetails(){

 cout << m_fName << " " << m_lName << " (" << m_age << ") " << m_ID << endl;

}
  // Name: SetDetails
   // Desc - Used as a setter for first name, last name, age, and id
  // Preconditions - Person already created
  // Postconditions - Member variables populated
void Person::SetDetails(string fName, string lName, int age, int id){

  //Setter for Details

    m_fName = fName;
    m_lName = lName;
    m_age = age;
    m_ID = id;

}
