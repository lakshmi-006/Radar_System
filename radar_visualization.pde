import processing.serial.*; 
Serial myPort; 
int[] angles = new int[360]; 
int[] distances = new int[360]; 

void setup() { 
  size(800, 400); 
  String portName = "com4"; // Change index if needed 
  myPort = new Serial(this, portName, 9600); 
  myPort.bufferUntil('\n');//Wait for newlines to read data 
} 
void draw() { 
  background(255); 
  for (int i = 0; i < 360; i++) { 
    float x = map(i, 0, 360, 0, width); 
    float y = map(distances[i], 0, 200, height, 0); // Adjust max distance if needed 
    if (distances[i] < 50){ 
      stroke(255, 0, 0);// Red color if object detected 
      fill(255, 0, 0); 
      textAlign(CENTER); 
      textSize(12); 
      text(distances[i] + "cm", x, y - 10);// Display distance above the line 
    } else{ 
      stroke(0, 255, 0);//Green color if no object detected 
    } 
    line(x, height, x, y); 
  } 
} 

void serialEvent(Serial myPort) { 
  String data = myPort.readStringUntil('\n'); 
  if (data != null) { 
    data = data.trim(); 
    String[] parts = split(data,','); 
    if (parts.length == 2){ 
      int angle = int(parts[0]); 
      int distance = int(parts[1]); 
      angles[angle] = angle; 
      distances[angle] = distance; 
    } 
  } 
}
