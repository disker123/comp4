/**********************************************************************
 *  N-Body Simulation ps3a-readme.txt template
 **********************************************************************/

Name:Greg Kaplowitz
Hours to complete assignment:12 hours

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
create a a class to hold a vector of unique pointers of celestial bodies that holds the data of a sprite that is placed in the universe.  The celestial bodies are filled by overloafding the incertion operatior and piping the data in from a file that first passes the number of bodies in the universe and the radius of the universe which are sued to calculate the possition of the bodies.

  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/

the universe is implemented as a vector of unique pointers that hold all the bodies of the universe in it to be drawn to the window when they are all created and ready to be drawn



/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Describe if and how do you used the smart pointers 
 *  Include code excerpts.
 **********************************************************************/
The window is created of an arbitrary size, we use 500x500 here becuase that it the size of the given universe texture.
then we pipe in the body count and universe radius.
after that we run the loop to create and fill the pointers of the body objects 
for(int i=0; i<planet_count; i++){
		std::unique_ptr<bodies> body(new bodies);
		cin >> *body;
		body->createBody(radius, size);
		system.addBody(move(body));
	}
This creates the body fills the member variables and sets the position and texture so that it is ready to be added to the universe vector
Then the universe itterates through the vector drawing each celestial body


/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
got help with the unique pointers

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
I was running my for loop in the open window loop at one point

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
did the universe background extra credit
