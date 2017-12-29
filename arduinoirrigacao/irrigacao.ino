/ *
   Remota de Irrigação
 
   O projeto consiste em disponibilizar via web opcoes para fechar e abrir torneiras especificas
   alem de programar para ligar e desligar dependendo da humidade detectada pelo os sensores de humidade
 
   @autor Eduardo da Penha Figueredo Junior
   @since 08/06/2014
   
 * /

# include  < SPI.h >
# include  < Ethernet.h >
# include  < SD.h >

Arquivo arquivo;
// String arquivoString = "";

//   MAC addres e ip do controlador
byte mac [] = { 
  0xDE , 0xAD , 0xBE , 0xEF , 0xFE , 0xED };
IPAddress ip ( 192 , 168 , 1 , 177 );

//   Iniciando biblioteca Servidor Ethernet
Servidor EthernetServer ( 80 );

void  setup () {
  //   Abrindo conexão série e espera abertura da porta:
  Serial. começar ( 9600 );
  enquanto (! Serial) {
    ;
  }
  
  //   iniciando conexao Ethernet e servidor:
  Ethernet. começar (mac, ip);
  servidor. begin ();
  Serial. imprimir ( " servidor esta rodando em " );
  Serial. println (Ethernet. localIP ());
}

/ * void carregaArquivo (String arquivo) {
  se (SD.exists (arquivo)) {
  } outro {
    // arquivo requisitado nao existe .. carregar arquivo 404.html exibindo que arquivo nao existe e enviando um cabecaclho com 404
  }
} * /

 loop vazio () {
  // ouvir os clientes recebidos
  Cliente EthernetClient = servidor. disponível ();
  se (cliente) {
    Serial. println ( " novo cliente " );
    // um pedido http termina com uma linha em branco
    boolean currentLineIsBlank = true ;
    enquanto (cliente. conectado ()) {
      se (cliente disponível ()) {
        char c = cliente. ler ();
        Serial. escreva (c);
        // se você chegou ao fim da linha (recebeu uma nova linha
        // caractere) e a linha está em branco, o pedido http terminou,
        // para que você possa enviar uma resposta
        se (c == ' \ n ' && currentLineIsBlank) {
          //   Pegar o nome do arquivo e enviar para um funcao carregaArquivo
          // client.print (carregaArquivo (c.algumacoisa));
          // envia um cabeçalho de resposta HTTP padrão
          cliente. println ( " HTTP / 1.1 200 OK " );
          cliente. println ( " Content-Type: text / html " );
          cliente. println ( " Conexão: fechar " );  // a conexão será fechada após a conclusão da resposta
	  // client.println ("Refresh: 5"); // atualize a página automaticamente a cada 5 segundos
          cliente. println ();
          cliente. println ( " <! DOCTYPE HTML> " );
          cliente. println ( " <html> " );
          cliente. println ( " EXIBINDO DADOS: D " );
          cliente. println ( " </ html> " );
          quebrar ;
        }
        se (c == ' \ n ' ) {
          // você está iniciando uma nova linha
          currentLineIsBlank = true ;
        } 
        senão  se (c! = ' \ r ' ) {
          // você obteve um personagem na linha atual
          currentLineIsBlank = false ;
        }
      }
    }
    // dando ao navegador tempo para receber os dados
    atraso ( 1 );
    // fechando a conexao:
    cliente. parar ();
    Serial. println ( " cliente desconectado " );
  }
}
