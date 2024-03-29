// I created this because I needed a password generator at work since I work as a It technician
// and I did not want to use third party applications since the one I was using got taken down thats 
// when I realized that I could create my own generator with C++.

#include <iostream>
#include <fstream> 
#include <cstdlib>

// Password library with symbols
const char wSymbol[] = "0123456789!@#$%^&*-+=[{[}<>/,.?-abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// This returns the length of the out library 
int SIZE1 = sizeof(wSymbol)-1;

// Password library without symbol 
const char woSymbol[] = "0123456789AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz0123456789";
// This returns the length of the second library 
int SIZE2 = sizeof(woSymbol)-1;

int main(){
    srand(time(0));
    std::ofstream outFS;
    outFS.open("newGenPassword.txt");

    // This checks if the text file can open
    if (!outFS.is_open()){
        std::cout << "Could not open file newGenPassword.txt exiting." << std::endl;
        return 1;
    }//end if 

    // Holds the answer to whether or not the user wants symbols in their password
    char a;
    // Starting Program
    std::cout << "SECURE PASSWORD GENERATOR" << std::endl;
    std::cout << "Include symbols [y/n]: ";
    std::cin  >> a;

    // if the user picks yes to having symbols it will run through this if statement
    if (a == 'y'){
        int num;
        std::cout << "Enter the desired length of new password: ";
        std::cin  >> num;
      
        // I added this as a precaution because creating too long of a password will 
        // cause a computer to stop working properly
        if (num > 256){
          std::cout << "Error: Maximum numbers is 256. Try again." << std::endl;
          return 1;
        }//end if 

        // Incase user inputs a negative number
        else if (num <= 0){
          std::cout << "Error: Password length has to be greater than 0. Try again." << std::endl;
          return 1;
        }//end else if 

        //output for password with symbols included
        outFS << "Newly Generated Password: " << std::endl;
        for(int i = 0; i < num; i++){
            outFS << wSymbol[rand() % SIZE1];
        }
    }// end if
      
    // If the user picks no to having symbols it will run through this else if 
    else if (a == 'n'){
        int num;
        std::cout << "Enter desired length of new password: ";
        std::cin  >> num;
        // I added this as a precaution because creating too long of a password will 
        // cause a computer to stop working properly
        if (num > 256){
          std::cout << "Error: Maximum numbers is 256. Try again." << std::endl;
          return 1;
        }//end if 

        // Incase user inputs a negative number
        else if (num <= 0){
          std::cout << "Error: Password length has to be greater than 0. Try again." << std::endl;
          return 1;
        }//end else if 

      //output for password without symbols
        outFS << "Newly Generated Password: " << std::endl;
        for (int i = 0; i < num; i++){
            outFS << woSymbol[rand() % SIZE2]; 
        }
    }// end else if
    else {
        std::cout << "Wrong input. Try again." << std::endl;
        return 1;
    }
    outFS.close();
    std::cout << system("open newGenPassword.txt") << std::endl;
    return 0;
}
