//23.01.04 - Sein Kim
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
      int stim_pos = Data.indexOf(",");
      int ref_pos = Data.indexOf(",", stim_pos+1);
      int repeat_pos = Data.indexOf(">",ref_pos);

      String stim = Data.substring(1,stim_pos);
      String ref = Data.substring(stim_pos+1,ref_pos);
      String repeat = Data.substring(ref_pos+1,repeat_pos);

      int stim_time = stim.toInt();   
      int ref_time = ref.toInt();
      int repeat_time = repeat.toInt();

      for(repeat_time;repeat_time>0;repeat_time--)
      {
        digitalWrite(4,HIGH);
        //Serial.println(stim_time);
        delay(stim_time);
        digitalWrite(4,LOW);
        //Serial.println(ref_time);
        delay(ref_time);
      }
      //Serial.println("END");
    }
    else
    {
      digitalWrite(4,LOW);
      //Serial.print(F("Wrong"));
    }
  }

}
