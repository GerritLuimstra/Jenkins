//game statueses
//will be set to true as soon as the game finished
boolean maze = false;
boolean race = false;
boolean balloon = false;
boolean sumo = false;

void theMaze(){
	if(!leftInfraRed() && !rightInfraRed()){

        forwardSpeed(80);
        delay(10);

    } else if(!leftInfraRed() && rightInfraRed()){
        
        right();
        delay(10);

    } else if(leftInfraRed() && !rightInfraRed()){

        left(); 
        delay(10); 
    
	} else if(leftInfraRed() && rightInfraRed()){
       
		if(object_detected(15)){

			halt();
			maze = true;

		} else{

			left();
			delay(300); 

       } 
    }
}

void ratRace(){
	boolean finished = false;
	straight();
	delay(500);
	while(!finished)
	{
		if(!rightInfraRed() && !leftInfraRed())
		{
		  straight();
		}
		else if(rightInfraRed() && !leftInfraRed())
		{
		  left();
		}
		else if(!rightInfraRed() && leftInfraRed())
		{
		  right();
		}
		else if(rightInfraRed() && leftInfraRed())
		{
		  halt();
		  finished = true;
		  race = true;
		}
	  }
}