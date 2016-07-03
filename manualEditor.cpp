#include "manualEditor.h"

ManualEditor::ManualEditor(ProgramData* param) {
  programData = param;
  one = new unsigned char[programData->uvDimension*programData->uvDimension];
  two = new unsigned char[programData->uvDimension*programData->uvDimension];
  running = false;
  editingOne = false;
  printingByte = true;
}

ManualEditor::~ManualEditor() {
  delete[] one;
  delete[] two;
}

void ManualEditor::runEditor() {
  running = true;
  while(running) {
    string input = getInput();
    if(input == "print" || input == "p") printData();
    else if(input == "mutate" || input == "m") mutate();
    else if(input == "crossover" || input == "c") crossover();
    else if(input == "switch" || input == "s") switchFocus();
    else if(input == "bit") printingByte = false;
    else if(input == "byte") printingByte = true;
    else if(input == "help") help();
    else if(input == "quit" || input == "q") running = false;
    else cout << "Unrecognized Command" << endl;
  }
}

void ManualEditor::printData() {
  int dim = programData->uvDimension;
  if(printingByte) {
    // printing data as bytes
    for(int i=0;i<dim;i++) {
      for(int j=0;j<dim;j++) {
        cout << one[i*dim+j] << " ";
      }
      cout << "           ";
      for(int j=0;j<dim;j++) {
        cout << two[i*dim+j] << " ";
      }
      cout << endl;
    }
  } else {
    // printing data as bits
    for(int i=0;i<dim;i++) {
      for(int j=0;j<dim;j++) {
        for(int k =0;k<8;k++) {
          cout << (one[i*dim+j] >> k) & 0x1 << " "; 
        }
      }
      cout << "           ";
      for(int j=0;j<dim;j++) {
        for(int k=0;k<8;k++) {
          cout << (one[i*dim+j] >> k) & 0x1 << " ";
        }
      }
      cout << endl;
    }
  }
}

void ManualEditor::mutate() {
  unsigned char* chosen = editingOne ? one : two;
  cout << "What Index Should Be Mutated" << endl;
  int ind = getIntInput();
  cout << "What Bit Should Be Fliped" << endl;
  char tmp = !((chosen[index] >>index8) & 0x1);
  if(!tmp) chosen[index] = (chosen[index] & (0xFF & ~(0x1 << index8)));
  else chosen[index] = (chosen[index] | (0x00 | (0x1 << index8)));
}

void ManualEditor::crossover() {
  unsigned char* chosen = editingOne ? one : two;
  unsigned char* notChosen = editingOne ? two : one;
  int dim = programData->uvDimension;
  cout << "What Start X Index" << endl;
  int startX << cin;
  cout << "What Start Y Index" << endl;
  int startY << cin;
  cout << "What Length" << endl;
  int len << cin;
  for(int i=startY;i<len+startY;i++)
    for(int j=startX;j<len+startX;j++)
      chosen[i*len+j] = nonChosen[i*len+j];
}

void ManualEditor::help() {
  cout << "print | p     ::     - reprints the individuals" << endl;
  cout << "mutate | m    ::     - mutates the focused individual" << endl;
  cout << "crossover | c ::     - crossovers the individuals" << endl;
  cout << "switch | s    ::     - switches focus to the other individual" << endl;
  cout << "bit           ::     - print information in bits" << endl;
  cout << "byte          ::     - print information in bytes" << endl;
  cout << "quit | q      ::     - quit the editor" << endl;
}

string ManualEditor::getiStringInput() {
  string temp;
  temp << cin;
  return temp;
}

int ManualEditor::getIntInput() {
  int temp;
  temp << cin;
  return temp;
}

float ManualEditor::getFloatInput() {
  float temp;
  temp << cin;
  return temp;
}
