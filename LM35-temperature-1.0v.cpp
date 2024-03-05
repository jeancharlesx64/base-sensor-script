int pinoSensor = 5; // Saída do sensor na AB.
int valorLido = 0; //Variável auxiliar.
float temperatura = 0; //Variável que armazenará a temperatura lida
int linha = 0; //variavel que se refere as linhas do excel

void setup() {//Função que será executada uma
    Serial.begin(9600); //Inicia a comunicação serial a 9600 bauds.
}

void loop() {//Função que será executada continuamente.
    valorLido = analogRead(pinoSensor);//Leitura analógica da porta A
    temperatura = valorLido * 0.00488;// 5 volts/ 1023 = 0,0048 precisão do A/D
    temperatura = temperatura * 100;// converte milivolts para celsius cada 10mV == 1 grau C
    linha++;//incrementa linha para que a leitura pule linha

    //inicia a impressão dos dados, fica sempre iniciando
    Serial.print(temperatura);
  Serial.print("\n");

    // loop para limitar a que de dados
    if(linha > 100){
        linha = 0;
    }
    delay (1000); //Tempo 5 seg para realizar outra leitura.
}
