#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <cmath>
#include <random>
#include <chrono>
#include <ctime>
#include <cstdlib>


typedef std::size_t HASH_INDEX_T;

struct MyStringHash {
    HASH_INDEX_T rValues[5] { 983132572, 1468777056, 552714139, 984953261, 261934300 };
    MyStringHash(bool debug = true)
    {
        if(false == debug){
            generateRValues();
        }
    }
    
    // hash function entry point (i.e. this is h(k))
    HASH_INDEX_T operator()(const std::string& k) const //could take in a string of '28' chars
    {
        // Add your code here

        // 
        long long w[5] = {0}; //initializing all w[i] arrays

        unsigned long long powerbase[6] = {1, 36, 1296, 46656, 1679616, 60466176};
        
        int w_index = 4;
        int exponent = 0;
        int charcount = 0; 
   

           for (int i = k.size() - 1; i >= 0; i--) { //reverse iteration
           //index to make sure i hit size of k (6)
           //resetting counter

              if(charcount < 6){ //strlen less than 7
                char c = k[i]; //obtain character from string
                HASH_INDEX_T digit = letterDigitToNumber(c); //passing in character to converter
                w[w_index] += (digit * powerbase[exponent]); 
                //powerindex++; //increment powerindex + charcount
                exponent++; 
                charcount++; 

              }

              else if(charcount >= 6){
                w_index--; //once we hit charcount, decrement index of w
                exponent = 0; //reset charcount + exponent
                charcount = 0;  
                i++; 
              } 
              
          }

      //hashing string:


        long long hashval = (rValues[0]*w[0]) + (rValues[1]*w[1]) + (rValues[2]*w[2]) + (rValues[3]*w[3]) + (rValues[4]*w[4]);  
          
          
      //     std::cout << rValues[0] << std::endl;
      //     std::cout << w[0] << std::endl; 
      //     std::cout << rValues[1] << std::endl;
      //   std::cout << w[1] << std::endl; 
      //   std::cout << rValues[2] << std::endl;
      //     std::cout << w[2] << std::endl; 
      //     std::cout << rValues[3] << std::endl;
      // std::cout << w[3] << std::endl; 
      // std::cout << rValues[4] << std::endl;
      // std::cout << w[4] << std::endl; 
 
      
      std::cout << w[0] << std:: endl; 
      std::cout << w[1] << std:: endl; 
      std::cout << w[2]<< std:: endl; 
      std::cout << w[3] << std:: endl; 
      std::cout << w[4] << std::endl;

      // std::cout << hashval << std::endl;
      return hashval;  

    }
          


        
    



    

    // A likely helper function is to convert a-z,0-9 to an integral value 0-35
    HASH_INDEX_T letterDigitToNumber(char letter) const
    {
        //for loop for the letters
        // for loop for the integers?
        std::size_t index = 0; //return type

        if((int)letter <= 122 && (int)letter >= 97){ //ascii val from 'a' to 'z'
              index = static_cast<std::size_t>(letter - 97); //convertionm made of type size t
              return index; 
            }
        if((int)letter <= 90 && (int)letter >= 65){ //ascii val from 'A' to 'Z'
            index = static_cast<std::size_t>(letter - 65);
            return index; 
        }
        if((int)letter <= 57 && (int)letter >= 48){ //ascii val from '0' to '9'
            index = static_cast<std::size_t>(letter - 22);
            return index; 
        }
        // Add code here or delete this helper function if you do not want it

    }



    // Code to generate the random R values
    void generateRValues()
    {
        // obtain a seed from the system clock:
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 generator (seed);  // mt19937 is a standard random number generator

        // Simply call generator() [it has an operator()] to get another random number
        for(int i{ 0 }; i < 5; ++i)
        {
            rValues[i] = generator();
        }
    }
};

#endif
