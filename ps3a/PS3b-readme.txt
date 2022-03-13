/**********************************************************************
 *  N-Body Simulation ps3b-readme.txt template
 **********************************************************************/

Name:Greg Kaplowitz
Hours to complete assignment:8

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
this assinment is a phyisics soimulation that can incorperate the universe in terms f gravity and superpossition. I acomplished a template for that affect and incorperated in close half of our solarsystem

  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
The new physics updait function that calculates the physics for the simulation.




/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Describe if and how do you used the smart pointers 
 *  Include code excerpts.
 **********************************************************************/
The universe is a vector of smart pointers that hold all the bodies of the universe to be itterated through 
for all the physics and drawing of the universe to the window.  every loop we run the updait that recalulates the forces and superpossiitoning of the bodies and redraws the universe.


/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
I wasn't clearing and redrawing it in my delta t for loop so I was stuck with the view of the static universe for a while and couldnt figure out why none of my physics were showing on screen

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
did music extra credit
