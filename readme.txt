/**********************************************************************
 *  N-Body Simulation ps3a-readme.txt template
 **********************************************************************/

Name:Mandar Kapadia
Hours to complete assignment: 10 hours

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
In this assignment we are taking User inputted files that have diffrent distances and diffrent location you have to find the distance 
in the window in ratio to real life and get it to go there.implementing a universe class which hold objects objects of Celetial bodies 
which hold all the information of the Celetial Body like postion velocity sprite and texture.The universe class would read from the file and would also 
create a draw function that would make it easy to print in the main. 
The 

  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
    In this project I used a vector of pointers to Celetial bodies so I could edit and run it. I also had used an algorithm to convert
    the postions to print in the window so that it fits the x,y and is int the space.  




/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Describe if and how do you used the smart pointers 
 *  Include code excerpts.
 **********************************************************************/
I used smart pointers to code and make my vector. I used shared pointers because the pointer is going to be shared with multiple 
data structures and will be going around. I created it by using "std::vector<std::shared_ptr<CelestialBody>> pCB;" this will creating 
a shared pointer of CelestialBody called pCB.



/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
I got help from erik and ravi. They helped me debug my insertion and my formala. my insertion was wrong because it was reading a int instead 
of a double and my formala was insecrt and was not postion at 0 which they helped me debug. 

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
I did have a problem where my insertion did not work but I did changed the implemented so i would work.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
 I also did the extra credit and made a background