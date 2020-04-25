import processing.opengl.*;
import processing.serial.*;

//Sets variables for serial port, bytes, and floats
Serial sp;
byte[] buff;
float[] r;

float OFFSET_X = 2.5, OFFSET_Y = -2.5; //These offsets are chip specific, and vary. Play with them to get the best ones for you

//This sets up the Processing 3 Java window dimension and visuals
void setup() {
size(400, 300, P3D);
sp = new Serial(this, "/dev/cu.wchusbserial1410", 9600); //You have to rename your port in the "" and change the baud rate.
buff = new byte[128];
r = new float[3];
}

float protz, protx;
void draw() {
//perspective( 45, 4.0/3.0, 1, 5000 );
translate(400/2, 300/2, -400); //Sets left/right, up/down, and toward/away translation
background(0); //Sets background color to black
buildShape(protz, protx); //Used to define a new shape

int bytes = sp.readBytesUntil((byte)10, buff); //It will only read until 10 bytes of data
String mystr = (new String(buff, 0, bytes)).trim(); //trim removes whitespace at start of string
if(mystr.split(" ").length != 3) { //uses string to break characters by using a delimiter ""
println(mystr);
return;
}
setVals(r, mystr);

float z = r[0], x = r[1];
if(abs(protz - r[0]) < 0.05)
z = protz;
if(abs(protx - r[1]) < 0.05)
x = protx;
background(0);
buildShape(z, x);

protz = z;
protx = x;
println(r[0] + ", " + r[1] + ", " + r[2]); //prints x, y, z values in the console
}

//This sets up the 3D object inside the window
void buildShape(float rotz, float rotx) {
pushMatrix();
scale(6,6,14);
rotateZ(rotz);
rotateX(rotx);
fill(255);
stroke(0);
box(60, 10, 10);
fill(0, 255, 0);
box(10, 9, 40);
translate(0, -10, 20);
fill(255, 0, 0);
box(5, 12, 10);
popMatrix();
}
//Sets the values in an array
void setVals(float[] r, String s) {
int i = 0;
r[0] = -(float)(Integer.parseInt(s.substring(0, i = s.indexOf(" "))) +OFFSET_X)*HALF_PI/256;
r[1] = -(float)(Integer.parseInt(s.substring(i+1, i = s.indexOf(" ", i+1))) + OFFSET_Y)*HALF_PI/256;
r[2] = (float) Integer.parseInt(s.substring(i+1));

}