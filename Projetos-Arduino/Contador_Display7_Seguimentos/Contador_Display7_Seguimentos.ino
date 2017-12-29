
int R = 10 ;
int G = 11 ;
int B = 9 ;

// a rotina de configuração é executada uma vez quando você pressiona reset:
void  setup () {
  // pinos do led
  pinMode (R, OUTPUT);
  pinMode (G, OUTPUT);
  pinMode (B, OUTPUT);
  Serial. começar ( 9600 );
  
  digitalWrite (R, LOW);
  digitalWrite (G, LOW);
  digitalWrite (B, LOW);
}

// a rotina do loop corre uma e outra vez para sempre:
 loop vazio () {
  
  digitalWrite (R, HIGH);
  digitalWrite (G, 0 );
  digitalWrite (B, 0 );
  Serial. println ( " Acende " );
  atraso ( 500 );
  digitalWrite (R, LOW);
  Serial. println ( " Apaga " );
  digitalWrite (G, HIGH);
  Serial. println ( " Acende " );
  atraso ( 500 );
  digitalWrite (G, LOW);
  digitalWrite (B, HIGH);
  Serial. println ( " Acende " );
  atraso ( 500 );
  digitalWrite (B, LOW);
}
