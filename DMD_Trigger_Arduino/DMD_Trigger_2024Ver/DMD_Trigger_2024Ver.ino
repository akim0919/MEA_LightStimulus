//24.01.03 - Sein Kim
//To put trigger(sync) data into Intan

String Data = "";
int stim_pos,ref_pos,repeat_pos;
String stim, ref, repeat;
int stim_time,ref_time, repeat_time;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(100);
  pinMode(4,OUTPUT); //Arduino PIN 4 -> Intan Digital Input

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    Data = Serial.readString();    //Read stimulus parameter data<string> from DMD_GUI

    if(Data.charAt(0) == '<' and Data.charAt(Data.length()-1) == '>')
    {
      digitalWrite(4,HIGH);
      //Serial.println(stim_time);
      delayMicroseconds(50);
      digitalWrite(4,LOW);
      //Serial.println(ref_time);
      delayMicroseconds(0);
      //Serial.println("END");
    }
    
    else
    {
      digitalWrite(4,LOW);
      //Serial.print(F("Wrong"));
    }
  }

}
