// L298N
// Motor พูเลย์
int in1 = 11 ;
int in2 = 10 ;
int enA = 9 ;
// Motor คนน้ำยาง
int in3 = 7 ;
int in4 = 6 ;
int enB = 5 ;

// Solinoid
int valve = 2 ;

//เวลาหยอดน้ำกรด
int acid_time=10000 ;


void setup() 
{
  pinMode(in1,OUTPUT) ;
  pinMode(in2,OUTPUT) ;
  pinMode(in3,OUTPUT) ;
  pinMode(in4,OUTPUT) ;
  pinMode(enA,OUTPUT) ;
  pinMode(enB,OUTPUT) ;  
}

void Pstop()
{
  digitalWrite(in1,LOW) ;
  digitalWrite(in2,LOW) ;
  
  
}

void loop()
{
  Pforward(5000) ; // วิ่งสุด
  Stir_acid(60000) ; //คน 60 วินาที
  Prevarse(5500) ; // กลับสุด
}

void Pforward(int T)
{
  digitalWrite(in1,LOW) ;
  digitalWrite(in2,HIGH) ;
  delay(T);
}

void Prevarse(int T)
{
  digitalWrite(in1,HIGH) ;
  digitalWrite(in2,LOW) ;
  delay(T);
}

void Stir_acid(int T) 
{
  digitalWrite(valve,HIGH);//เปิดวาร์ล
  delay(acid_time); //เวลาหยอดน้ำกรด
  digitalWrite(valve,LOW);//ปิดวาร์ล
  digitalWrite(in3,HIGH) ;
  digitalWrite(in4,LOW) ;
  delay(T); // ใช้เวลาคน 60 วินาที
  

}

