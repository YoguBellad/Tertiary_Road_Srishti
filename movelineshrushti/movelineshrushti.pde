int[] data;
float x=250, y=300, x2=100, y2=100;
int c=0;
void setup() {
  size(500, 500);
  // Load text file as a string
}

void draw() {

  while (c==0) {
    String[] stuff = loadStrings("C:\\Users\\dell\\Documents\\qwerty7.txt");
    // Convert string into an array of integers using ',' as a delimiter
    data = int(split(stuff[0],','));
    background(255);
    stroke(153);
    for (int i = 0; i < data.length; i++) {
      println(data[i]);


      if (data[i]!=500) {
        x2=x+(cos(data[i]*0.01745)*10);
        y2=y-(sin(data[i]*0.01745)*10);
        line(x, y, x2, y2);
        x=x2;
        y=y2;
      } else
      {
        c=1;
      }
      delay(1);
    }
  }
}