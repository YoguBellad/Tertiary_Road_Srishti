
 
 import processing.serial.*;
 Serial port;
 String IP="localhost";
 String xyz="2";
 
 void setup()  {
 
   /* This part must be altered to fit your local settings. The number in brackets after "Serial.list()" is where you declare what COM port your Arduino is connected to.
      If you get error messages, try a different number starting from 0 (e.g. 0, 1, 2, 3...) . */
    port = new Serial(this, Serial.list()[1], 9600);  // Open the port that the Arduino board is connected to, at 9600 baud
 
}
 void draw() {
 
 
 
 
 if (port.read()== '@') {
    println(" stop");
 
  }
  String onoroff[] = loadStrings("C:\\xampp\\htdocs\\dashboard\\LEDstate.txt"); // Insert the location of your .txt file
    // Prints whatever is in the file ("1" or "0")
 if(!(xyz.equals(onoroff[0]))){
   print(onoroff[0]);
  if (onoroff[0].equals("F") == true) {
    println(" Fast lane");
    port.write('F'); 
 
  }
  
  if (onoroff[0].equals("L") == true) {
    println(" Normal lane");
    port.write('L'); 
 
  }
  
  if (onoroff[0].equals("N") == true) {
    println(" North");
    port.write('N'); 
 
  }
  
  if (onoroff[0].equals("S") == true) {
    println(" South");
    port.write('S'); 
 
  }
  
  if (onoroff[0].equals("E") == true) {
    println(" east ");
    port.write('E'); 
 
  }
  
  if (onoroff[0].equals("W") == true) {
    println(" west");
    port.write('W'); 
 
  }
  
  if (onoroff[0].equals("P") == true) {
    println(" PEDESTRIAN");
    port.write('P'); 
 
  }
  if (onoroff[0].equals("M") == true) {
    println(" Emergency");
    port.write('M'); 
 
  }
  if (onoroff[0].equals("x") == true) {
    println(" xit");
    port.write('X'); 
 
  }
  xyz=onoroff[0];
 }
  delay(1000); // Set your desired interval here, in milliseconds
 }