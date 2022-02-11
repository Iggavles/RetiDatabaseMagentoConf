#include <iostream>
#include <string>

using namespace std;

class Azione {
  private:
    string nome;    
  public:    
    Azione(string n) { nome=n; }
    virtual string dettagli() = 0;  
    void debug() {
        cout << "dettagli(" << nome << "): " << dettagli() << "\n";
    }
};

class Tweet : public Azione {
  private:
    string messaggio;    
  public:
    using Azione::Azione;
    void setMessage(string m) { 
        messaggio=m; 
    }
    string dettagli() { 
        string risultato = messaggio;
        return risultato; }  
};

class Email : public Azione {
  private:
    string messaggio;
    string destinatario;
  public:
    using Azione::Azione;
    void setMessage(string m, string d) { 
        messaggio=m; 
        destinatario=d; 
    }
    string dettagli() { 
        string risultato = messaggio + "(" + destinatario + ")";
        return risultato; }  
};

int main() {
   Tweet t = Tweet(string("a tweet")); 
   t.setMessage("Mi dispiace se oggi è stata molto pesante la lezione!"); 
   Email e = Email(string("an email"));
   e.setMessage("vedi tweet che ti ho inviato", "andrea.ribuoli@yahoo.com");
   t.debug();
   e.debug(); 
}
