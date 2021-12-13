//Name: FriendFinder.cpp
//Project: CMSC 202 Project 2, Fall 2021
//Author:  Kirtan Thakkar
//Date:    10/12/2021
//Desc: This file contains the function definations for FriendFinder class.

#include "FriendFinder.h" //Must be implemented before FriendFinder

using namespace std;

  // Name: FriendFinder
  // Desc - Default constructor for application for finding friends
  // Preconditions - Creates a Person and an organization
  // Postconditions - Welcomes user and calls Start()
FriendFinder::FriendFinder(){


  cout << "*****************************" << endl;
  cout << "Welcome to UMBC Friend Finder" << endl;
  cout << "*****************************\n" << endl;

  Start();
}
  // Name: GetDetails
  // Desc - Asks user for their first name, last name, age, and ID to populate m_me
  // Preconditions - None
  // Postconditions - Populates information related to m_me
void FriendFinder::GetDetails(){

  // Takes the details from the user, and sets up a profile
  
  int age, id;
  string fname, lname;


  cout << "\nWhat is your first name?" << endl;
  cin >> fname;

  cout << "What is your last name?" << endl;
  cin >> lname;

  cout << "what is your age?" << endl;
  cin >> age;

  cout << "What is your ID?" << endl;
  cin >> id;

  m_me.SetDetails(fname, lname, age, id);
  
  m_organization.SetName();
  

 

}
  // Name: DisplayMenu
  // Desc - Displays main menu for application
  // Preconditions - None
  // Postconditions - Called from Start updates integer passed
void FriendFinder::DisplayMenu(int &choice){


  Person* theChosenOne;
  
  switch(choice)
    {

    case 1: // Displays Roster

      cout << "You are: ";
      m_me.DisplayDetails();
      cout << endl;
      m_organization.DisplayRoster();
    
    break;
    case 2:// Displays friends list
    
    m_me.DisplayFriends();
      
  
    break;
    case 3:// Searches for a friend

    m_organization.DisplayRoster();
    theChosenOne = m_organization.GetPerson();
    
    m_me.AddFriend(theChosenOne);
    
    break;
    case 4://Removes a friend

    m_me.DisplayFriends();
    m_me.RemoveFriend();
    
    break;

    default:
      
      cout << "Wrong number!" << endl;
     
    }
      
      


}
  // Name: Start
  // Desc - Main function running FriendFinder
  //        Calls GetDetails
  //        Populates data for organization
  //        Continually calls DisplayMenu until someone enters 4 (exit)
  // Preconditions - m_me and m_organization are created but not populated
  // Postconditions - Runs until user enters 4. Thanks user for usage. Ends application
void FriendFinder::Start(){

  int input = 0;
  bool run = true;

  GetDetails();
  m_organization.LoadRoster();
  
  cout << endl;
  
  do{
    
  cout << "\nWhat would you like to do?" << endl;
  cout << "1. Display Entire Orgnization" << endl;
  cout << "2. Display Friend List" << endl;
  cout << "3. Search for a Friend" << endl;
  cout << "4. Remove Friend " << endl;
  cout << "5. Exit" << endl;
    
  cin >> input;

  if(input < 5 && input > 0)
    {
      DisplayMenu(input);
      
    }else if (input == 5)
    {
      run = false;
      cout << "Thank you for using UMBC Friend Finder!" << endl;
    }

 
  }while(run);

}
