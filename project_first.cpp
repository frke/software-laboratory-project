#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

class Program{
    string name;
    int length;
    int waterTemperature;
    float energyConsuption;
  public:
    Program(string n, int l, int t, float e){
      name = n;
      length = l;
      waterTemperature = t;
      energyConsuption = e;
    }
    void displayParameters(){
      cout << "Name: " << name <<endl;
      cout << "length: " << length <<endl;
      cout << "Water Temperature: " << waterTemperature <<endl;
      cout << "Energy Consuption: " << energyConsuption <<endl;
    }
  };

class WordTxt{
        string txt = ".txt";
        string word;
    public:
      WordTxt(string w){
        word=w+txt;
      }

      void displayNameTxt(){
        cout << word << endl;
      }

      string wordy(){
        string result;
        string path = "C:/Users/mateu/Desktop/PROJEKTY/C++/ProgramsDishwasher/";
        result = path + word;
        return result;
      }
  };

void choosingCycleDescription(){
    cout << "Choose a program for your dishwasher\n";
    cout << "Available options: \n";
    cout << "*1.basic\n*2.fast\n*3.intensive\n*4.economical\n";
}

string choosingCycleOption(){
  int a;
  string name;
  cin >> a;
  if(a>4){
    cout << "Program with that number does not exist. Choose other one \n";
    cin >> a;
  };

  if(a == 1){
    name = "basic";
  }else if(a == 2){
    name = "fast";
  }else if(a == 3){
    name = "intensive";
  }else{
    name = "economical";
  };

  return name;
}

void Timer(int timeOfCycle){
  int i=0;
  int downCounter;
  bool flagLoop = true;
  bool flagLoop2 = true;
  int hours;
  int yesOption;
  cin >> yesOption;
  if(yesOption==1){
    do{
      system( "cls" );
      downCounter=timeOfCycle-i;
      hours=downCounter/60;
      cout <<hours<<":"<< downCounter%60 <<" ";
      Sleep(1000);

        if(GetAsyncKeyState(VK_LSHIFT)) {
        flagLoop = false;
        };

        if(GetAsyncKeyState(VK_SPACE)){
        flagLoop2 = false;
          do{
            if(GetAsyncKeyState(VK_SPACE)){
              flagLoop2 = true;
            }
            Sleep(1);
          }while(flagLoop2==false);
        };


    i++;
  }while(flagLoop==true || downCounter==0);
      cout << "The program has been finished\n";
    };
}



int main(){

  string inscr1; string inint2; string inint3; string inint4; string name; string fileToOpenPath;
  int timeOfCycle;

choosingCycleDescription();
name = choosingCycleOption();
WordTxt nameTxt(name);
nameTxt.displayNameTxt();
fileToOpenPath = nameTxt.wordy();

  cout << "Porgram has the following parameters: \n";
  fstream file;
  file.open(fileToOpenPath,ios::in);
    file.seekg( +5, std::ios_base::beg);
    getline(file,inscr1);
    cout << "*name: " << inscr1 <<"\n";
    file.seekg( +5, std::ios_base::cur);
    getline(file,inint2);
    cout << "*length: " << inint2 <<"\n";
    file.seekg( +16, std::ios_base::cur);
    getline(file,inint3);
    cout << "*water temperature: " << inint3 <<"\n";
    file.seekg( +17, std::ios_base::cur);
    getline(file,inint4);
    cout << "*energy consuption: " << inint4 <<"\n\n";
  file.close();
  cout <<"To start program press 1, to finish the program press 'LEFT_SHIFT', to stop the program pess 'SPACE'\n\n";
  timeOfCycle = stoi(inint2);
  Timer(timeOfCycle);
  return 0;
}
